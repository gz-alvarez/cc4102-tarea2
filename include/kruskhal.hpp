#ifndef KRUSKHAL_HPP
#define KRUSKHAL_HPP

#include <vector>

#include <point.hpp>


void kruskal_opt_heap(const std::vector<Point>& points);
void kruskal_opt_arr(const std::vector<Point>& points);
void kruskal_heap(const std::vector<Point>& points);
void kruskal_arr(const std::vector<Point>& points);


#endif
