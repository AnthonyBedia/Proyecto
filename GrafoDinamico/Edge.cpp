#include "Edge.h"

edge::edge(vertex* _dest, int _weight)
{
	dest = _dest;
	weight = _weight;
	next = NULL;
}