// Week 3 Exercise from Professor Ira Pohl
// By Joel E. Rego (May 22, 2020)
//

// This program is an implementation of the is-connected
// algorithm. To maintain readability, I have made a
// class that creates a random graph. You are free to 
// change the size of this graph.
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
			cout << i  << "\t";
		}
		cout << endl;
		for(int i=0; i<size*8 + 1; ++i) {
			cout << "-";
		}
		cout << endl;
		for(int i=0; i<size; ++i) {
			cout << i << ": \t";
			for(int j=0; j<size; ++j) {
				cout << graph[i][j] << "\t";
			}
			cout << endl;			
		}
		cout << endl;		
	}
	bool is_connected();
	~new_graph() { // Destructor
		delete graph;
	}
private:
	bool** graph;
	int size;
};

// Implementation of the is connected 
// algorithm invented by Ira Pohl. A 
// generalization of this algorithm later
// became known as breadth-first search.
//

bool new_graph::is_connected() {
	int old_size = 0, c_size = 0;
	bool* close = new bool[size];
	bool* open = new bool[size];
	for(int i=0; i<size; ++i) 
		open[i] = close[i] = false;
	
	// Initially, the source '0' is reachable
	open[0] = true;
	
	while(c_size < size) {
		
		for (int i = 0; i < size; ++i){
			old_size = c_size;
			// Adding nodes to the closed set
			if (open[i] && (close[i] == false)) {
				close[i] = true;
				c_size++;
				for (int j = 0; j < size; ++j)
					open[j] = open[j] || graph[i][j];
			}
		}
		if (c_size == size ) return true;
		if (old_size == c_size ) return false;
	}
	return true;
}

int main() {
	int size;
	cout << "\nEnter the number of nodes: ";
	cin >> size;
	new_graph g = { size };
	g.generate();
	cout << "\nGraph of size " << size << " is generated." << endl;	
	g.print();
	cout << g.is_connected() << endl;
}
