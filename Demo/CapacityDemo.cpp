#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*int main()
{
	vector<int> ivec;
	//sizeӦ��Ϊ0��capacity��ֵ����������ʵ��
	cout << "ivec:size" << ivec.size() <<"     "<< "capacity:" << ivec.capacity() << endl;//ivec:size 0       capacity:0    
	for (int k = 0; k < 20; k++) {
		ivec.push_back(k);
	}

	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 20       capacity:28 
	//��capacity����Ϊ50
	ivec.reserve(50);
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 20       capacity:50 
	//���Ԫ�أ��ù���������
	while (ivec.size() != ivec.capacity()) 
	{
		ivec.push_back(3);
	}
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 50       capacity:50 

	//��������һ��Ԫ�أ�ʹ�����ĳ���Ԥ��ֵ(ֻҪû�в������󳬳�vector��������vector�Ͳ������·����ڴ�ռ�)
	ivec.push_back(1);
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 51       capacity:75 

	//Ҫ���˻��ڴ�(�Ὣvector����Ԥ���� == size��ֵ)
	ivec.shrink_to_fit();
	cout << "ivec:size" << ivec.size() << "     " << "capacity:" << ivec.capacity() << endl;//ivec:size 51       capacity:75 
	return 0;
}*/