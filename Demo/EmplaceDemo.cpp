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
	v.emplace_back(1, 2);//1,2ʵ���ǵ�����Foo�Ĺ��캯��
	v.emplace(v.begin(), 2, 3);
	v.insert(v.begin(), Foo(4, 5));//insert����Ҫ��һ��ʵ������
	return 0;
}*/