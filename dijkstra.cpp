// Week 3 Homework from Professor Ira Pohl
// By Joel E. Rego (May 22, 2020)
//

// This program is an implementation of the Dijkstra's
// algorithm. To maintain readability, I have made a
// class that creates a random graph. You are free to 
// change the size of this graph. The graph also contains 
// a method to find shortest path from single source, using
// Dijkstra's algorithm.
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
		cout << "\nN: \t";
		for(int i=0; i<size; ++i) {
			cout << i + 1 << "\t";
		}
		cout << endl;
		for(int i=0; i<size*8 + 1; ++i) {
			cout << "-";
		}
		cout << endl;
		for(int i=0; i<size; ++i) {
			cout << i + 1 << ": \t";
			for(int j=0; j<size; ++j) {
				cout << graph[i][j] << "\t";
			}
			cout << endl;			
		}
		cout << endl;		
	}
	~new_graph() { // Destructor
		delete graph;
	}
private:
	bool** graph;
	int size;
};

int main() {
	int size;
	cout << "\nEnter the number of nodes: ";
	cin >> size;
	new_graph g = { size };
	g.generate();
	cout << "\nGraph of size " << size << " is generated." << endl;	
	g.print();
}
