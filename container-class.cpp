#include <iostream>
#include <string>

using namespace std;

class stack {
public:
	void reset() { top = EMPTY; }
	void push(int c) { s[++top] = c; }
	int pop() { return s[top--]; }
	int top_of() const { return s[top]; }
	bool empty() const { return (top == EMPTY); }
	bool full() const { return (top == FULL); }
private:
	enum { max_len = 100, EMPTY = -1, FULL = max_len - 1 };
	int s[max_len];
	int top;
};

int main() {
	stack s;
	s.reset(); //s.top = EMPTY
	for(int i = 0; i < 100; i++) {
		s.push(i);
	}
	while(!s.empty())
		cout << s.pop() << endl;
}
