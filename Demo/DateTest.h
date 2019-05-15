#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;
using std::vector;
class A {
public:
	A();
	A(string s);
	void foo();
protected:
	vector<string> v;
};
A::A() {
	v.push_back("This is A()");
}
A::A(string s) : A() {
	v.push_back("This is A(string s)");
	v.push_back(s);
}
void A::foo() {
	for (auto i : v) {
		cout << i << endl;
	}
}
int main() {
	A a("holo");
	a.foo();
	return 0;
}
