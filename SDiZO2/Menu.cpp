#include <iostream>
#include "Menu.h"
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"

void Menu::menu()
{
	int choice = 99;
	int source = 0;
	int destination = 0;

	IncidenceMatrix m;
	AdjacencyList a;

	while (choice != 0)
	{
		std::cout << "Wybierz co chcesz zrobic:" << std::endl;
		std::cout << "    1. Wypisz graf w reprezentacji macierzowej" << std::endl;
		std::cout << "    2. Wypisz graf w reprezentacji listowej" << std::endl;
		std::cout << "    3. Algorytm Prima dla macierzy" << std::endl;
		std::cout << "    4. Algorytm Prima dla listy" << std::endl;
		std::cout << "    5. Algorytm Dijkstry dla macierzy" << std::endl;
		std::cout << "    6. Algorytm Dijkstry dla listy" << std::endl;
		std::cout << "    7. Powrot" << std::endl;
		std::cout << "Wybor: ";
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 0) exit(EXIT_SUCCESS);

		switch (choice)
		{
		default:
			std::cout << "Bledny wybor!" << std::endl;
			break;

		case 0:
			break;

		case 1:
			m.ReadFromFile();
			m.printDirected();
			m.printUdirected();
			m.clearMatrix();
			break;

		case 2:
			a.readFromFile();
			a.printDirected();
			a.printUdirected();
			a.clearList();
			break;

		case 3:
			m.ReadFromFile();
			m.PrimAlgorithm(source);
			m.clearMatrix();
			break;

		case 4:
			a.readFromFile();
			a.PrimAlgorithm(source);
			a.clearList();
			break;

		case 5:
			m.ReadFromFile();
			m.DijksryAlgorithm(source, destination);
			m.clearMatrix();
			break;

		case 6:
			a.readFromFile();
			a.DijksryAlgorithm(source, destination);
			a.clearList();
			break;

		case 7:
			mainMenu();
			break;
		}
	}
}

void Menu::mainMenu()
{
	int choice = 99;

	float density = 0;

	IncidenceMatrix m;
	AdjacencyList a;

	std::cout << "SDiZO, Projekt 2, Michal Polak, 235046" << std::endl << std::endl;

	while (choice != 0)
	{
		std::cout << "Wybierz jak wygenerowac graf:" << std::endl;
		std::cout << "    1. Zaladuj dane z pliku" << std::endl;
		std::cout << "    2. Wygeneruj losowy graf" << std::endl;
		std::cout << "Wybor: ";
		std::cin >> choice;
		std::cout << std::endl;

		if (choice == 0) exit(EXIT_SUCCESS);

		switch (choice)
		{
		
			default:
				std::cout << "Bledny wybor!" << std::endl;
				break;

			case 0:
				break;
			
			case 1:
				m.ReadFromFile();
				a.readFromFile();
				menu();
				break;

			case 2:
				//m.GenerateRandom(density);
				a.GenerateRandom(density);
				menu();
				break;
		}
	}
}