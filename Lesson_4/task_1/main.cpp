#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#pragma execution_character_set ("UTF-8")



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try
	{
	pqxx::connection c(
		"host=localhost "
		"port=5432 "
		"dbname=lesson_DB_4 "
		"user=Study_DB "
		"password=mellon");

	std::cout << "Hello" << std::endl;

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}