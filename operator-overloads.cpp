#include <iostream>

using namespace std;

typedef enum days:std::int8_t {SUN, MON, TUE, WED, THU, FRI, SAT} days;

ostream& operator<<(ostream& cout, const days& d){ 
	switch(d) {
		case SUN: cout << "SUN"; break; 
		case MON: cout << "MON"; break; 
		case TUE: cout << "TUE"; break; 
		case WED: cout << "WED"; break; 
		case THU: cout << "THU"; break; 
		case FRI: cout << "FRI"; break; 
		case SAT: cout << "SAT"; break; 
	}
	return cout;
}

inline days operator++(days& d) {
	return d = static_cast<days>((static_cast<int>(d) + 1) % 7);
}

inline days operator++(days& d, int) {
	days old = d;
	d = static_cast<days>((static_cast<int>(d) + 1) % 7);
	return old;
}

inline days operator+(days& d, int a) {
	d = static_cast<days>((static_cast<int>(d) + a) % 7);
	return d;
}

int main() {
	days a {days::FRI};
	cout << a << endl;
	cout << a++ << endl;
	cout << ++a << endl;
	cout << a+2 << endl;
	return 0;
}
