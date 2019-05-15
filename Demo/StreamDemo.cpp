#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/*int main()
{
	ofstream openFile("f:\\sgyt.txt");
	if (openFile.fail())
	{
		cout << "打开文件错误！" << endl;
		cout << "f:\\sgyt.txt" << endl;
		exit(0);
	}
	openFile << "abc def ghi";
	openFile.close();
	return 0;
}*/
/*int main()
{
	ifstream read("f:\\sgyt.txt");
	if (read.fail())
	{
		cout << "文件错误" << endl;
		exit(0);
	}
	const int len = 20;
	char str[len];
	//read >> str;   这个遇见空格就停止
	read.getline(str, 20);
	cout << str << endl;
	read.close();
	return 0;
}*/

/*void main()
{
	//ofstream out("f:\\sgyt.txt", ofstream::out);  这种是直接刷新整个文件
	ofstream out("f:\\sgyt.txt", ofstream::app);//这种是在文件后面追加
	if (out.fail())
	{
		cout << "打开失败" << endl;
		exit(0);
	}
	out << "ssssss";
	out.close();
	system("pause");

}*/

