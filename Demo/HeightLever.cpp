#include<iostream>
#include<string>
#include<tuple>
#include<vector>
#include<list>
using namespace std;
//tuple类型
/*+int main()
{
	//tuple快速而随意的数据结构
	tuple<size_t, size_t, size_t> three1 = { 1,2,3 };
	tuple<size_t, size_t, size_t> three{1,2,3};
	tuple<string, vector<double>, int, list<int>> someVal("constants", { 2.31,12.31 }, 2, { 12,12,3 });

	//使用make_tuple
	//auto item = make_tuple("wdwd", 123, 12, 12.3, {1,2,1});//貌似不能放数组
	auto item= make_tuple("wdwd", 123, 12, 12.3);

	//访问tuple的成员
	auto first = get<0>(three1);
	cout << first << endl;//1
	get<0>(three1) = 2;
	cout << get<0>(three1) << endl;//2
	auto listd = get<1>(someVal);
	cout << listd[0] << endl;// 2.31
	return 0;
}*/

//辅助类来查询tuple的成员数量和类型
/*int main() 
{
	tuple<int, vector<string>, double> t1 = { 12,{"wdw","dd","three"},3.15 };
	typedef decltype(t1) trans;//trans是item的类型
	//返回trans类型对象中成员的数量
	size_t st = tuple_size<trans>::value;
	cout << st << endl;//3;
	//取出t1元素的第0个元素的类型
	tuple_element<0, decltype(t1)>::type cnt = 2;
	cout << get<0>(t1) << endl;//12没有改变t1
	return 0;
}*/


/*int main()
{
	tuple<string, string> p1("1","2");
	tuple<size_t, size_t> p2(1, 2);
	//bool p = p1 < p2;错误，不同类型不能比较
	tuple<size_t, size_t, size_t> p3(1, 2, 3);
	//bool p = p2 > p3;成员数量不同
	tuple<size_t, size_t> p4(0, 4);
	tuple<size_t, size_t> p5(3, 4);
	cout << (p4 > p2) << endl;//0
	cout << (p5> p2) << endl;//1 要全部大于前面中的参数，才是true
	return 0;
}*/
/*#include <algorithm>
class Sales_data {

};
//matches的三个成员：一家书店的索引和两个指向书店vector中元素的vector
typedef tuple<
	vector<Sales_data>::size_type,
	vector<Sales_data>::const_iterator,
	vector<Sales_data>::const_iterator
> matches;
//fils保存每家书店的销售记录,
//findBook返回一个vector，每家销售了给定书籍的书店在其中都有一项
vector<matches> findBook(const vector<vector<Sales_data>> &files, const string &book)
{
	vector<matches> ret;
	for (auto iter = files.cbegin(); iter != files.cend(); iter++) 
	{
		//查找相同ISBN的Sales_data范围
		auto found = equal_range(iter->cbegin(), iter->cend(), book, [](string f, string b) {return f == b; });
		if (found.first != found.second)
			ret.push_back(make_tuple(iter - files.cbegin(), found.first, found.second));
	}
	return ret;//找到的所有匹配的结果
}*/

//使用tuple返回多个值
/*int main()
{
	vector<int> k = { 12,1,3,1,23,1,3,12,543,42,34,23,42,33,2 };
	cout << *k.cbegin() << endl;//12
	vector<int>::size_type size = (k.begin() + 5) - k.begin();//这种方式计算迭代器中当前的长度
	cout << size << endl;
	return 0;
}*/
#include<bitset>
//bitset类型
/*int main() 
{
	bitset<32> b1("1010");
	return 0;
}*/

#include<regex>
/*int main()
{
	string pattern{ "\\d{3}-\\d{8}|\\d{4}-\\d{7}" };//电话号码
	regex rs(pattern);
	string tel = "0319-9876543";
	bool k = regex_match(tel, rs);
	cout << k << endl;
	return 0;
}*/


/*int main()
{
	regex r("abcd", regex::icase);
	string str = "ABCd";
	bool flag = regex_match(str, r);
	cout << flag << endl;
	return 0;
}*/


/*int main()
{
	regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
	cmatch results;//匹配结果string 输出
	if (regex_search("myfile.cc", results, r))//这里char
		cout << results.str() << endl;

	smatch results1;
	string vc{ "myfile.cc" };
	if (regex_search(vc, results1, r))//这里是string
		cout << results1.str() << endl;
	return 0;
}*/


