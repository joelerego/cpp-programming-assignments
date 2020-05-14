// C++ program to illustrate the 
// functions in std::vector 
#include <iostream> 
#include <vector> 

using namespace std; 

int main() 
{ 
	vector<int> arr; 

	// The following loop pushes 5 numbers into the dynamic array
	for (int i = 1; i <= 5; i++) 
		arr.push_back(i); 

	cout << "Size : " << arr.size(); 
	cout << "\nCapacity : " << arr.capacity(); 
	cout << "\nMax_Size : " << arr.max_size(); 

	cout << "\nThe Array contains: \n";
	for (int i=0; i<arr.size(); i++) 
		cout << arr[i] << endl;
	
	// resizes the vector size to 4 
	arr.resize(4); 

	// prints the vector size after resize() 
	cout << "\nSize : " << arr.size(); 
	
	cout << "\nThe Array contains: \n";
	for (int i=0; i<arr.size(); i++) 
		cout << arr[i] << endl;

	// checks if the vector is empty or not 
	if (arr.empty() == false) 
		cout << "\nVector is not empty"; 
	else
		cout << "\nVector is empty"; 

	// Shrinks the vector 
	arr.shrink_to_fit(); 
	cout << "\nVector elements are: "; 
	for (auto it = arr.begin(); it != arr.end(); it++) 
		cout << *it << " "; 

	return 0; 
} 
