#include <iostream>

using namespace std;

typedef enum days {SUN, MON, TUE, WED, THU, FRI, SAT} days;

ostream& operator<<(ostream& out, const days& d){ 
	switch(d) {
		case SUN: out << "SUN";
							break;
		case MON: out << "MON";
							break;
		case TUE: out << "TUE";
							break;
		case WED: out << "WED";
							break;
		case THU: out << "THU";
							break;
		case FRI: out << "FRI";
							break;
		case SAT: out << "SAT";
							break;
	};
	return out;
}

inline days operator++(days& d) {
	return d = static_cast<days>((static_cast<int>(d) + 1) % 7);
}

inline days operator++(days& d, int) {
	days old = d;
	d = static_cast<days>((static_cast<int>(d) + 1) % 7);
	return old;
}

int main() {
	days a {days::FRI};
	cout << a << endl;
	cout << a++ << endl;
	cout << ++a << endl;
	return 0;
}
