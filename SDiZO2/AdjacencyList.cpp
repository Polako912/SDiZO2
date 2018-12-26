#include "AdjacencyList.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <functional>
#include <queue>

typedef std::pair<int, int> iPair;

AdjacencyList::AdjacencyList()
{
	vertex = 0;
	edge = 0;
}

AdjacencyList::~AdjacencyList()
{
	clearList();
}

void AdjacencyList::readFromFile()
{
	std::fstream file;
	file.open("data.txt");
	if(file.good())
	{

			file >> edge >> vertex;

			int startVertex, endVertex, weight;
			undirectedList.resize(vertex);
			directedList.resize(vertex);

			for (int i = 0; i < edge; i++)
			{
				file >> startVertex >> endVertex >> weight;
				undirectedList[startVertex].push_back(std::make_pair(endVertex, weight));
				undirectedList[endVertex].push_back(std::make_pair(startVertex, weight));
				directedList[startVertex].push_back(std::make_pair(endVertex, weight));
			}
		
	}
	file.close();
}

void AdjacencyList::GenerateRandom(float density)
{
	int startVertex, endVertex, weight;

	std::cout << "Podaj ilosc wierzcholow: " << std::endl;
	std::cin >> vertex;
	std::cout << "Podaj gestosc grafu :" << std::endl;
	std::cin >> density;

	edge = floor(density/100 *(vertex*(vertex - 1)));

	undirectedList.resize(vertex);
	directedList.resize(vertex);

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

			weight = rand() % 100 + 0;

			file << startVertex << " " << endVertex << " " << weight << "\n";

			undirectedList[startVertex].push_back(std::make_pair(endVertex, weight));
			undirectedList[endVertex].push_back(std::make_pair(startVertex, weight));
			directedList[startVertex].push_back(std::make_pair(endVertex, weight));
		}
	}
	file.close();
}

void AdjacencyList::printDirected()
{
	for (int i = 0; i < directedList.size(); ++i) 
	{
		std::cout << "Lista Sasiedztwa[" << i << "]";

		std::list<std::pair<int, int> >::iterator itr = directedList[i].begin();

		while (itr != directedList[i].end()) 
		{
			printf(" -> %d(%d)", (*itr).first, (*itr).second);
			++itr;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void AdjacencyList::printUdirected()
{
	for (int i = 0; i < undirectedList.size(); ++i)
	{
		std::cout << "Lista Sasiedztwa[" << i << "]";

		std::list<std::pair<int, int> >::iterator itr = undirectedList[i].begin();

		while (itr != undirectedList[i].end())
		{
			printf(" -> %d(%d)", (*itr).first, (*itr).second);
			++itr;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void AdjacencyList::DijksryAlgorithm(int source, int destination)
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

			for (const auto& i : directedList[u])
			{
				int v = i.first;
				int weight = i.second;

					if (distance[v] > distance[u] + weight)
					{
						distance[v] = distance[u] + weight;
						parent[v] = u;
						pQueue.push(std::make_pair(distance[v], v));
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

void AdjacencyList::PrimAlgorithm(int source)
{
	std::priority_queue< iPair, std::vector <iPair>, std::greater<iPair> > pQueue;
 
	int suma = 0;

	std::cout << "Podaj wierzcholek zrodlowy: " << std::endl;
	std::cin >> source;

	std::vector<int> price(vertex, 10000);

	std::vector<int> parent(vertex, -1);

	std::vector<bool> visited(vertex, false);

	pQueue.push(std::make_pair(0, source));
	price[source] = 0;

	if (source < 0)
		std::cout << "Blad" << std::endl;
	else
	{
		while (!pQueue.empty())
		{
			int u = pQueue.top().second;
			pQueue.pop();

			visited[u] = true;

			for (const auto& i : undirectedList[u])
			{
				int v = i.first;
				int weight = i.second;

				if (visited[v] == false && price[v] > weight)
				{
					price[v] = weight;
					pQueue.push(std::make_pair(price[v], v));
					parent[v] = u;
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

void AdjacencyList::clearList()
{
	directedList.clear();
	undirectedList.clear();
}