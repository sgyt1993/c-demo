#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;
/*int main()
{
	map<string, int> word;
	set<string> es = { "the","but","and","an","a" };
	map<string, string> ma = { {"jonce","18"},
												{"cd","20" },
												{"kd","202"} };
	return 0;
}*/


/*int main() 
{
	pair<string, string> pair1;
	pair1.first = "hehe";
	pair1.second = "awwd";
	cout << pair1.first << pair1.second << endl;
}*/

//map容器的遍历
/*int main()
{
	map<int, string> m1 = { {1,"sg"},{2,"ss"},{3,"wd"},{4,"wdw"},{6,"wdwdw"},{7,"wdwda"},{9,"wdwd"} };
	for (map<int, string>::iterator iter = m1.begin(); iter != m1.end(); iter++) {
		cout << iter->first << ":" << iter->second << endl;
	}
	return 0;
}*/

//set容器
/*int main()
{
	set<int> iset = { 0,1,2,3,4,5,6,7,7 };
	cout << iset.size()<< endl;
	for (auto iter = iset.begin(); iter != iset.end(); iter++) 
	{
		cout << *iter << endl;
	}
}*/


//插入
/*int main()
{
	map<string, string> m1 = { "123","121" };
	map<string, string> m2 = { "213","123" };
	m2.insert({ "1","wdwd" });
	//m2.insert(m1);这种错误
	m2.insert("2","wdwd");
	return 0;
}*/

//插入的返回值
/*int main()
{
	//单个插入
	map<string, string> m1;
	pair<string, string> pa1 = { "m2","kk" };
	pair<map<string, string>::iterator, bool> p1 = m1.insert(pa1);
	cout << p1.first->first << endl;
	cout << p1.second << endl;
	return 0;
}*/

/*int main()
{
	map<string, string> m1 = { {"1","dwdad"} };
	map<string, string> ma = { {"jonce","18"},{"cd","20" },{"kd","202"} };
	m1.insert(ma.begin(),ma.end());
	m1.insert({ "jonce","18" });
	for (auto k : m1) {
		cout << k.first << k.second << endl;//
	}
	return 0;
}*/


//删除容器
/*int main()
{
	map<string, string> ma = { {"jonce","18"},{"cd","20" },{"kd","202"} };
	ma.erase("jonce");
	ma.erase(ma.begin());
	ma.erase(ma.begin(), --ma.end());
	cout << ma.size() << endl;
	return 0;
}*/


//map下标操作
/*int main() 
{
	map<string, string> ma = { {"jonce","18"},{"cd","20" },{"kd","202"} };
	string k = ma["jonce"];
	ma["www"] = "mmmmm";
	cout << k << endl;
	cout << ma["www"] << endl;
	return 0;
}*/

//map 访问元素
/*int main() 
{
	map<string, string> ma = { {"jonce","18"},{"cd","20" },{"kd","202"} };
	auto k  = ma.find("wdw");
	bool flag = k == ma.end();
	cout << flag << endl; //1
	auto g = ma.find("jonce");
	if (g != ma.end()) {
		cout << g->first <<":"<<g->second<< endl;
	}
	return 0;
}*/
