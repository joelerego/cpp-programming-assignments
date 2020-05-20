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

point operator+ (point& p1, point& p2) {
	point sum; 
	sum.setx(p1.getx() + p2.getx());
	sum.sety(p1.gety() + p2.gety());
	return sum;	
}

ostream& operator<< (ostream& out, point& p) {
	out << "X = " << p.getx() << " Y = " << p.gety();
	return out;
}

int main() {
	point p1 = {10, 20}, p2 = {30, 40};
	point sum = p1 + p2;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << sum << endl;
	return 0;
}
