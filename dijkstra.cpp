// Week 3 Homework from Professor Ira Pohl
// By Joel E. Rego (May 30, 2020)
//

// Please vist github.com/joelerego for all
// previous assignments.
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
// a dynamically allocated 2D integer array which
// represents the existence of an edge from i to j.
// The matrix is a square matrix, i.e, i equals j and
// the total number of nodes in the graph is i or j.
//
class new_graph {
public:
	new_graph(int size = 5): size(size) { // Default Constructor
		graph = new int*[size];
		for(int i = 0; i < size; ++i)
			graph[i] = new int[size];		
	}
	
	void generate() {
		for(int i=0; i<size; ++i) {
			for(int j=0; j<size; ++j) {
				if (i==j) graph[i][j] = 999; // Enforce no loops
				else {
					srand(clock());
					graph[i][j] = graph[j][i] = rand()%10;
					
					// If there is no edge, it means the distance
					// is infinite. We represent infinite using a
					// large number in this program, like 999.
					//
					if (graph[i][j] == 0) graph[i][j] = graph[j][i] = 999;
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
			cout << i << "\t";
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
	
	void dijkstra();
	
	~new_graph() { // Destructor
		delete graph;
	}
private:
	int** graph;
	int size;
};

// The following method
void new_graph::dijkstra() {
	int source = 0, destination = size - 1;
	int* close = new int[size];
	int* open = new int[size];
	
	// Initially, all nodes are unreachable, or infinite,
	// which is indicated by -1.
	//
	for(int i=0; i<size; ++i) 
		open[i] = close[i] = 999;
	
	// Initially, the source '0' is reachable
	open[source] = 0;
	
	
	for(int i = 0; i < size; ++i)
	{
		// First, we add the minimum distance in the
		// open set into the closed set, by doing the following.
		// We store the index of the minimum distance in a 
		// variable named min.
		//
		int min = 999;
		for(int j = 0; j < size; ++j)
			if(open[j] < min and open[j] < close[j]) min = j;
			
		// Now that we have found min, let us store it in our
		// closed set.
		//
		close[min] = open[min];
		
		// The second step is recalculating all the possible
		// distances in the open set, and replacing them if
		// we find a shorter distance.
		//
		for (int j = 0; j < size; ++j)
			open[j] = open[j] < (close[min] + graph[min][j]) ? open[j] : close[min] + graph[min][j];			
	}
	
	cout << "Miminum distances: " << endl;
	for (int i = 0; i < size; i++ ) 
	{
		cout << 0 << " ---> " << i << " = " << close[i] << endl;
	}
	cout << endl;
}

int main() {
	int size;
	cout << "\nEnter the number of nodes: ";
	cin >> size;
	
	new_graph g = { size };
	g.generate();
	cout << "\nGraph of size " << size << " is generated." << endl;	
	cout << "\nWeighted matrix of the graph: " << endl;
	g.print();
	
	g.dijkstra();
}
