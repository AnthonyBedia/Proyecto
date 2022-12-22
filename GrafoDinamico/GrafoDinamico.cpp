
#include <iostream>
#include "Grafo.h"

int main()
{
	Grafo* grafo = new Grafo();
	int opc = 0;
	grafo->AddVertex("A");
	grafo->AddVertex("B");
	grafo->AddVertex("C");
	grafo->AddVertex("D");
	grafo->AddVertex("E");


	/*grafo->AddVertex("A");
	grafo->AddVertex("B");
	grafo->AddVertex("C");
	grafo->AddVertex("D");
	grafo->AddVertex("E");
	grafo->AddVertex("F");
	grafo->AddVertex("G");
	grafo->AddEdge("A", "B", 7);
	grafo->AddEdge("A", "D", 5);
	grafo->AddEdge("B", "A", 7);
	grafo->AddEdge("B", "C", 8);
	grafo->AddEdge("B", "D", 9);
	grafo->AddEdge("B", "E", 7);
	grafo->AddEdge("C", "B", 8);
	grafo->AddEdge("C", "E", 5);
	grafo->AddEdge("D", "A", 5);
	grafo->AddEdge("D", "B", 9);
	grafo->AddEdge("D", "E", 15);
	grafo->AddEdge("D", "F", 6);
	grafo->AddEdge("E", "B", 7);
	grafo->AddEdge("E", "C", 5);
	grafo->AddEdge("E", "D", 15);
	grafo->AddEdge("E", "F", 8);
	grafo->AddEdge("E", "G", 9);
	grafo->AddEdge("F", "D", 6);
	grafo->AddEdge("F", "E", 8);
	grafo->AddEdge("F", "G", 11);
	grafo->AddEdge("G", "E", 9);
	grafo->AddEdge("G", "F", 11);*/

	/*grafo->AddVertex("A");
	grafo->AddVertex("B");
	grafo->AddVertex("C");
	grafo->AddVertex("D");
	grafo->AddVertex("E");
	grafo->AddVertex("F");
	grafo->AddVertex("G");
	grafo->AddEdge("A", "A", 13);
	grafo->AddEdge("A", "D", 8);
	grafo->AddEdge("B", "B", 52);
	grafo->AddEdge("B", "C", 17);
	grafo->AddEdge("B", "D", 83);
	grafo->AddEdge("B", "F", 97);
	grafo->AddEdge("B", "G", 60);
	grafo->AddEdge("C", "A", 4);
	grafo->AddEdge("D", "B", 97);
	grafo->AddEdge("D", "C", 37);
	grafo->AddEdge("D", "D", 22);
	grafo->AddEdge("D", "E", 41);
	grafo->AddEdge("D", "G", 64);
	grafo->AddEdge("E", "B", 8);
	grafo->AddEdge("E", "E", 45);
	grafo->AddEdge("E", "F", 92);
	grafo->AddEdge("F", "A", 12);
	grafo->AddEdge("F", "B", 8);
	grafo->AddEdge("F", "E", 42);
	grafo->AddEdge("G", "D", 17);*/

	while (opc != 6)
	{
		system("cls");
		cout << "1. Insertar vertice" << endl;
		cout << "2. Insertar arista" << endl;
		cout << "3. Ver tamanio" << endl;
		cout << "4. Mostrar matriz/lista de adyacencia" << endl;
		cout << "5. Ejecutar algoritmo de Prim" << endl;
		cout << "6. Salir" << endl;

		cout << endl;
		cout << "Ingrese una opcion del menu: ";
		cin >> opc;

		system("cls");

		switch (opc)
		{
		case 1:
		{
			string name;
			cout << "Ingrese el nombre del vertice: ";
			cin >> name;

			grafo->AddVertex(name);

			break;
		}
		case 2:
		{
			if (grafo->IsEmpty())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string ori, dest;
				int weight;
				cout << "Ingrese el nombre del vertice de origen: ";
				cin >> ori;
				cout << "Ingrese el nombre del vertice destinatario: ";
				cin >> dest;
				cout << "Ingrese el peso: ";
				cin >> weight;

				grafo->AddEdge(ori, dest, weight);
				char rpta = ' ';
				cout << "Desea insertar arista: " << dest << "-->" << ori << "?";
				cin >> rpta; 
				if (rpta == 's' || rpta == 'S')
					grafo->AddEdge(dest, ori, weight);
				else
					break;
			}

			break;
		}
		case 3:
		{
			int size = grafo->GetSize();
			cout << "El grafo tiene " << size << " vertices" << endl;

			break;
		}
		case 4:
		{
			if (grafo->IsEmpty())
				cout << "El grafo esta vacio" << endl;
			else
				grafo->ShowAdjacencyList();

			break;
		}
		case 5:
		{
			if (grafo->IsEmpty())
				cout << "El grafo esta vacio" << endl;
			else
			{
				string name;
				cout << "Ingrese el nombre del vertice de origen: ";
				cin >> name;

				grafo->Prim(name);
			}

			break;
		}
		}

		cin.get();
		cin.get();
	}

}
