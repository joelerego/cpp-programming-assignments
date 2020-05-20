#include <iostream>

using namespace std;

class point {
public:
	void print() const {
		cout << "(" << x << ", " << y << ")";
	}
	void set(double x, double y) {
		this -> x = x;
		this -> y = y;
	}
private:
	double x, y;		
};
	
int main() {
	point p1;
	p1.set(4, 5);
	p1.print();
	return 0;	
}
