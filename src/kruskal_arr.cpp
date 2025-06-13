#include <kruskal.hpp>
#include <graph.hpp>
#include <disjoint_set.hpp>
#include <algorithm>

void kruskal_arr(const std::vector<Point>& points, std::vector<Edge>& edges) {
    // 1) ordenamos las aristas por peso con std::sort
    std::sort(edges.begin(), edges.end());

    // 2) creamos un disjointset sin optimizar
    DisjointSet<Point> ds(points);

    // 3) recorremos las aristas de menor a mayor
    std::vector<Edge> ret_edges;
    ret_edges.reserve(points.size() - 1);

    // 4) por cada arista: 
    for (const Edge& e : edges) {
        size_t root_a = ds.find(e.a);
        size_t root_b = ds.find(e.b);

        //    - usamos find para ver si son del mismo conjunto
        //    - unimos los conjuntos con union
        if (root_a != root_b) {
            ret_edges.push_back(e);
            ds.unite(root_a, root_b);
        }

        // (while aristas > n-1)
        if (ret_edges.size() == points.size() - 1)
            break;
    }
}


// Como debo hacerlo
// 1) ordenamos las aristas por peso con std::sort
// 2) creamos un disjointset sin optimizar
// 3) recorremos las aristas de menor a mayor
// 4) por cada arista: (while aristas > n-1)
//    - usamos find para ver si son del mismo conjunto
//    - else: unimos los conjuntos con union

