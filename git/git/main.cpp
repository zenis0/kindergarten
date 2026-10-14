#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>

// Я не правильно загрузил репозиторий в гит ( на паре ) и потерял чуть чуть кода ( просто визуально было приятнее )

int main()
{
	setlocale(LC_ALL, "ru");

	std::cout << "\t\t\t\t\t\t---------------\n";
	std::cout << "\t\t\t\t\t\tМагаз Александра\n";
	std::cout << "\t\t\t\t\t\t---------------\n";

	std::string fruits[4]{ "Яблочный","Апельсиновый","Абрикосовый","Грушевый" };
	std::string ovosh[3]{ "Томатный","Луковый","Огуречный" };
	std::string tea[2]{ "Чесночный","Петрушевый" };

	// цены за литр 
	const int priceFruit[4] = { 90, 100, 120, 95 };
	const int priceOvosh[3] = { 80, 70, 75 };
	const int priceTea[2] = { 110, 105 };
	const int priceBoyar = 150;
	const double limitSum = 1000; // сделал больше, теперь как надо

	// количество литров по каждому напитку
	int fruitQty[4] = { 0, 0, 0, 0 };
	int ovoshQty[3] = { 0, 0, 0 };
	int teaQty[2] = { 0, 0 };
	int boyar = 0;
	bool boyarBlocked = false;

	int category = 0;

	while (true)
	{
		std::cout << "\nВыберите категорию напитков\n";
		std::cout << "1.Фруктовые\n";
		std::cout << "2.Овощные\n";
		std::cout << "3.Чаи\n";
		std::cout << "4.Настойки\n";
		std::cout << "0.Выход из магазина\n";
		std::cout << "Ввод: ";
		std::cin >> category;

		if (category > 4 || category < 0)
		{
			std::cout << "Вы вышли из диапазона\n";
			continue;
		}

		if (category == 0)
		{
			break;
		}

		int product = 0;
		int kolvo = 0;

		if (category == 1)
		{
			std::cout << "Выберите напиток из этой категории\n";
			for (int i = 0; i < 4; i++)
			{
				std::cout << i + 1 << "." << fruits[i] << "(" << priceFruit[i] << " руб)\n";
			}
			std::cout << "Ввод: ";
			std::cin >> product;

			if (product < 1 || product > 4)
			{
				std::cout << "Вы вышли из диапазона\n";
				continue;
			}

			std::cout << "Введите количество(в литровых банках): ";
			std::cin >> kolvo;
			if (kolvo <= 0)
			{
				continue;
			}
			fruitQty[product - 1] += kolvo;

			// фруктовый сок блокирует боярышник и аннулирует уже купленный
			if (boyar > 0)
			{
				boyar = 0;
				std::cout << "Купленный боярышник аннулирован\n";
			}
			boyarBlocked = true;
		}
		else if (category == 2)
		{
			std::cout << "Выберите напиток из этой категории\n";
			for (int i = 0; i < 3; i++)
			{
				std::cout << i + 1 << "." << ovosh[i] << "(" << priceOvosh[i] << " руб)\n";
			}
			std::cout << "Ввод: ";
			std::cin >> product;

			if (product < 1 || product > 3)
			{
				std::cout << "Вы вышли из диапазона\n";
				continue;
			}

			std::cout << "Введите количество(в литровых банках): ";
			std::cin >> kolvo;
			if (kolvo <= 0)
			{
				continue;
			}
			ovoshQty[product - 1] += kolvo;
		}
		else if (category == 3)
		{
			std::cout << "Выберите напиток из этой категории\n";
			for (int i = 0; i < 2; i++)
			{
				std::cout << i + 1 << "." << tea[i] << "(" << priceTea[i] << " руб)\n";
			}
			std::cout << "Ввод: ";
			std::cin >> product;

			if (product < 1 || product > 2)
			{
				std::cout << "Вы вышли из диапазона\n";
				continue;
			}

			std::cout << "Введите количество(в литровых банках): ";
			std::cin >> kolvo;
			if (kolvo <= 0)
			{
				continue;
			}
			teaQty[product - 1] += kolvo;
		}
		else if (category == 4)
		{
			if (boyarBlocked)
			{
				std::cout << "Покупка боярышника заблокирована\n";
				continue;
			}

			std::cout << "Боярышник(" << priceBoyar << " руб)\n";
			std::cout << "Введите количество(в литровых банках): ";
			std::cin >> kolvo;
			if (kolvo <= 0)
			{
				continue;
			}
			boyar += kolvo;
		}
	}

	// подсчет чека
	std::cout << "\nЗавершение работы...\n";
	Sleep(2000);
	std::system("cls");
	std::cout << "-------- Чек --------\n";

	double sum = 0;

	for (int i = 0; i < 4; i++)
	{
		if (fruitQty[i] > 0)
		{
			std::cout << fruits[i] << ": " << fruitQty[i] << " л\n";
			sum += fruitQty[i] * priceFruit[i];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (ovoshQty[i] > 0)
		{
			std::cout << ovosh[i] << ": " << ovoshQty[i] << " л\n";
			// каждый четвертый литр лукового сока в подарок
			int paid = ovoshQty[i];
			if (i == 1)
			{
				int gift = ovoshQty[i] / 4;
				paid -= gift;
				if (gift > 0)
				{
					std::cout << "  подарок: " << gift << " л\n";
				}
			}
			sum += paid * priceOvosh[i];
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (teaQty[i] > 0)
		{
			std::cout << tea[i] << ": " << teaQty[i] << " л\n";
			sum += teaQty[i] * priceTea[i];
		}
	}

	if (boyar > 0)
	{
		std::cout << "Боярышник: " << boyar << " л\n";
		sum += boyar * priceBoyar;
	}

	// скидка 5% на петрушевый чай от 3 л
	double discount1 = 0;
	if (teaQty[1] >= 3)
	{
		discount1 = teaQty[1] * priceTea[1] * 0.05;
		sum -= discount1;
	}

	// скидка 13% на весь чек
	double discount2 = 0;
	if (sum > limitSum)
	{
		discount2 = sum * 0.13;
		sum -= discount2;
	}

	if (discount1 > 0)
	{
		std::cout << "Скидка 5% на петрушевый чай: " << discount1 << " руб\n";
	}
	if (discount2 > 0)
	{
		std::cout << "Скидка 13% на весь чек: " << discount2 << " руб\n";
	}
	std::cout << "Итого: " << sum << " руб\n";

	return 0;
}
