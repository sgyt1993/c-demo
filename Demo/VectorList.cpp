#include<iostream>
#include<vector>
#include<list>
using namespace std;
void main()
{
	list<int> l1(2, 0);
	list<int>::iterator iter;
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	for (iter = l1.begin(); iter != l1.end(); iter++) 
	{
		cout << *iter << endl;
	}
	if (l1.empty()) 
	{
		cout << "l1ЮЊПе" << endl;
	}
	
	system("pause");
}