// The following CPP program contains 
// a template function that can take 
// all summable datatypes as input and
// return the sum.
//

#include <iostream>
#include <vector>

using namespace std;

// #define constants become consts
const int N = 40;

// The following is a template for universal summation
template <class T>
inline void summation(T& sum, T size, vector<T>& data) {
	for(int i=0; i<size; i++) {
		sum += data[i];
	}
}

int main() {
	int sum = 0;
	vector<int> data;
	
	for(int i = 0; i < N; ++i) 
		data.push_back(i);
	
	summation(sum, N, data);
	
	printf("Sum is %d\n", sum);
	return 0;

}
