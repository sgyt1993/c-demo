//��ʾ����
#include<iostream>
using namespace std;
class A 
{
public:
	inline void func(int, int);//����Ա����func()����Ϊ��������
	inline void print();//����Ա����print��������Ϊ�ں�����
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
	a.func(1, 2);//����func(1,2)������������ֱ�ӽ�i=1,j=2д������
	a.print();//����print()�����������ڽ�cout<<"�������Ϊ��"<<i*j<<endl;ֱ��д������
	return 0;
}*/