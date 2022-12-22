#pragma once
#include <iostream>

class edge;

class vertex
{
	std::string name;
	vertex* next;
	edge* ari;

	friend class Grafo;
public:
	vertex(std::string name);
};

