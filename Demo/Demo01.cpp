#include<iostream>
/*int main()
{
	std::cout << "Enter two number:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of " << v1 << "and" << v2 << "is" << v1 + v2 << std::endl;
	return 0;
}*/

/*int main()
{
	int sum = 0, val = 1;
	while (val <= 10) {
		sum = sum + val;
		val++;
	}
	std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;
	return 0;
}*/

/*int main()
{
	int sum = 0, value = 0;
	while (std::cin >> value)
		sum += value;
	std::cout << "Sum is" << sum << std::endl;
	return 0;
}*/

/*int main()
{
	//currVal������ͳ�Ƶ��������ǽ��������ֵ����val
	int currVal = 0, val = 0;
	//��ȡ��һ��������ȷ��ȷʵ�����ݿ��Դ���
	if (std::cin >> currVal) {
		int cnt=0 ;
		while (std::cin >> val) {
			if (currVal == val) {
				cnt++;
			}
			else {
				std::cout << currVal << "occurs" << cnt << "times" << std::endl;
				currVal = val;
				cnt = 0;
			}
		}
		//��ס��ӡ�ļ������һ��ֵ�ĸ���
		std::cout << currVal << "occurs" << cnt << "times" << std::endl;
	}
	return 0;
}*/