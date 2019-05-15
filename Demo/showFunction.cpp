//显示内联
#include<iostream>
using namespace std;
class A 
{
public:
	inline void func(int, int);//将成员函数func()申明为内联函数
	inline void print();//将成员函数print（）声明为内涵函数
private:
	int i, j;
};
void A::func(int x,int y)
{
	i = x;
	j = y;
}
void A::print()
{
	cout << "x*y" << i * j << endl;
}
/*int main()
{
	A a;
	a.func(1, 2);//调用func(1,2)内联函数等于直接将i=1,j=2写在这里
	a.print();//调用print()内联函数等于将cout<<"两数相乘为："<<i*j<<endl;直接写到该行
	return 0;
}*/