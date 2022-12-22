#include "Grafo.h"


Grafo::Grafo()
{
	primero = NULL;
	size = 0;
}

bool Grafo::IsEmpty()
{
	return size == 0;
}

int Grafo::GetSize()
{
	return size;
}

vertex* Grafo::GetVertex(string name)
{
	vertex* i = primero;

	while (i != NULL)
	{
		if (i->name == name)
			return i;

		i = i->next;
	}

	return NULL;
}

void Grafo::AddVertex(string name)
{
	if (GetVertex(name) == NULL)
	{
		vertex* nuevo = new vertex(name);

		if (IsEmpty())
			primero = nuevo;
		else
		{
			vertex* i = primero;

			while (i->next != NULL)
				i = i->next;

			i->next = nuevo;
		}

		size++;
	}
	else
		cout << "Ese vertice ya existe en el grafo" << endl;
}

void Grafo::AddEdge(string ori, string dest, int weight)
{
	vertex* vOri = GetVertex(ori);
	vertex* vdest = GetVertex(dest);

	if (vOri == NULL)
		cout << "El vertice de origen no existe" << endl;

	if (vdest == NULL)
		cout << "El vertice de destino no existe" << endl;

	if (vOri != NULL && vdest != NULL)
	{
		edge* nueva = new edge(vdest, weight);

		if (vOri->ari == NULL)
			vOri->ari = nueva;
		else
		{
			edge* j = vOri->ari;

			while (j->next != NULL)
				j = j->next;

			j->next = nueva;
		}
	}
}

void Grafo::ShowAdjacencyList()
{
	vertex* i = primero;

	while (i != NULL)
	{
		edge* j = i->ari;
		cout << i->name << " = ";

		while (j != NULL)
		{
			cout << i->name << "->" << j->weight << "->" << j->dest->name << ",";
			j = j->next;
		}

		cout << endl;
		i = i->next;
	}
}
void Grafo::Prim(string origin)
{
	vertex* vOrigin = GetVertex(origin);

	if (vOrigin == NULL)
	{
		cout << "El vertice de origen no existe" << endl;
		return;
	}

	map<vertex*, map<vertex*, int>> matrizady;
	list<pair<vertex*, pair<vertex*, int>>> listaSolucion;
	unordered_set<vertex*> visitados;

	vertex* vi = primero;

	while (vi != NULL)
	{
		vertex* vj = primero;

		while (vj != NULL)
		{
			matrizady[vi][vj] = 0;
			vj = vj->next;
		}

		edge* aj = vi->ari;

		while (aj != NULL)
		{
			matrizady[vi][aj->dest] = aj->weight;
			aj = aj->next;
		}

		vi = vi->next;
	}

	visitados.insert(vOrigin);
	int edges = 1;

	while (edges < size)
	{
		vertex* vMinorigin, * vMinDestino;
		int weightMin = numeric_limits<int>::max();

		for (unordered_set<vertex*>::iterator i = visitados.begin(); i != visitados.end(); i++)
		{
			for (map<vertex*, int>::iterator j = matrizady[*i].begin(); j != matrizady[*i].end(); j++)
			{
				if (j->second < weightMin && j->second != 0 && visitados.count(j->first) == 0)
				{
					weightMin = j->second;
					vMinorigin = *i;
					vMinDestino = j->first;
				}
			}
		}

		listaSolucion.push_back(pair<vertex*, pair<vertex*, int>>(vMinorigin, pair<vertex*, int>(vMinDestino, weightMin)));
		visitados.insert(vMinDestino);
		edges++;
	}
	int suma = 0;

	for (list<pair<vertex*, pair<vertex*, int>>>::iterator i = listaSolucion.begin(); i != listaSolucion.end(); i++)
	{
		cout << i->first->name << " <-> " << i->second.second << " <-> " << i->second.first->name << endl;
		suma += i->second.second;
	}
	cout << suma;
}