// The following program computes
// the probability for dice possibilites
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int sides = 6;

int main () {
	const int n_dice = 2;
	srand(clock());
	cout << "\nEnter the number of trails: " << endl;
	int trials;
	cin >> trials;
	int outcomes[13] = {0};
	for (int i=0; i<trials; ++i)
		outcomes[(rand()%6+1)+(rand()%6+1)]++;
	cout << "Probability: \n";
	for (int i=2; i<n_dice*sides+1; ++i)
		cout << "i = " << i << " p = " << static_cast<double>(outcomes[i])/trials << endl;
	cout<<endl;
	return 0;
} 
