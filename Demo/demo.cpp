#include<iostream>
#include<string>
#include<vector>
#include<iterator>
#include <algorithm> 
using namespace std;
//equal
/*int main()
{
	vector<string> vc;
	vc.push_back("aaa");
	vc.push_back("ssss");
	vc.push_back("nnn");
	vector<string> vc1;
	vc1.push_back("nnnn");
	vc1.push_back("mmm");
	vc1.push_back("kkk");
	bool flag = equal(vc.cbegin(), vc.cend(), vc1.cbegin());//注意vc1的容器数量大于等于vc的容器数量
	cout << flag << endl;
	return 0;
}*/

//fill
/*int main() 
{
	vector<string> vc;
	vc.push_back("aaa");
	vc.push_back("ssss");
	vc.push_back("nnn");
	fill(vc.begin(), vc.end(), "0");
	for (auto k = vc.begin(); k != vc.end(); k++) 
	{
		cout << *k << endl;
	}
	return 0;
}*/

//back_inserter 插入迭代器
/*int main()
{
	vector<int> vc;
	auto it = back_inserter(vc);
	*it = 42;
	for (auto k : vc) {
		cout << k << endl;
	}
	return 0;
}*/

//cope
/*int main()
{	
	vector<string> vc;
	vc.push_back("aaa");
	vc.push_back("ssss");
	vc.push_back("nnn");
	vector<string> vcope(7,"0");
	copy(vc.begin(), vc.end(), vcope.begin());//注意初始化容器必须要有长度
	for (auto k : vcope) 
	{
		cout << k << endl;//aaa,ssss,nnn,0,0,0,0
	}
	return 0;
}*/

/*int main()
{
	int  a[] = { 10,20,30,40,50,60,70 };
	int k[sizeof(a)/sizeof(*a)];
	copy(begin(a), end(a), k);
	for (auto z : k) 
	{
		cout << z << endl;
	}
	return 0;
}*/

//replace
/*int main()
{
	vector<string> vc;
	vc.push_back("aaa");
	vc.push_back("ssss");
	vc.push_back("nnn");
	vc.push_back("aaa");
	string old = "aaa";
	string newWord = "00";
	replace(vc.begin(), vc.end(),old, newWord);
	//replace(vc.begin(), vc.end(),"aaa","000");和上面的一样
	//replace(vc.begin(), vc.end(), "aaa", "00");这种是错误
	for (auto z : vc)
	{
		cout << z << endl;
	}
	return 0;
}*/

/*int main()
{
	vector<string> vc = { "fox","cd","aa","ss","gg","cd","kkk","eee" };
	//必须要去排序，想重复的值并排在一起才能使用unique
	sort(vc.begin(),vc.end());// { "fox","cd","cd","aa","ss","gg","kkk","eee","" };
	//返回指向不重复区域之后一个位置的迭代器（重复处的第一个位置的迭代器）
	auto end_unique = unique(vc.begin(), vc.end());
	//使用向量操作erase删除重复
	vc.erase(end_unique, vc.end());
	for (auto k : vc) 
	{
		cout << k << endl;// { "fox","cd","aa","ss","gg","kkk","eee","" };
	}
	return 0;
}*/

//向算法中传递函数
/*
bool isSorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

int main()
{
	vector<string> vc = { "a","sa","dsda","s","d","aw","da","sd","s","dawd","s","wdwd","sd","awd","sd","fw","fwffwd" };
	sort(vc.begin(), vc.end(), isSorter);//这种规则在main函数的上面
	for (auto k : vc) 
	{
		cout << k << endl;
	}
	gai();
	return 0;
}

void gai() {
	cout << "nihao" << endl;
}*/


//lambda表达式
/*int main()
{
	vector<string> vc = { "a","sa","dsda","s","d","aw","da","sd","s","dawd","s","wdwd","sd","awd","sd","fw","fwffwd" };
	sort(vc.begin(), vc.end(), [](const string &m1, const string &m2) 
	{
		return m1.size() < m2.size();
	});
	for (auto k : vc) 
	{
		cout << k << endl;
	}
	return 0;
}*/


