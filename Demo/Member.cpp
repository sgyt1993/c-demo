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
	Sales_item total;//���潻������

	if (std::cin >> total) {
		Sales_item trans;//�������
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
	std::cout << i + i << std::endl;//�����-84
	std::cout << u + i << std::endl;//int�����ռ��32λ�������4294967264
	return 0;

}*/

/*int main()
{
	unsigned u1 = 42, u2 = 10;
	std::cout << u1 - u2 << std::endl;//�����32��ȷ
	std::cout << u2 - u1 << std::endl;//��ʵ�ʽ��ҪΪ����ʱ���ò������ű����ʹ�����
	return 0;
}*/

/*int main()
{
	const int ci = 1024;
	const int &r1 = ci;
	
	r1 = 42//����r1�ǶԳ���������
	int &r2 = ci;//������һ���ǳ�������ָ��һ����������
	return 0;
}*/

/*int main()
{
	int errNum = 0;
	int *const currErr = &errNum;//curErr��һֱָ��errNum
	const double pi = 3.14159;
	const double *const pip = &pi; //pip��һ��ָ��������ĳ���ָ��
	return 0;
}*/

/*int main()
{
	int f = 5;
	int i = 0;	
	int *const p1 = &i;//���ܸı�p1��ֵ������һ�������const
	int *ccc = &f;
	const int ci = 42;//���ܸı�ci��ֵ������һ�������const
	const int *p2= &ci;//�ܸı�p2��ֵ������һ���ײ��const
	const int *const p3 = p2;//���ҵ�const�Ƕ��㣬������ǵײ�
	const int &r = ci;//�����������õ�const���ǵײ�const
	i = 4;
	ccc = &i;
	std::cout << "*pi" << *p1 << std::endl;
	return 0;
}*/

/*int main()
{
	int i = 5;
	int f = 5;
	int *const p1 = &i;//����ָ�룬����ָ��������ַ�����ǿ��Ըı��ַ�е�����
	int const *p2 = &f;//ָ�뱾���ǳ�����*p2���ݲ��ܸı䣬p2����ָ��������ַ
	i = 3;
	std::cout << "p1:" << *p1 << std::endl;//p1:3
	std::cout << "p2:" << *p2 << std::endl;//p2:3
    int k = 6;
	*p1 = 222;
	*p1 = &k;//���ܸı��ַ
	p1 = 222;//���ܸı��ַ

	p2 = &k;
	*p2 = 66;//���ܸı�����
	*p2 = &k;//���ܸı�����
	return 0;
}*/
/*using std::cin;
using std::cout;
using std::endl;
int main()
{
	int i ;
	cout << "������i��ֵ" << endl;
	cin >> i;
	cout << "i:" << i << endl;
	return 0;
}*/