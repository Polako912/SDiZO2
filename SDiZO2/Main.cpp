#include<iostream>
#include "Menu.h"
#include "IncidenceMatrix.h"
#include "AdjacencyList.h"
#include <ctime>
#include "../../../../../Downloads/TimeMeasure.h"

int main()
{
	Menu menu;
	menu.mainMenu();

	IncidenceMatrix m;
	AdjacencyList a;
	float density = 0;
	int source = 0;
	int destination = 0;

	//m.ReadFromFile();
	//m.GenerateRandom(density);
	//m.printUdirected();
	//m.PrimAlgorithm(source);
	//m.DijksryAlgorithm(source, destination);

	//a.readFromFile();
	//a.GenerateRandom(density);
	//a.print();
	//a.PrimAlgorithm();
	//a.DijksryAlgorithm(source, destination);

	//system("pause");

//	srand(time(NULL));
//	TimeMeasure time;
//
//	std::vector<double> czasy;
//
//	int vertices = 50;
//
//	for (int i = 0; i < 100; i++)
//	{
//		int vertex1 = rand() % vertices;
//		int vertex2 = rand() % vertices;
//		//a.clearList();
//		//a.GenerateRandom(25);
//		m.clearMatrix();
//		m.GenerateRandom(25);
//		time.startCounting();
//		//a.DijksryAlgorithm(vertex1, vertex2);
//		//m.PrimAlgorithm(vertex1);
//		m.DijksryAlgorithm(vertex1, vertex2);
//		double czas = time.getCounter();
//		czasy.push_back(czas);
//	}
//	TimeMeasure::saveToFile(czasy, "time25.txt");
//	czasy.clear();
//
//	for (int i = 0; i < 100; i++)
//	{
//		int vertex1 = rand() % vertices;
//		int vertex2 = rand() % vertices;
//		//a.clearList();
//		//a.GenerateRandom(50);
//		m.clearMatrix();
//		m.GenerateRandom(50);
//		time.startCounting();
//		//a.DijksryAlgorithm(vertex1, vertex2);
//		//m.PrimAlgorithm(vertex1);
//		m.DijksryAlgorithm(vertex1, vertex2);
//		double czas = time.getCounter();
//		czasy.push_back(czas);
//	}
//	TimeMeasure::saveToFile(czasy, "time50.txt");
//	czasy.clear();
//
//	for (int i = 0; i < 100; i++)
//	{
//		int vertex1 = rand() % vertices;
//		int vertex2 = rand() % vertices;
//		//a.clearList();
//		//a.GenerateRandom(75);
//		m.clearMatrix();
//		m.GenerateRandom(75);
//		time.startCounting();
//		//a.DijksryAlgorithm(vertex1, vertex2);
//		//m.PrimAlgorithm(vertex1);
//		m.DijksryAlgorithm(vertex1, vertex2);
//		double czas = time.getCounter();
//		czasy.push_back(czas);
//	}
//	TimeMeasure::saveToFile(czasy, "time75.txt");
//	czasy.clear();
//
//	for (int i = 0; i < 100; i++)
//	{
//		int vertex1 = rand() % vertices;
//		int vertex2 = rand() % vertices;
//		//a.clearList();
//		//a.GenerateRandom(99);
//		m.clearMatrix();
//		m.GenerateRandom(99);
//		time.startCounting();
//		//a.DijksryAlgorithm(vertex1, vertex2);
//		//m.PrimAlgorithm(vertex1);
//		m.DijksryAlgorithm(vertex1, vertex2);
//		double czas = time.getCounter();
//		czasy.push_back(czas);
//	}
//	TimeMeasure::saveToFile(czasy, "time99.txt");
//	czasy.clear();

	system("Pause");
	return 0;
}