//lambda 表达式
/*void biggies(vector<string> &word, vector<string>::size_type sz);
int main() 
{
	vector<string> vc = { "a","sa","dsda","s","d","aw","da","sd","s","dawd","s","wdwd","sd","awd","sd","fw","fwffwd" };
	biggies(vc, 2);
	return 0;
}
void biggies(vector<string> &word, vector<string>::size_type sz) 
{
	sort(word.begin(), word.end(), [](const string &m1, const string &m2) {
		return m1.size() < m2.size();
	});

	//获取size>su的元素的迭代器
	auto wc = find_if(word.begin(), word.end(), [sz](const string &m1) 
	{
		return m1.size() > sz;
	});

	//计算满足size>sz的数量
	auto  count = word.end() - wc;
	cout << count << endl;

	//输出大于sz的值
	for_each(wc, word.end(), [](const string &s) {cout << s << "   "; });
	cout << endl;
}*/


//lambda中的隐式捕获
/*int main()
{

	int data[] = { 1,2,3,4,5,6,6,2,2,2,563,5,234,2 };
	int border = 8;
	char space = ' ';
	auto f5 = [=](const int &i) {if (i > border) cout << i << "\t"; };//这个拿到的border=8
	auto f6 = [&](const int &i) {if (i > border)cout << i << "\t"; };//这个拿到的border=0
	auto f7 = [&, space](const int &i) {if (i > border)cout << i << space; };//这个拿到的border=0
	border = 0;
	for_each(begin(data), end(data), f5);
	cout << endl;
	for_each(begin(data), end(data), f6);
	cout << endl;
	for_each(begin(data), end(data), f7);
	cout << endl;
	return 0;
}*/

//lambda捕获值需要改变时 需要加mutable
/*int main()
{
	int data[] = { 1,2,3,4,5,6,6,2,2,2,563,5,234,2 };
	char space = ' ';
	int border = 6;
	auto f8 = [&, space](const int &m1)mutable {if (m1 > border) { space = '\t'; cout << m1 << space; } };
	for_each(begin(data), end(data), f8);
	return 0;
}*/

//lambda返回类型
/*int main()
{
	int data[] = { 1,2,3,4,5,6,6,2,2,2,563,5,234,2 };
	auto f9 = [](const int i) {if (i % 3) return i * 3; else return i;  };//ambda代码块中有多个return语句，并且还有if/else语句，但是编译器可以根据return语句推断出，其返回值应该是一个int类型，所以可以省略尾置返回类型。
	auto f10 = [](const int i) ->double
	{
		if (i % 3) return i * 3.0;
		else return i;
	};//但是，像下面这种形式，由于编译器在推断返回类型时发现了不一致，所以必须显式的指定
	transform(begin(data), end(data),begin(data), f9);
	int border = 0;
	auto f6 = [&](const int &i) {if (i > border)cout << i << "\t"; };//这个拿到的border=0
	for_each(begin(data), end(data), f6);//{3,6,3,12,15,6,6,6,6,6,1689,15,234,6}改变了容器中的每一个值
	return 0;
}*/

//参数绑定bind
/*#include<functional>
double myDivide(double x, double y) 
{
	return x / y;
}

int main()
{
	using namespace std::placeholders;
	auto k = bind(myDivide, _1, _2);
	cout << k(4.0, 2.0) << endl;
	return 0;
}*/


//istream_iterator  
/*#include<iterator>
int main()
{
	int value1, value2;
	cout << "Please,insert two values:";

	istream_iterator<int> eos;
	istream_iterator<int> iit(cin);//232 2
	cout << "eos:" << *eos;//0
	cout << "iit:" << *iit;//232
	cout << endl;
	if (iit != eos) {
		value1 = *iit;
	}
	++iit;
	if (iit != eos) {
		value2 = *iit;
	}
	cout << value1 << "*" << value2 << "=" << (value1*value2) << "\n";
	return 0;
}*/


//ostream_iterator
/*#include<iterator>
int main()
{
	vector<string> vc;
	vector<string> vk(20);
	for (int i = 0; i < 10; i++) 
	{
		vc.push_back("kk" );
	}
	copy(vc.begin(), vc.end(), vk.begin());
	for (auto k : vc) {
		cout << k<<"," ;
	}
	cout << endl;
	ostream_iterator<string> out_it(cout, ",");
	copy(vc.begin(), vc.end(), out_it);
	return 0;
}*/

//反向迭代器
/*int main()
{
	vector<int> vc = { 0,1,2,3,4,5,6,7,8,9 };
	//从尾元素到首元素的反向迭代
	for (auto r_itor = vc.crbegin(); r_itor != vc.crend(); r_itor++) {
		cout << *r_itor << endl;//9,8,7,6,5,4,3,2,1
	}
	return 0;
}*/


//泛型算法结构





