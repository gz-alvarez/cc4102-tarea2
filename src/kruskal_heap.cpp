#include <kruskal.hpp>

#include <queue>

#include <graph.hpp>
#include <disjoint_set.hpp>


void kruskal_heap(const std::vector<Point>& points, std::vector<Edge>& edges) {
	std::priority_queue<Edge> heap;
	for (Edge e: edges) {
		heap.push(e);
	}

	DisjointSet ds(points);
	std::vector<Edge> ret_edges;
	ret_edges.reserve(points.size()-1);

	while (ret_edges.size() < points.size()-1) {
		const Edge& next = heap.top();
		size_t sa = ds.find(next.a);
		size_t sb = ds.find(next.b);
		if (sa != sb) {
			ret_edges.push_back(next);
			ds.unite(sa, sb);
		}
		heap.pop();
	}
}