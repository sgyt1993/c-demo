#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
using std::string;
/*int main()
{
	const char* p = "Hello World";
	char noNull[] = { 'H','i' };
	string s1(p);
	string s2(noNull, 2);
	string s3(p + 6, 5);
	string s4(p, 6, 5);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	return 0;
}*/

/*int main()
{
	string name("AnnaBelle");
	int k = name.find("nnaB1");
	cout << k << endl;
	return 0;
}*/

/*int main()
{
	string s1 = "pi = 3.14";
	auto d = stod(s1.substr(s1.find_first_of("+-.1234567890")));
	cout << d << endl;  //3.14
}*/

/*int main()
{
	stack<int> intStack;
	for (size_t ix = 0; ix != 10; ix++) {
		intStack.push(ix);
	}
	while (!intStack.empty()) {
		cout << intStack.top() << endl;
		intStack.pop();
	}
	return 0;
}*/