#include<iostream>
#include<string>
using namespace std;

//函数模板类型
template<typename T> int compare(const T& v1, const T& v2) 
{
	if (v1 > v2) 
	{
		return -1;
	}
	else 
	{
		return 1;
	}
}

/*int main() 
{
	auto k = compare(10, 9);
	cout << k << endl;
	return 0;
}*/