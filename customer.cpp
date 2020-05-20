#include <iostream>
#include <string>
using namespace std;

enum c_kind { general, wholesale, retail };

class customer {
public:
	void set_name(const string& l, const string& f)
	{ last_name = l; first_name = f; }
	c_kind get_kind() const { return t; }
	void set_kind(c_kind k) { t = k; }
	void print() const { cout << (first_name + " "
												+ last_name) << endl; }
	double price_discount() const;
private:
	string last_name, first_name;
	int id_number;
	c_kind t;
};

// A const method cannot change the value of any members
double customer::price_discount() const
{
	if (t == wholesale)
		return 0.20;
	else
		return 0.1;
}

int main() {
	customer c1;
	c1.set_name("Rego", "Joel");
	c1.set_kind( wholesale );
	c1.print();
}
