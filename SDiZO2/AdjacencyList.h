#pragma once
#include <list>
#include <vector>

class AdjacencyList
{
private:

	int vertex;
	int edge;
	std::vector<std::list<std::pair<int, int> > > undirectedList;
	std::vector<std::list<std::pair<int, int> > > directedList;

public:

	AdjacencyList();
	~AdjacencyList();

	void readFromFile();

	void GenerateRandom(float density);

	void printDirected();
	void printUdirected();

	void DijksryAlgorithm(int source, int destination);
	void PrimAlgorithm(int source);

	void clearList();
};