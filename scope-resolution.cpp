#include <iostream>
using namespace std;

int count = 0;

//Unary scope resolution operator
void how_many(double w[], double n, int& count) {
		for(int i=-0; i<5; i++) {
			count += (w[i] == n);
		}
		++::count;		
}

int main() {
	double arr[5] = { 1, 2, 3, 1, 1 };
	how_many(arr, 1, count);
	cout << count;
}
