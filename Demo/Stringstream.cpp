#include<iostream>
#include<string>
#include<vector>
#include<sstream>        //istringstream ����������ͷ�ļ�
#include "PersionInfo.h"
using namespace std;
using std::string;
using std::vector;
/*void main()
{
	string line, word;//�ֱ𱣴����������һ�к͵���
	vector<PersonInfo> peoples;//����������������м�¼
	cout << "����������" << endl;
	while (getline(cin, line)) 
	{
		PersonInfo info;//����һ������˼�¼���ݵĶ���
		istringstream record(line);//����¼�󶨵��ն�����С�
		record >> info.name;//��ȡ����
		cout << info.name << endl;
		while (record >> word)
		{ //��ȡ�绰����
			info.phones.push_back(word);//��������
			cout << word << endl;
		}

	}
	system("pause");
}*/