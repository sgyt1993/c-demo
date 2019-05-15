#include<iostream>
#include<string>
#include<vector>
#include<sstream>        //istringstream 必须包含这个头文件
#include "PersionInfo.h"
using namespace std;
using std::string;
using std::vector;
/*void main()
{
	string line, word;//分别保存来自输入的一行和单词
	vector<PersonInfo> peoples;//保存来自输入的所有记录
	cout << "请输入名字" << endl;
	while (getline(cin, line)) 
	{
		PersonInfo info;//创建一个保存此记录数据的对象
		istringstream record(line);//讲记录绑定到刚读入的行、
		record >> info.name;//读取名字
		cout << info.name << endl;
		while (record >> word)
		{ //读取电话号码
			info.phones.push_back(word);//保存他们
			cout << word << endl;
		}

	}
	system("pause");
}*/