//匹配与regex迭代器类型sregex_iterator
/*int main()
{
	//查找一个字符不是c的字符串ei
	string pattern("[^c]ei");
	//包含所有pattern的所有单词
	pattern = "[[:alnum:]]*" + pattern + "[[:alnum:]]*";
	regex r(pattern, regex::icase);
	string file = "receipt freind theif receive";
	for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it)
	{
		auto pos = it->prefix().str();//前面一个单词
		auto fix = it->suffix().str();//后面所有单词
		cout << pos << endl;
		cout << it->str() << endl;
		cout << fix << endl;
	}
	//friend 
	//theif
	return 0;
}*/

/*int main() 
{
	regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);//myfile.cc，myfile，cc
	regex r1("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);//myfile.cc，cc
	regex r2("[[:alnum:]]+\\.cpp|cxx|cc$", regex::icase);//cc
	string vc{ "myfile.cc" };
	smatch results;//匹配结果string 输出
	for (sregex_iterator it(vc.begin(), vc.end(), r2), it_end; it != it_end; it++) 
	{
		int i = 0;
		auto k = *it;
		for (auto cit = k.begin(); cit != k.end(); cit++) 
		{
			cout << cit->str() << endl;//子正则函数
		}
	}
	return 0;
}*/


//regex_replace
 
/*int main()
{
	//问号(?)表示之前的可以选择
	std::string phone =
		"(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
	regex r(phone);
	//代替
	string fmt("$2.$5.$7");
	string number("(908)555-1800");
	bool k = regex_match(number, r);
	cout << k << endl;
	cout << regex_replace(number, r, fmt) << std::endl;

	string file("Caroline (201)555-2368 862-55-0123");
	cout << regex_replace(file, r, fmt) << std::endl;
	cout << regex_replace(file, r, fmt,regex_constants::format_no_copy) <<endl;
}*/

/*int main() 
{
	string str = "1994 is my birth year";
	regex r("\\d{4}");
	string fmt = "19";
	string replace1 = regex_replace(str, r, fmt);//拿到正则到的数据进行修改
	cout << replace1 << endl;//19 is my birth year
	string replace2 = regex_replace(str, r, fmt,regex_constants::format_no_copy);//不显示不匹配的值
	cout << replace2 << endl;//19
	return 0;
}*/

/*int main() 
{
	string phone = "(\\()?(\\d{3})(\\))?(\\d{3})([-.])?(\\d{4})";
	regex r(phone);
	smatch m;
	string s = "(201)555-2368 862-555-123";
	string fmt = "$2.$5.$7";
	cout<<regex_replace(s, r, fmt)<<endl;
	return 0;
}*/
#include<random>
#include<set>
//随机数
/*int main() 
{
	default_random_engine e;
	set<unsigned> s;
	for (int i = 0; s.size()< 30; i++) 
	{
		s.insert(e());
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) 
	{
		cout << *iter << endl;
	}
	return 0;
}*/

/*int main() 
{
	uniform_int_distribution<int> u(0, 255);
	default_random_engine e;
	set<int> k; 
	for (int i = 0; k.size() < 20; i++) 
	{
		k.insert(u(e));
	}
	for (auto iter = k.begin(); iter != k.end(); iter++)
	{
		cout << *iter << endl;
	}
	return 0;
}*/

//随机数种子
/*int main()
{
	default_random_engine u1(200001);
	default_random_engine u2;
	u2.seed(200001);
	default_random_engine u3;
	//u1和u2相同的种子，那么生成的随机数相同
	for (int i = 0; i < 20; i++)
	{
		cout << u1() << endl;
	}
	cout << "........................" << endl;
	for (int i = 0; i < 20; i++)
	{
		cout << u2() << endl;
	}
	return 0;
}*/


//其他随机数分步(生产小数随机数)
/*int main()
{
	default_random_engine e;
	uniform_real_distribution<double> u(0, 1);
	for (int i = 0; i < 20; i++) {
		cout<<u(e)<<endl;
	}
}*/

//生产随机的bool值
/*int main() 
{
	default_random_engine e;
	bernoulli_distribution b;//默认50%的机会
	for (int i = 0; i < 20; i++) {
		bool flag = b(e);
		cout << flag << endl;
	}
}*/

