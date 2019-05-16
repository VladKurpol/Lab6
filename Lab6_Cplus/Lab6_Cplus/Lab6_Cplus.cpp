// Lab6_Cplus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Shop
{
	std::string Surname;
	std::string initials;

	int Date_1[2];
	int Date_2[2];

	int first_cost;
	int second_cost;

	short percent;
};

void Save_in_File(Shop *customer, ofstream &file, int number)
{
	for (size_t i = 0; i < number; i++)
	{
		file << "Фамилия: " << customer[i].Surname << "\t";
		file << "Инициалы: " << customer[i].initials << "\t";
		file << "День, месяц, год покупки в первые 6 месяцев: " << customer[i].Date_1[0] << " " << customer[i].Date_1[1] << " " << customer[i].Date_1[2] << "\t";
		file << "День, месяц, год покупки в следующие 6 месяцев: " << customer[i].Date_2[0] << " " << customer[i].Date_2[1] << " " << customer[i].Date_2[2] << "\t";
		file << "Стоимость первого товара: " << customer[i].first_cost << "\t";
		file << "Стоимость второго товара: " << customer[i].second_cost << "\t";
		file << "Процент: " << customer[i].percent << "%" << "\t";
		file << "===================================" << "\t";
	}
}

void Add_percent(Shop *customer, int number)
{
	for (size_t i = 0; i < number; i++)
	{
		if (customer[i].first_cost + customer[i].second_cost >= 10000)
		{
			customer[i].percent = customer[i].percent + 5;
		}
	}
}

void Output(Shop *customer, int number)
{
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "Фамилия: " << customer[i].Surname << "\n";
		std::cout << "Инициалы: " << customer[i].initials << "\n";
		std::cout << "День, месяц, год покупки в первые 6 месяцев: " << customer[i].Date_1[0] << " " << customer[i].Date_1[1] << " " << customer[i].Date_1[2] << "\n";
		std::cout << "День, месяц, год покупки в следующие 6 месяцев: " << customer[i].Date_2[0] << " " << customer[i].Date_2[1] << " " << customer[i].Date_2[2] << "\n";
		std::cout << "Стоимость первого товара: " << customer[i].first_cost << "\n";
		std::cout << "Стоимость второго товара: " << customer[i].second_cost << "\n";
		std::cout << "Процент: " << customer[i].percent << "%" << "\n";
		std::cout << "===================================" << "\n";
	}
}

void Input(Shop *customer, int number) // Функция ввода данных 
{
	for (size_t i = 0; i < number; i++)
	{
		std::cout << "Введите фамилию: ";
		std::cin >> customer[i].Surname;

		std::cout << "Введите инициалы: ";
		std::cin >> customer[i].initials;

		std::cout << "Введите дату покупки за первые шесть месяцев (day, month, year): " << "\n";
		std::cin >> customer[i].Date_1[0];
		std::cin >> customer[i].Date_1[1];
		std::cin >> customer[i].Date_1[2];

		std::cout << "Введите дату покупки за следующие шесть месяцев (day, month, year): " << "\n";
		std::cin >> customer[i].Date_2[0];
		std::cin >> customer[i].Date_2[1];
		std::cin >> customer[i].Date_2[2];

		std::cout << "Стоимость первого товара:" << "\n";
		std::cin >> customer[i].first_cost;

		std::cout << "Стоимость первого товара" << "\n";
		std::cin >> customer[i].second_cost;

		std::cout << "Начальный процент:" << "\n";
		std::cin >> customer[i].percent;
	}
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	ofstream file;
	file.open("database.txt", std::ios::binary);

	if (!file.is_open())
	{
		std::cout << "Ошибка открытия файла database!" << "\n";
	}
	else
	{
		std::cout << "Успешное открытие файла database" << "\n";
	}

	if (!file.is_open())
	{
		std::cout << "Ошибка открытия файла database" << "\n";
	}
	else
	{
		std::cout << "Успешное открытие файла database" << "\n";
	}

	std::cout << "Как много покупателей?" << "\n";
	int number = 0;
	std::cin >> number;

	Shop *customer = new Shop[number];

	std::cout << "Введите информацию про каждого покупателя:" << "\n";

	Input(customer, number);

	std::cout << "Вывод:" << "\n" << "\n";

	Output(customer, number);

	Add_percent(customer, number);

	std::cout << "Проверка на дополнительную скидку...." << "\n";

	Output(customer, number);

	pointer:
	std::cout << "Списки были обновлены. Добавить изменения в файл?" << "\n";

	int choice = 0;
	std::cout << "1. Да" << "\n";
	std::cout << "2. Нет. Закрыть программу." << "\n";

	std::cin >> choice;
	if (choice = 1)
	{
		Save_in_File(customer, file, number);
		std::cout << "Успешное сохранение." << "\n";
		file.close();
	}
	else if (choice = 2)
	{
		file.close();
		return 0;
	}
	else
	{
		std::cout << "Некорректный ввод. Попробуйте еще раз." << "\n";
		goto pointer;
	}
}