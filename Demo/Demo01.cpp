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
	//currVal是正在统计的数，我们将读入的新值存入val
	int currVal = 0, val = 0;
	//读取第一个数，并确保确实有数据可以处理
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
		//记住打印文件中最后一个值的个数
		std::cout << currVal << "occurs" << cnt << "times" << std::endl;
	}
	return 0;
}*/