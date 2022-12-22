#pragma once
#include "Vertex.h"
#include "Edge.h"
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <unordered_set>

using namespace std;

class Grafo
{
	vertex* primero;
	int size;

public:
	Grafo();
	bool IsEmpty(); // Retorna true si el grafo está vacío
	int GetSize(); // Retorna el número de vertices en el grafo
	vertex* GetVertex(string name); // Retornar el vertice que tenga el nombre especificado
	void AddVertex(string name); // Inserta un vertice al grafo
	void AddEdge(string ori, string dest, int weight); // Inserta arista entre los dos vertices especificados con el peso especificado
	void ShowAdjacencyList(); // Mostrar todos los vertices con sus aristas y pesos
	void Prim(string origin);// Genera el arbol recubridor minimo con el algoritmo de Prim
};

