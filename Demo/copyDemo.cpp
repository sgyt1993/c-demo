#include<iostream>
#include<string>
#include"DemoClass.h"
#include"MyStr.h"
using namespace std;

void  getA(A c) {
	cout << "getA called\n" << endl;
}

/*int main()
{
	string  null_book = "0009999";
	string kk("9999999");
	A a(100);
	A b = a;
	b.show();
	getA(b);
	return 0;
}*/

//����ǿ�������ֵ�������İ���
/*int main() 
{

	MyStr str1(1, "swdw");
	cout << "======================" << endl;
	MyStr str2;//ʹ��Ĭ�Ϲ���
	str2 = str1;//��Ϊstr2ʹ��Ĭ�Ϲ���������Mystr��ʵ���������ø�ֵ���캯��
	cout << "=======================" << endl;
	MyStr str3 = str2;//ʹ�ÿ�������
	return 0;
}*/

//ǳ���������


//swqp����
void swap(MyStr &a, MyStr& b) {
	using std::swap;
	swap(a.id, b.id);
	swap(a.name, b.name);//��Ч�ķ�ʽ�ٴδ���һ������
}
//swap����
int main()
{
	MyStr a(1, "sg");
	MyStr b(2, "sg2");
	swap(a, b);
	cout << a.getId() << endl;//2
	return 0;
}

