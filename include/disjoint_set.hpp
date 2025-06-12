#ifndef DISJOINT_SET_HPP
#define DISJOINT_SET_HPP

#include <vector>

template<typename T>
class DisjointSet {
	protected:
	std::vector<size_t> parent;
	std::vector<int> rank;

	public:

	size_t find(size_t i) {
		return (parent[i] == i) ? i : find(parent[i]);
	}

	void unite(size_t x, size_t y) {
		size_t f1 = find(x);
		size_t f2 = find(y);
		if (f1 == f2) return;
		if (rank[f1] < rank[f2]) {
			parent[f1] = f2;
		} else if (rank[f1] > rank[f2]) {
			parent[f2] = f1;
		} else {
			parent[f2] = f1;
			rank[f1]++;
		}
	}

	DisjointSet(const std::vector<T>& elems): parent(elems.size()), rank(elems.size()) {
		for (size_t i=0; i<elems.size(); i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}
};


template <typename T>
class DisjointSetOptimized: public DisjointSet<T> {
	public:
	using DisjointSet<T>::DisjointSet;
	size_t find(size_t i) {
		return (this->parent[i] == i) ? i : (this->parent[i] = find(this->parent[i]));
	}
};




#endif
