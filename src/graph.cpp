#include "graph.hpp"


double distance(Point a, Point b) {
	auto dx = a.x - b.x;
	auto dy = a.y - b.y;
	return dx * dx + dy * dy;
}