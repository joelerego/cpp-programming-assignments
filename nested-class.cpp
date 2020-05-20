#include <iostream>
using namespace std;
char c; // External scope ::c

class X {
public:
	char c; // X::c
	class Y { // Inner class declaration X::Y::
		public:
			void foo(char e)
			{
				X t;
				::c = t.c = c = e;
			}
		private:
			char c;		// X::Y::c
	};
};

int main() {
	X I;
	I.c = 'a';
	I.Y::f('b');
	cout << c;
	return 0;
}
