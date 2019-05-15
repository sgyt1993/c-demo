#include<iostream>
#include<string>
#include<vector>
using namespace std;
using std::string;
struct Foo
{
	Foo(int n, double x) ;
};
/*int main()
{
	vector<Foo> v;
	v.emplace_back(1, 2);//1,2实际是调用了Foo的构造函数
	v.emplace(v.begin(), 2, 3);
	v.insert(v.begin(), Foo(4, 5));//insert必须要有一个实例对象
	return 0;
}*/