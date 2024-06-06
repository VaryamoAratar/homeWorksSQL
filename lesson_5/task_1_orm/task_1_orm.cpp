#include <iostream>
#include <wt/dbo/dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <string>
#include <Windows.h>
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
    string connStr {
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

    cout << "Hello World!\n";

	}
	catch (const exception& ex)
	{
		cerr << "Error! " << ex.what() << endl;
	}
}

