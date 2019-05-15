#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*int main()
{
	vector<int> ivec;
	//size应该为0，capacity的值看依赖具体实现
	cout << "ivec:size" << ivec.size() <<"     "<< "capacity:" << ivec.capacity() << endl;//ivec:size 0       capacity:0    
	for (int k = 0; k < 20; k++) {
		ivec.push_back(k);
	}

	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 20       capacity:28 
	//讲capacity设置为50
	ivec.reserve(50);
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 20       capacity:50 
	//添加元素，用光容器余量
	while (ivec.size() != ivec.capacity()) 
	{
		ivec.push_back(3);
	}
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 50       capacity:50 

	//如果再添加一个元素，使容器的超过预留值(只要没有操作需求超出vector的容量，vector就不能重新分配内存空间)
	ivec.push_back(1);
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 51       capacity:75 

	//要求退还内存(会将vector超出预留量 == size的值)
	ivec.shrink_to_fit();
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 51       capacity:75 
	return 0;
}*/