#include<fstream>
#include<sstream>
#include<string>
//输出bool值时，默认是1,0，变成true,false
/*int main() 
{
	ofstream f("e:/sgyt.txt",ios::out);
	if (f.fail()) 
	{
		cout << "打开失败" << endl;
	}
	f << "default bool values:" << true << "   " << false ;//default bool values:1   0
	f << "\nalphe bool values:" << boolalpha << true << "    " << false ;//alphe bool values:true    false
	f.close();
	return 0;
}*/

//输出定制
/*int main() 
{

	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "打开失败" << endl;
	}
	f << showbase;//打印整型时显示进制
	f << "default:" << 20 << "   " << 1024 <<endl;
	f << "octal:" << oct << 20 << "   " << 1024 << endl;
	f<<"hex:"<<hex<< 20 << "   " << 1024 << endl;
	f<<"decimal:"<<dec << 20 << "   " << 1024 << endl;
	f.close();
	return 0;
}*/
/*
default:20   1024
octal:24   2000
hex : 14   400
decimal : 20   1024*/


//指定打印精度
//通过调用io对象precision成员或使用setprecision操纵符来改变精度
#include<iomanip>
/*int main() 
{
	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "打开失败" << endl;
	}
	//cout.precision返回当前精度值
	f << "Precision:" << f.precision() << ",Value:" << sqrt(2.0) << endl;
	//cout.precision(12)将打印精度设置为12位数字
	f.precision(12);
	f << "Precision" << f.precision() << ",Value:" << sqrt(2.0) << endl;
	//使用setprecision操纵符
	f<<setprecision(3);
	f << "Precision" << f.precision() << ",Value:" << sqrt(2.0) << endl;
	f.close();
	return 0;
}*/
/*
Precision:6,Value:1.41421
Precision12,Value:1.41421356237
Precision3,Value:1.41
*/


/*int  main() 
{
	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "打开失败" << endl;
	}
	f << 10.0 << endl;
	f << showpoint << 10.0 << noshowpoint << "    " << 10.0 << endl;
	//10
	//10.0000    10
	return 0;
}*/


//小数的操作符
/*int main() 
{
	ofstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "打开失败" << endl;
	}
	int i = -16;
	double d = 3.14159;
	//补白第一列，使用输出中最小12个位置
	f << "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n";
	//补白第一列，左对齐所有列
	f << left
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n"
		<< right;//恢复正常对齐
	//补白第一列，右对齐所有列
	f << right
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n";
	//补白第一列，但补在域的内部
	f <<internal
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n";
	//补白第一列，用#作为补白字符
	f << setfill('#')
		<< "i:" << setw(12) << i << "next col" << "\n"
		<< "d:" << setw(12) << d << "next col" << "\n"
		<< setfill(' ');
	
	i:         -16next col
d:     3.14159next col
i:-16         next col
d:3.14159     next col
i:         -16next col
d:     3.14159next col
i:-         16next col
d:     3.14159next col
i:-#########16next col
d:#####3.14159next col

	
	return 0;
}*/

//未格式化输出/输入操作
//sell,tell支持随机访问
/*int main() 
{
	ifstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "打开失败" << endl;
	}
	//当前的位置
	streampos pos = f.tellg();
	if (ios::beg == pos) 
	{
		cout << "the file is beginning" << endl;
	}
	return 0;
}*/

/*int main() 
{
	ifstream f("e:/sgyt.txt", ios::out);
	if (f.fail())
	{
		cout << "打开失败" << endl;
	}
	string line;
	getline(f, line);
	//拿到当前的pos点
	streampos pos = f.tellg();
	f.close();
	//重新开一个读入流
	ifstream g("e:/sgyt.txt", ios::out);
	if (g.fail())
	{
		cout << "打开失败" << endl;
	}
	//将g读入流标记到刚才读取的位置
	g.seekg(pos);
	getline(g, line);//这里取到的就是本文件的第二行文件
	cout << line << endl;
	return 0;
}*/

//二进制读取文件，并输出
/*int  main() 
{
	ifstream read("e:/Explosion_4k.jpg", ios::binary);
	ofstream out("e:/tupian.jpg", ios::binary);
	if (out.fail()) 
	{
		string command;
		string path = "e:/tupian.jpg";
		command = "mkdir -p " + path;
		system(command.c_str());
	};
	int ch;//使用一个int,而不是char保存get()的返回值
	while ((ch = read.get()) != EOF) 
	{
		out.put(ch);
	}
	read.close();
	out.close();
	return 0;
}*/






