#include <iostream>

int main()
{
	int n;
	std::cout << "Enter the size of the array: " << std::endl;
	std::cin >> n;
	
	int a[n];
	std::cout << "Enter the elements of the array: " << std::endl;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	int max = a[0];
	for(int i = 0; i < n; i++) {
		if(a[i] >= max) max = a[i];
	}
	
	int new_max = max;
	while(true) {
		int i;
		for(i = 0; i < n; i++) {
			if(new_max % a[i] == 0) { }
			else break;
		}
		if (i == n) break;
		else new_max++;
	}
	std::cout << new_max;
	return 0;
}
