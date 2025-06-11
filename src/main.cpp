#include <algorithm>
#include <chrono>
#include <fstream>
#include <random>

#include <krushkhal.hpp>
#include <point.hpp>


std::random_device rd;
std::mt19937 rng(rd());
std::uniform_real_distribution<float> dist(0.0f, 1.0f);


using time_unit = std::chrono::microseconds;


Point genpoint() {
	return Point{
		.x = dist(rng),
		.y = dist(rng)
	};
}


time_unit timeit(void(fun)(const std::vector<Point>&), const std::vector<Point>& points) {
	auto begin = std::chrono::steady_clock::now();
	fun(points);
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
		for (int rep=0; rep<5; rep++) {

			// generate n points
			std::vector<Point> points(n);
			std::generate(points.begin(), points.end(), genpoint);

			// output results for each implementation
			out_opt_heap << n << "," << timeit(krushkal_opt_heap, points) << std::endl;
			out_opt_arr << n << "," << timeit(krushkal_opt_arr, points) << std::endl;
			out_heap << n << "," << timeit(krushkal_heap, points) << std::endl;
			out_arr << n << "," << timeit(krushkal_arr, points) << std::endl;

		}
	}
}