#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include <vector>

#include <graph.hpp>


void kruskal_opt_heap(const std::vector<Point>& points, std::vector<Edge>& edges);
void kruskal_opt_arr(const std::vector<Point>& points, std::vector<Edge>& edges);
void kruskal_heap(const std::vector<Point>& points, std::vector<Edge>& edges);
void kruskal_arr(const std::vector<Point>& points, std::vector<Edge>& edges);


#endif
