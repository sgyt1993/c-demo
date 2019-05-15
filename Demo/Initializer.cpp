#include<iostream>
#include<vector>
#include<initializer_list>
using namespace std;

class Num
{
private:
	vector<int> vv;
public:
	Num(initializer_list<int> vc) {
		for (auto itor = vc.begin(); itor != vc.end(); itor++) 
		{
			vv.push_back(*itor);
		}
	}
	void  Print(void)
	{
		for (auto v : vv) 
		{
			cout << v << endl;
		}
	}
};


class NumVc
{
private:
	vector<int> vv;
public:
	NumVc(vector<int> vc) {
		for (auto itor = vc.begin(); itor != vc.end(); itor++)
		{
			vv.push_back(*itor);
		}
	}
	void  Print(void)
	{
		for (auto v : vv)
		{
			cout << v << endl;
		}
	}
};

/*initializer_list �������ǵ���������ʹ��{}ֱ�ӳ�ʼ������vector�ĵײ�Ҳ����initializer_listʵ�ֵ�*/
/*int main()
{
	Num m{1,213,2,5,6};
	m.Print();
	vector<int> m{12,123,13,2};
	return 0;
	
	//NumVc mv{1,213,2,5,6 };������ô��ʼ��
}*/