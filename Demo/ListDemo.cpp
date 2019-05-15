#include<iostream>
#include<vector>
#include<list>
#include<string>
using std::string;
using std::to_string;
using namespace std;
/*void main()
{

	vector<int>  vc;
	vc.push_back(1);
	vc.push_back(10);
	vc.push_back(11);
	for (vector<int>::iterator iter = vc.begin(); iter != vc.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (auto k : vc)
	{
		cout << k << endl;
	}

	for (int i = 0; i < vc.size(); i++)
	{
		cout << vc[i] << endl;
	}


	for (int i = 0; i < vc.size(); i++)
	{
		cout << vc.at[i] << endl;
	}
	system("pause");


	list<int>  li;
	li.push_back(1);
	li.push_back(10);
	li.push_back(11);
	for (list<int>::iterator iter = li.begin(); iter != li.end(); iter++)
	{
		cout << *iter << endl;
	}

	for (auto k : li)
	{
		cout << k << endl;
	}
}*/

/*int	main()
{
	list<string> names;
	vector<const char*> oldstyle;
	//name = oldstyle   容器类型不一致   
	names.assign(oldstyle.crbegin(), oldstyle.cend());
	return 0;
}*/

//容器的大小比较
/*int main()
{
	list<int> l1{ 1,2,3,4,5,6,7 };
	list<int> l2{ 2,3,4,5 };
	list<int> l3{ 8 ,9,10 };
	list<int> l4{ 1,2,3,6,8,9 };
	list<int> l5{ 1,2,3,4,5,6,7 };
	list<int> l6{ 1,2,3,4 };
	bool f1 = l2 > l1;
	bool f2 = l3 > l1;
	bool f3 = l4 > l1;
	bool f4 = l5 == l1;
	bool f5 = l6 <= l1;//bool f5 = l6 < l1
	cout << f1 << endl;//1
	cout << f2 << endl;//1
	cout << f3 << endl;//1
	cout << f4 << endl;//1
	cout << f5 << endl;//1
	return 0;
}*/

/*int main()
{
	vector<string> svec;
	svec.push_back("first");
	svec.insert(svec.begin(), "second");//等价于调用slist.push_font("Hello")
	svec.insert(svec.end(), 10, "Anna");
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++) 
	{
		cout << *iter << endl;
	}
	//输出的为second,first,Anna,Anna,Anna,Anna,Anna,Anna,Anna,Anna,Anna,Anna
	svec.clear();
	cout << ".........................................................." << endl;
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << "...................................clear............................." << endl;
	auto iter = svec.begin();
	for (int k = 0; k < 5; k++) {
		iter = svec.insert(iter,  to_string(k));//push_font("Hello")
	}
	for (vector<string>::iterator iter = svec.begin(); iter != svec.end(); iter++)
	{
		cout << *iter << endl;//43210
	}
	return 0;
}*/