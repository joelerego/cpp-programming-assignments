#include <iostream>
#include <climits>

using namespace std;

int main() {
	int num, min = 0, max = 0, count = 0;
	
	while (cout << "Enter number: " << endl && cin >> num) {
		if (count == 0) min = num;
		if (num >= max) max = num;
		if (num <= min) min = num;
		count++; 
	} 
	
	if(count) cout << "Minimum: " << min << "\tMaximum: " << max << endl;
	else cout << "Minimum: " << INT_MIN << "\tMaximum: " << INT_MAX << endl;
	return 0;
}
