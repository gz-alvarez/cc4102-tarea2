#ifndef KRUSHKHAL_HPP
#define KRUSHKHAL_HPP

#include <vector>

#include <point.hpp>


void krushkal_opt_heap(const std::vector<Point>& points);
void krushkal_opt_arr(const std::vector<Point>& points);
void krushkal_heap(const std::vector<Point>& points);
void krushkal_arr(const std::vector<Point>& points);


#endif
