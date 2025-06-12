#include <algorithm>
#include <chrono>
#include <fstream>
#include <print>
#include <random>

#include <kruskal.hpp>
#include <graph.hpp>


std::random_device rd;
std::mt19937_64 rng(rd());
std::uniform_real_distribution<double> dist(0.0, 1.0);


using time_unit = std::chrono::microseconds;


Point genpoint() {
	return Point{
		.x = dist(rng),
		.y = dist(rng)
	};
}


time_unit timeit(void(fun)(const std::vector<Point>&, std::vector<Edge>&), const std::vector<Point>& points, const std::vector<Edge> edges) {
	std::vector<Edge> edges_cp = edges;
	auto begin = std::chrono::steady_clock::now();
	fun(points, edges_cp);
	auto delta = std::chrono::duration_cast<time_unit>(std::chrono::steady_clock::now() - begin);
	return delta;
}


int main(int, char**) {

	// 𝑁 ∈ {2**5, 2**6, …, 2**12}
	std::array<uint64_t,12-5+1> ns;
	for (int i=5; i<13; i++) {
		ns[i-5] = 1 << i;
	}

	std::ofstream out_opt_heap("out_opt_heap.csv");
	std::ofstream out_opt_arr("out_opt_arr.csv");
	std::ofstream out_heap("out_heap.csv");
	std::ofstream out_arr("out_arr.csv");

	for (auto n: ns) {
		std::println("n={}", n);
		for (int rep=0; rep<5; rep++) {

			// generate n points
			std::vector<Point> points(n);
			std::generate(points.begin(), points.end(), genpoint);

			std::vector<Edge> edges;
			edges.reserve(n*(n-1)/2);

			for (size_t i=0; i<n; i++) {
				for (size_t j=i+1; j<n; j++) {
					edges.emplace_back(i, j, distance(points[i], points[j]));
				}
			}

			// output results for each implementation
			out_opt_heap << n << "," << timeit(kruskal_opt_heap, points, edges) << std::endl;
			out_opt_arr << n << "," << timeit(kruskal_opt_arr, points, edges) << std::endl;
			out_heap << n << "," << timeit(kruskal_heap, points, edges) << std::endl;
			out_arr << n << "," << timeit(kruskal_arr, points, edges) << std::endl;

		}
	}
}