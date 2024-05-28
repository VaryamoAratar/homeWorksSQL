#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>

int main()
{
	SetConsoleCP("1251");
	SetConsoleOutputCP("1251");

	try
	{
	pqxx::connection c(
		"host=localhost "
		"port=5432 "
		"dbname=lesson_DB_4 "
		"user=Study_DB "
		"password=mellon1");

	std::cout << "Hello" << std::endl;

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}