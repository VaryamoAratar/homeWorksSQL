#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <string>
#pragma execution_character_set ("UTF-8")

class Study_DB
{
public:
	//Конструктор, создаем подключение
	Study_DB(std::string& host, std::string& port, std::string& dbname, std::string& user, std::string& password)
	{
		std::ostringstream in;
		in << "host = " << host
			<< " port = " << port
			<< " dbname = " << dbname
			<< " user = " << user
			<< " password = " << password;
		c = new pqxx::connection(in.str());
	};
	~Study_DB()
	{
		delete c;
	};
	// оператор =
	Study_DB& operator = (const Study_DB& copy) = delete;
	Study_DB& operator = (Study_DB&& copy) noexcept
	{
		if (this != &copy)
		{
			c = std::move(copy.c);
		}
		return *this;
	}
	//Конструктор копирования
	Study_DB(const Study_DB& copy) = delete;
	Study_DB(Study_DB&& copy) noexcept
	{
		c = std::move(copy.c);
	}

	//Метод создает таблицы
	void create_table(std::string table)
	{
		pqxx::transaction tx{ *c };
		tx.exec(table);
		tx.commit();
	};
	//Метод удаляет таблицу
	void drop_table(std::string table_name)
	{
		pqxx::transaction tx{ *c };

		tx.exec("DROP table " + tx.esc(table_name) + " CASCADE;");
		tx.commit();
	}
	//Добавить клиента
	void add_new_client(std::string first_name, std::string last_name, std::string email)
	{
		pqxx::transaction tx{ *c };

		tx.exec("insert into \"Client_information\".client_info "
			"(first_name, last_name, email) "
			"values('" + tx.esc(first_name) + "', '" + tx.esc(last_name) + "', '" + tx.esc(email) + "'); ");
		tx.commit();
	};
	//добавить номер телефона
	void add_phone_number(int client_id, long long Phone_number)
	{
		pqxx::transaction tx{ *c };

		tx.exec("insert into \"Client_information\".Phone_number "
			"(client_id, Phone_number) "
			"values('" + tx.esc(std::to_string(client_id)) + "', '" + tx.esc(std::to_string(Phone_number)) + "'); ");
		tx.commit();
	}
	//Найти клиента по имени фамилии и емейл
	int get_client_id(std::string first_name, std::string last_name, std::string email)
	{
		pqxx::transaction tx{ *c };

		auto out = std::stoi(tx.query_value<std::string>("SELECT client_id "
			"FROM \"Client_information\".client_info "
			"WHERE first_name = '" + tx.esc(first_name) + "' and last_name = '" + tx.esc(last_name) + "' and email = '" + tx.esc(email) + "';"));

		return out;

	}
	//Найти клиента по номеру телефона
	int get_client_id(long long phone_number)
	{
		pqxx::transaction tx{ *c };

		auto out = std::stoi(tx.query_value<std::string>("SELECT client_id "
			"FROM \"Client_information\".Phone_number "
			"WHERE Phone_number = '" + tx.esc(std::to_string(phone_number)) + "';"));

		return out;
	}
	//Удалить клиента
	void delete_client(std::string first_name, std::string last_name, std::string email)
	{
		pqxx::transaction tx{ *c };

		tx.exec("delete from \"Client_information\".client_info "
			"WHERE first_name ='" + tx.esc(first_name) + "' and last_name ='" + tx.esc(last_name) + "' and email ='" + tx.esc(email) + "';");
		tx.commit();

	}
	//Удалить номер телефона клиента
	void delete_phone_number(int client_id, long long phone_number)
	{
		pqxx::transaction tx{ *c };

		tx.exec("delete from \"Client_information\".Phone_number "
			"WHERE client_id = '" + tx.esc(std::to_string(client_id)) + "' and Phone_number = '" + tx.esc(std::to_string(phone_number)) + "'; ");
		tx.commit();
	}
	//Изменить данные клиента
	void update_client_info(std::string first_name, std::string last_name, std::string email,std::string new_first_name, std::string new_last_name, std::string new_email)
	{
		if (new_first_name.empty()) new_first_name = first_name;
		if (new_last_name.empty()) new_last_name = last_name;
		if (new_email.empty()) new_email = email;
		pqxx::transaction tx{ *c };

		tx.exec("update \"Client_information\".client_info "
			"set first_name = '" + tx.esc(new_first_name) + "', last_name = '" + tx.esc(new_last_name) + "', email = '" + tx.esc(new_email) + "' "
			"WHERE first_name ='" + tx.esc(first_name) + "' and last_name ='" + tx.esc(last_name) + "' and email = '" + tx.esc(email) + "';");
		tx.commit();
	}

private:
	pqxx::connection* c;
};


int main()
{
	//setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try
	{
		std::string host{ "localhost" };
		std::string port{ "5432" };
		std::string dbname{ "lesson_DB_4" };
		std::string user{ "Study_DB" };
		std::string password{ "mellon" };
		Study_DB study(host, port, dbname, user, password);

		std::string client_info
		{ "create table if not exists \"Client_information\".client_info("
			" client_id serial NOT null unique,"
			" first_name text NOT NULL,"
			" last_name text NOT NULL,"
			" email text not null,"
			" CONSTRAINT client_info_pk PRIMARY KEY(first_name, last_name, email));" };
		std::string phone_number
		{ "create table if not exists \"Client_information\".Phone_number("
			" client_id integer references \"Client_information\".client_info(client_id) ON DELETE CASCADE, "
			" Phone_number text primary KEY);" };

		study.create_table(client_info);
		study.create_table(phone_number);

		study.add_new_client("Сергей", "Овсянников", "andirgr@mail.ru");
		study.add_new_client("Дарья", "Фиалковская", "fiadv89@gmail.com");
		study.add_new_client("Дмитрий", "Вертунов", "diamwe@mail.ru");

		study.add_phone_number(study.get_client_id("Сергей", "Овсянников", "andirgr@mail.ru"), 89124553703);
		study.add_phone_number(study.get_client_id(89124553703), 89508187475);
		study.add_phone_number(study.get_client_id(89124553703), 13);

		study.add_phone_number(study.get_client_id("Дарья", "Фиалковская", "fiadv89@gmail.com"), 89127434774);

		study.update_client_info("Сергей", "Овсянников", "andirgr@mail.ru", "", "", "randirgr@mail.ru");

		study.delete_phone_number(study.get_client_id(89124553703), 13);
		study.delete_client("Дмитрий", "Вертунов", "diamwe@mail.ru");

		//study.drop_table("\"Client_information\".client_info");
		//study.drop_table("\"Client_information\".Phone_number");



	std::cout << "Hello" << std::endl;

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}