#include <iostream>
using namespace std;

int main() {
	int arr1[5] = {1, 2, 3, 4, 5}; // Normal declaration of an array
	cout << "First 1D array: " << endl;
	for(int i=0; i<5; i++) cout << arr1[i] << endl;
	
	int* arr2 = new int[5]; // Pointer to a block of memory
	for(int i=0; i<5; i++) arr2[i] = i+6;
	cout << "Second 1D array: " << endl;
	for(int i=0; i<5; i++) cout << *arr2 + i << endl;
	
	// Now let us create a dynamic 2D array
	// Method 1: We can use a single pointer. But this
	// creates a situation where you have a static number
	// of rows but a dynamic number of columns.
	//
	int* arr3[5];
	for(int i=0; i<5; i++) {
		arr3[i] = new int[5]; // This enforces a 5x5 array
	}
	
	cout << "Partially dynamic 2D array" << endl;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			arr3[i][j] = i + j;
			cout << arr3[i][j] << "\t";
		}
		cout << endl;
	}
	
	// Method 2: Here, we use a pointer to a pointer. This
	// is a truly dynamically allocated 2 dimensional or 
	// multidimensional array
	//
	int** arr4;
	arr4 = new int*[5]; // Pointing to pointers to integers
	for(int i=0; i<5; i++) {
		arr4[i] = new int[5]; //Pointing to integer values
	}
	
	cout << "Truly dynamic 2D array" << endl;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			arr4[i][j] = i + j;
			cout << arr4[i][j] << "\t";
		}
		cout << endl;
	}
}
