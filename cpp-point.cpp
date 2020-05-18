#include <iostream>
#include <vector>
using namespace std;

class point {
public:
	double getx() { return x; } // Inline automatically
	void setx(double v) { x = v } // Mutator method
private:
	double x, y;
};

int main() {
	return 0;
}
