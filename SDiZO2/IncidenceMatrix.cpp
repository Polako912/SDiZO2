#include "IncidenceMatrix.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <functional>

typedef std::pair<int, int> iPair;

IncidenceMatrix::IncidenceMatrix(): vertex(0), edge(0), weight(0)
{
	vertex = 0;
	edge = 0;
	weight = 0;
}

IncidenceMatrix::~IncidenceMatrix()
{
	clearMatrix();
}

void IncidenceMatrix::ReadFromFile()
{
	std::ifstream file;

	file.open("data.txt");
	if (file.good())
	{
			file >> edge >> vertex;

			directedMatrix.resize(vertex + 1);

			for (int i = 0; i < vertex + 1; i++)
			{
				directedMatrix[i].resize(edge);
			}

			for (int i = 0; i < vertex + 1; i++)
			{
				for (int j = 0; j < edge; j++)
				{
					directedMatrix[i][j] = 0;
				}
			}

			undirectedMatrix.resize(vertex + 1);

			for (int i = 0; i < vertex + 1; i++)
			{
				undirectedMatrix[i].resize(edge);
			}

			for (int i = 0; i < vertex + 1; i++)
			{
				for (int j = 0; j < edge; j++)
				{
					undirectedMatrix[i][j] = 0;
				}
			}

			int startVertex, endVertex, edgeWeight;

			for (int i = 0; i < edge; i++) 
			{
				file >> startVertex >> endVertex >> edgeWeight;
				directedMatrix[startVertex][i] = 1;
				directedMatrix[endVertex][i] = -1;
				directedMatrix[vertex][i] = edgeWeight;

				undirectedMatrix[startVertex][i] = 1;
				undirectedMatrix[endVertex][i] = 1;
				undirectedMatrix[vertex][i] = edgeWeight;
			}
		
	}
	
	file.close();
}

void IncidenceMatrix::GenerateRandom(float density)
{
	int startVertex = 0;
	int endVertex = 0;
	int edgeWeight = 0;
	srand(time(NULL));

	std::cout << "Podaj ilosc wierzcholow: " << std::endl;
	std::cin >> vertex;
	if (vertex < 0)
	{
		std::cout << "Liczba wierzcholkow musi byc wieksza od 0" << std::endl;
	}
	std::cout << "Podaj gestosc grafu :" << std::endl;
	std::cin >> density;
	if (density < 0)
	{
		std::cout << "Gestosc musi byc wieksza od 0" << std::endl;
	}

	edge = floor(density/100 *(vertex*(vertex - 1)));

	directedMatrix.resize(vertex + 1);

	for (int i = 0; i < vertex + 1; i++)
	{
		directedMatrix[i].resize(edge);
	}

	for (int i = 0; i < vertex + 1; i++)
	{
		for (int j = 0; j < edge; j++)
		{
			directedMatrix[i][j] = 0;
		}
	}

	undirectedMatrix.resize(vertex + 1);

	for (int i = 0; i < vertex + 1; i++)
	{
		undirectedMatrix[i].resize(edge);
	}

	for (int i = 0; i < vertex + 1; i++)
	{
		for (int j = 0; j < edge; j++)
		{
			undirectedMatrix[i][j] = 0;
		}
	}

	std::fstream file;
	file.open("data.txt", std::ios::out);
	if (file.good())
	{
		file << edge << " " << vertex << " " << "\n";

		for (int i = 0; i < edge; i++)
		{
			startVertex = rand() % (vertex)+0;
			do
			{
				endVertex = rand() % (vertex)+0;
			} while (startVertex == endVertex);

			edgeWeight = rand() % 1000 + 0;

			file << startVertex << " " << endVertex << " " << edgeWeight << "\n";

			directedMatrix[startVertex][i] = 1;
			directedMatrix[endVertex][i] = -1;
			directedMatrix[vertex][i] = edgeWeight;

			undirectedMatrix[startVertex][i] = 1;
			undirectedMatrix[endVertex][i] = 1;
			undirectedMatrix[vertex][i] = edgeWeight;
		}

	}
	file.close();
}

