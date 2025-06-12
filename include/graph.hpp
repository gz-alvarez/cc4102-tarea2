#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <algorithm>
#include <stddef.h>
#include <vector>


struct Point {
	double x;
	double y;
};


double distance(Point a, Point b);


/// Una arista almacena los indices de los puntos A y B que une.
/// Para evitar duplicados, automáticamente se almacena en A el indice más bajo.
/// La estructura es inmutable.
struct Edge {
	size_t a;
	size_t b;
	double length;
	Edge(size_t a, size_t b, double length): a(std::min(a,b)), b(std::max(a,b)), length(length) {}
	bool operator<(const Edge& rhs) const {
		return length<rhs.length;
	}
};


#endif
