// This program creates a randomly generated graph.
// It uses the heap to dynamically allocate memory to
// a 2D boolean array.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// The following is the graph class which creates
// a dynamically allocated 2D boolean array which
// represents the existence of an edge from i to j.
// The matrix is a square matrix, i.e, i equals j and
// the total number of nodes in the graph is i or j.
//
class new_graph {
public:
	new_graph(int size = 5) {
		graph = new bool*[size];
		for(int i = 0; i < size; ++i)
			graph[i] = new bool[size];		
	}
	~new_graph() {
		delete graph;
	}
private:
	bool** graph;	
};

int main() {
	
}