void IncidenceMatrix::printDirected()
{
	int i, j;

	std::cout << "Macierz Incydencji (graf skierowany): " << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(4) << " ";

	for (i = 0; i < edge; i++) std::cout << std::setw(4) << i;
	std::cout << std::endl << std::endl;

	for (i = 0; i < vertex; i++)
	{
		std::cout << std::setw(4) << i;
		for (j = 0; j < edge; j++) std::cout << std::setw(4) << (int)directedMatrix[i][j];
		std::cout << std::endl;
	}

	std::cout << "Wagi krawedzi: " << std::endl;
	for (int i = 0; i < edge; i++)
	{
		std::cout << std::setw(4) << "[" << directedMatrix[vertex][i] << "]";
	}
	std::cout << std::endl;
}

void IncidenceMatrix::printUdirected()
{
	int i, j;

	std::cout << "Macierz Incydencji (graf nieskierowany): " << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(4) << " ";

	for (i = 0; i < edge; i++) std::cout << std::setw(4) << i;
	std::cout << std::endl << std::endl;

	for (i = 0; i < vertex; i++)
	{
		std::cout << std::setw(4) << i;
		for (j = 0; j < edge; j++) std::cout << std::setw(4) << (int)undirectedMatrix[i][j];
		std::cout << std::endl;
	}

	std::cout << "Wagi krawedzi: " << std::endl;
	for (int i = 0; i < edge; i++)
	{
		std::cout << std::setw(4) << "[" << undirectedMatrix[vertex][i] << "]";
	}
	std::cout << std::endl;
}

void IncidenceMatrix::PrimAlgorithm(int source)
{
	std::priority_queue< iPair, std::vector <iPair>, std::greater<iPair> > pQueue;

	int suma = 0;

	std::vector<int> price(vertex, 10000);

	std::vector<int> parent(vertex, -1);

	std::vector<bool> visited(vertex, false);

	std::cout << "Podaj wierzcholek zrodlowy: " << std::endl;
	std::cin >> source;

	if (source < 0)
		std::cout << "Blad" << std::endl;
	else
	{
		pQueue.push(std::make_pair(0, source));
		price[source] = 0;

		while (!pQueue.empty())
		{
			int u = pQueue.top().second;
			pQueue.pop();

			visited[u] = true;

			for (int i = 0; i < edge; i++)
			{
				if (undirectedMatrix[u][i] == 1)
				{
					for (int j = 0; j < vertex; j++)
					{
						if (undirectedMatrix[j][i] == 1)
						{
							if (visited[j] == false && price[j] > undirectedMatrix[vertex][i])
							{
								price[j] = undirectedMatrix[vertex][i];
								pQueue.push(std::make_pair(price[j], j));
								parent[j] = u;
							}
						}
					}
				}
			}
		}

		std::cout << "Rodzic:	Wierzcholek: " << std::endl;
		for (int i = 1; i < vertex; ++i)
		{
			std::cout << "  " << parent[i] << "   -->   " << i << '\n';
			suma += price[i];
		}

		std::cout << "Waga: " << std::endl;
		std::cout << suma;
		std::cout << std::endl;
	}
}

void IncidenceMatrix::DijksryAlgorithm(int source, int destination)
{
	std::priority_queue< iPair, std::vector <iPair>, std::greater<iPair> > pQueue;

	std::vector<int> distance(vertex, 10000);

	std::vector<int> parent(vertex, -1);

	std::cout << "Podaj zrodlowy wierzcholek: " << std::endl;
	std::cin >> source;
	std::cout << "Podaj koncowy wierzcholek: " << std::endl;
	std::cin >> destination;

	pQueue.push(std::make_pair(0, source));
	distance[source] = 0;

		while (!pQueue.empty())
		{
			int u = pQueue.top().second;
			pQueue.pop();

			for (int i = 0; i < edge; i++)
			{
				if (directedMatrix[u][i] == 1)
				{
					for (int j = 0; j < vertex; j++)
					{
						if (directedMatrix[j][i] == -1)
						{
							if (distance[j] > distance[u] + directedMatrix[vertex][i])
							{
								distance[j] = distance[u] + directedMatrix[vertex][i];
								parent[j] = u;
								pQueue.push(std::make_pair(distance[j], j));
							}
						}
					}
				}
			}
		}

		std::cout << "Droga: " << std::endl;
		std::cout << source << " -> " << parent[destination] << " -> " << destination << '\n';
		std::cout << std::endl;

		std::cout << "Koszt: " << std::endl;
		std::cout << distance[destination];
		std::cout << std::endl;
}

void IncidenceMatrix::clearMatrix()
{
	directedMatrix.clear();
	undirectedMatrix.clear();
}