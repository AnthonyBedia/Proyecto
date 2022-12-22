#pragma once
#include <iostream>

class vertex;

class edge
{
	int weight;
	edge* next;
	vertex* dest;

	friend class Grafo;
public:
	edge(vertex* _dest, int weight);
};

