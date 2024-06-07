#include <iostream>
#include <wt/dbo/dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <string>
#include <Windows.h>
#include <set>
#pragma execution_character_set ("UTF-8")


using namespace std;
class Book;
class Stock;
class Sale;
class Publisher
{
public:
	string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;

	template <class Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
	}
};
class Book
{
public:
	string title;
	Wt::Dbo::ptr<Publisher> publisher;
	Wt::Dbo::collection <Wt::Dbo::ptr<Stock>> stocks;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, title, "title");
		Wt::Dbo::belongsTo(a, publisher, "publisher");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
	};
};
class Shop
{
public:
	string name;
	Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

	template <typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, name, "name");
		Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");

	};
};
class Stock
{
public:
	int count;
	Wt::Dbo::ptr<Shop> shops;
	Wt::Dbo::ptr<Book> books;
	Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sale;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, count, "count");
		Wt::Dbo::belongsTo(a, shops, "shop");
		Wt::Dbo::belongsTo(a, books, "book");
		Wt::Dbo::hasMany(a, sale, Wt::Dbo::ManyToOne, "stock");
	};
};
class Sale
{
public:
	int price;
	string data_sale;
	int count;
	Wt::Dbo::ptr<Stock> stock;

	template<typename Action>
	void persist(Action& a)
	{
		Wt::Dbo::field(a, price, "price");
		Wt::Dbo::field(a, data_sale, "data sale");
		Wt::Dbo::belongsTo(a, stock, "stock");
	};
};


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try
	{
		string connStr{
			"host= localhost"
			" port= 5432"
			" dbname= lesson_DB_5"
			" user= Study_DB"
			" password= mellon" };


		Wt::Dbo::Session session;
		session.setConnection(move(make_unique<Wt::Dbo::backend::Postgres>(connStr)));

		session.mapClass<Publisher>("publisher");
		session.mapClass<Book>("book");
		session.mapClass<Shop>("shop");
		session.mapClass<Stock>("stock");
		session.mapClass<Sale>("sale");

		session.createTables();

		Wt::Dbo::Transaction t{ session };

		auto publisher1 = unique_ptr <Publisher>(new Publisher{ "Eksmo" });
		auto publisher2 = unique_ptr <Publisher>(new Publisher{ "Lenizdat" });

		Wt::Dbo::ptr<Publisher> dbPubl1 = session.add<Publisher>(move(publisher1));
		Wt::Dbo::ptr<Publisher> dbPubl2 = session.add<Publisher>(move(publisher2));
		Wt::Dbo::ptr<Publisher> dbPubl3 = session.add<Publisher>(move(unique_ptr <Publisher>(new Publisher{ "Samizdat" })));

		auto book1 = unique_ptr <Book>(new Book{ "Остров мертвых", dbPubl1 });
		auto book2 = unique_ptr <Book>(new Book{ "Девять принцев Амбера", dbPubl1 });
		auto book3 = unique_ptr <Book>(new Book{ "Ружья Авалона", dbPubl1 });
		auto book4 = unique_ptr <Book>(new Book{ "Бемби", dbPubl2 });
		auto book5 = unique_ptr <Book>(new Book{ "Князь Серебряный", dbPubl2 });
		auto book6 = unique_ptr <Book>(new Book{ "Вид с холма", dbPubl2 });
		auto book7 = unique_ptr <Book>(new Book{ "ТРИНИТРОТОЛУОЛ", dbPubl3 });
		auto book8 = unique_ptr <Book>(new Book{ "Он", dbPubl3 });
		auto book9 = unique_ptr <Book>(new Book{ "Орбис", dbPubl3 });

		Wt::Dbo::ptr<Book> dbbook1 = session.add<Book>(move(book1));
		Wt::Dbo::ptr<Book> dbbook2 = session.add<Book>(move(book2));
		Wt::Dbo::ptr<Book> dbbook3 = session.add<Book>(move(book3));
		Wt::Dbo::ptr<Book> dbbook4 = session.add<Book>(move(book4));
		Wt::Dbo::ptr<Book> dbbook5 = session.add<Book>(move(book5));
		Wt::Dbo::ptr<Book> dbbook6 = session.add<Book>(move(book6));
		Wt::Dbo::ptr<Book> dbbook7 = session.add<Book>(move(book7));
		Wt::Dbo::ptr<Book> dbbook8 = session.add<Book>(move(book8));
		Wt::Dbo::ptr<Book> dbbook9 = session.add<Book>(move(book9));

		auto shop1 = unique_ptr <Shop>(new Shop{ "Читай-город" });
		auto shop2 = unique_ptr <Shop>(new Shop{ "Лабиринт" });
		auto shop3 = unique_ptr <Shop>(new Shop{ "Литрес" });

		Wt::Dbo::ptr<Shop> dbshop1 = session.add<Shop>(move(shop1));
		Wt::Dbo::ptr<Shop> dbshop2 = session.add<Shop>(move(shop2));
		Wt::Dbo::ptr<Shop> dbshop3 = session.add<Shop>(move(shop3));

		auto stock1 = unique_ptr <Stock>(new Stock{ 200, dbshop1, dbbook1 });
		auto stock2 = unique_ptr <Stock>(new Stock{ 100, dbshop1, dbbook4 });
		auto stock3 = unique_ptr <Stock>(new Stock{ 70, dbshop1, dbbook7 });
		auto stock4 = unique_ptr <Stock>(new Stock{ 150, dbshop2, dbbook5 });
		auto stock5 = unique_ptr <Stock>(new Stock{ 10, dbshop2, dbbook4 });
		auto stock6 = unique_ptr <Stock>(new Stock{ 12, dbshop2, dbbook8 });
		auto stock7 = unique_ptr <Stock>(new Stock{ 17, dbshop3, dbbook2 });
		auto stock8 = unique_ptr <Stock>(new Stock{ 100, dbshop3, dbbook6 });
		auto stock9 = unique_ptr <Stock>(new Stock{ 50, dbshop3, dbbook9 });
		auto stock10 = unique_ptr <Stock>(new Stock{ 5, dbshop2, dbbook3 });

		Wt::Dbo::ptr<Stock> dbstock1 = session.add<Stock>(move(stock1));
		Wt::Dbo::ptr<Stock> dbstock2 = session.add<Stock>(move(stock2));
		Wt::Dbo::ptr<Stock> dbstock3 = session.add<Stock>(move(stock3));
		Wt::Dbo::ptr<Stock> dbstock4 = session.add<Stock>(move(stock4));
		Wt::Dbo::ptr<Stock> dbstock5 = session.add<Stock>(move(stock5));
		Wt::Dbo::ptr<Stock> dbstock6 = session.add<Stock>(move(stock6));
		Wt::Dbo::ptr<Stock> dbstock7 = session.add<Stock>(move(stock7));
		Wt::Dbo::ptr<Stock> dbstock8 = session.add<Stock>(move(stock8));
		Wt::Dbo::ptr<Stock> dbstock9 = session.add<Stock>(move(stock9));
		Wt::Dbo::ptr<Stock> dbstock10 = session.add<Stock>(move(stock10));

		auto sale1 = unique_ptr <Sale>(new Sale{ 299, "2024-06-07", 100,  dbstock1 });
		auto sale2 = unique_ptr <Sale>(new Sale{ 299, "2024-06-07", 100,  dbstock2 });
		auto sale3 = unique_ptr <Sale>(new Sale{ 299, "2024-04-05", 50,  dbstock3 });
		auto sale4 = unique_ptr <Sale>(new Sale{ 299, "2024-03-06", 120,  dbstock4 });
		auto sale5 = unique_ptr <Sale>(new Sale{ 299, "2024-05-16", 3,  dbstock5 });
		auto sale6 = unique_ptr <Sale>(new Sale{ 299, "2024-06-07", 55,  dbstock6 });
		auto sale7 = unique_ptr <Sale>(new Sale{ 299, "2024-05-07", 22,  dbstock7 });
		auto sale8 = unique_ptr <Sale>(new Sale{ 299, "2024-06-02", 13,  dbstock8 });
		auto sale9 = unique_ptr <Sale>(new Sale{ 299, "2024-02-14", 10,  dbstock9 });
		auto sale10 = unique_ptr <Sale>(new Sale{ 299, "2024-02-23", 5,  dbstock10 });

		Wt::Dbo::ptr<Sale> dbsale1 = session.add<Sale>(move(sale1));
		Wt::Dbo::ptr<Sale> dbsale2 = session.add<Sale>(move(sale2));
		Wt::Dbo::ptr<Sale> dbsale3 = session.add<Sale>(move(sale3));
		Wt::Dbo::ptr<Sale> dbsale4 = session.add<Sale>(move(sale4));
		Wt::Dbo::ptr<Sale> dbsale5 = session.add<Sale>(move(sale5));
		Wt::Dbo::ptr<Sale> dbsale6 = session.add<Sale>(move(sale6));
		Wt::Dbo::ptr<Sale> dbsale7 = session.add<Sale>(move(sale7));
		Wt::Dbo::ptr<Sale> dbsale8 = session.add<Sale>(move(sale8));
		Wt::Dbo::ptr<Sale> dbsale9 = session.add<Sale>(move(sale9));
		Wt::Dbo::ptr<Sale> dbsale10 = session.add<Sale>(move(sale10));

		cout << "Hello World!\n";
		t.commit();

		Wt::Dbo::Transaction t2{ session };

		string in;
		cout << "Введите наименование или ID издателя: ";
		cin >> in;

		Wt::Dbo::ptr<Publisher> publishers;
		try
		{
			int id = stoi(in);
			publishers = session.find<Publisher>().where("id = ?").bind(id);

		}
		catch (const exception&)
		{
			publishers = session.find<Publisher>().where("name = ?").bind(in);
		}
		if (publishers)
		{

			cout << "Издатель найден, это: " << publishers->name << endl;
			set<string> shopNames;

			for (const auto& books : publishers->books)
			{
				for (const auto& stocks : books->stocks)
				{
					shopNames.insert(stocks->shops->name);
				}
			}
			cout << "Магазины, в которых продают книги этого издателя: " << endl;
			int count_shop{ 0 };
			for (const auto& outNames : shopNames)
			{

				cout << ++count_shop << '\t' << outNames << endl;
			}
		}
		else
		{
			cout << "Издатель не найден" << endl;
		}
		t2.commit();
	}
	catch (const exception& ex)
	{
		cerr << "Error! " << ex.what() << endl;
	}
}

