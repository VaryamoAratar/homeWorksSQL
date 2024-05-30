#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include <string>
#pragma execution_character_set ("UTF-8")

class Study_DB
{
public:
	Study_DB(std::string& host, std::string& port, std::string& dbname, std::string& user, std::string& password)
	{
		std::ostringstream in;
		in << "host = " << host
			<< " port = " << port
			<< " dbname = " << dbname
			<< " user = " << user
			<< " password = " << password;
		c = new pqxx::connection (in.str());
	};
	~Study_DB() 
	{
		delete c;
	};

private:
	pqxx::connection* c;
};


int main()
{
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

	std::cout << "Hello" << std::endl;

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}