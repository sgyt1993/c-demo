#include<iostream>
/*int main()
{
	Sales_item book;
	std::cin >> book;
	std::cout << book << std::endl;
	return 0;
}*/

/*int main()
{
	Sales_item total;//保存交易总数

	if (std::cin >> total) {
		Sales_item trans;//保存变量
		while (std::cin >> trans) {
			if (total.isbn == trans.isbn) {
				total += trans;
			}
			else {
				std::cout << total << std::endl;
				total = trans;
			}
		}
		std::cout << total << std::endl;

	}
	else {
		std::cerr << "No data?" << std::endl;
		return -1;
	}
	return 0;
}*/

/*int main()
{
	unsigned u = 10;
	int i = -42;
	std::cout << i + i << std::endl;//输出是-84
	std::cout << u + i << std::endl;//int如果是占用32位，输出是4294967264
	return 0;

}*/

/*int main()
{
	unsigned u1 = 42, u2 = 10;
	std::cout << u1 - u2 << std::endl;//输出是32正确
	std::cout << u2 - u1 << std::endl;//当实际结果要为负数时，用不带符号变量就错误了
	return 0;
}*/

/*int main()
{
	const int ci = 1024;
	const int &r1 = ci;
	
	r1 = 42//错误，r1是对常量的引用
	int &r2 = ci;//错误，让一个非常量引用指向一个常量对象
	return 0;
}*/

/*int main()
{
	int errNum = 0;
	int *const currErr = &errNum;//curErr将一直指向errNum
	const double pi = 3.14159;
	const double *const pip = &pi; //pip是一个指向常量对象的常量指针
	return 0;
}*/

/*int main()
{
	int f = 5;
	int i = 0;	
	int *const p1 = &i;//不能改变p1的值，这是一个顶层的const
	int *ccc = &f;
	const int ci = 42;//不能改变ci的值，这是一个顶层的const
	const int *p2= &ci;//能改变p2的值，这是一个底层的const
	const int *const p3 = p2;//靠右的const是顶层，靠左的是底层
	const int &r = ci;//用于申明引用的const都是底层const
	i = 4;
	ccc = &i;
	std::cout << "*pi" << *p1 << std::endl;
	return 0;
}*/

/*int main()
{
	int i = 5;
	int f = 5;
	int *const p1 = &i;//常量指针，不能指向其他地址，但是可以改变地址中的内容
	int const *p2 = &f;//指针本身是常量，*p2内容不能改变，p2可以指向其他地址
	i = 3;
	std::cout << "p1:" << *p1 << std::endl;//p1:3
	std::cout << "p2:" << *p2 << std::endl;//p2:3
    int k = 6;
	*p1 = 222;
	*p1 = &k;//不能改变地址
	p1 = 222;//不能改变地址

	p2 = &k;
	*p2 = 66;//不能改变内容
	*p2 = &k;//不能改变内容
	return 0;
}*/
/*using std::cin;
using std::cout;
using std::endl;
int main()
{
	int i ;
	cout << "请输入i的值" << endl;
	cin >> i;
	cout << "i:" << i << endl;
	return 0;
}*/