#pragma once
#include <vector>

class IncidenceMatrix
{
private:

	int vertex;
	int edge;
	int weight;
	std::vector<std::vector<int> > directedMatrix;
	std::vector<std::vector<int> > undirectedMatrix;

public:

	IncidenceMatrix();
	~IncidenceMatrix();

	void ReadFromFile();

	void GenerateRandom(float density);

	void printDirected();
	void printUdirected();

	void PrimAlgorithm(int source);
	void DijksryAlgorithm(int source, int destination);

	void clearMatrix();
};