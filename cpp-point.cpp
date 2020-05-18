#include <iostream>
#include <vector>
using namespace std;

class point {
public:
	point() { 
		this -> x = 0.0; 
		this -> y = 0.0; 
	}
	point(double x, double y) { 
		this -> x = x; 
		this -> y = y; 
	}
	double getx() { return x; } // Inline automatically
	double gety() { return y; } // Inline automatically
	void setx(double v) { x = v; } // Mutator method 
	void sety(double v) { y = v; } // Mutator method
private:
	double x, y;
};

int main() {
	point p1;
	return 0;
}
