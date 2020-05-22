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
	new_graph(int size = 5): size(size) { // Default Constructor
		graph = new bool*[size];
		for(int i = 0; i < size; ++i)
			graph[i] = new bool[size];		
	}
	void generate() {
		for(int i=0; i<size; ++i) {
			for(int j=0; j<size; ++j) {
				if (i==j) graph[i][j] = false; // Enforce no loops
				else {
					srand(clock());
					graph[i][j] = graph[j][i] = ( rand()%100 > 19 );
				}
			}
		} 
	}
	int graph_size() {
		return size;
	}
	void print() {
		for(int i=0; i<size; ++i) {
			for(int j=0; j<size; ++j) {
				cout << graph[i][j] << "\t";
			}
			cout << endl;			
		}
		
	}
	~new_graph() { // Destructor
		delete graph;
	}
private:
	bool** graph;
	int size = 5;
};

int main() {
	new_graph g = { 5 };
	g.generate();
	g.print();
}
