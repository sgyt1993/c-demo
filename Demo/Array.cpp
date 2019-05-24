//动态数组
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
using  namespace std;

/*class A {
public:
	A() :k(0) {};
	A(int i) {
		this->k = i;
	}
	void show() { cout << k << endl; };
private:
	int k;
};

//初始化动态数组
void  construction() 
{
	int *pia = new int[10];//10个未初始化的int 
	int *pia2 = new int[10]();//10个值初始化为0的int
	string *psa = new string[10];//10个空的string
	string *psa2 = new string[10]();//10个空的string
	int  *pia3 = new int[10]{ 0,1,2,3,4,5 };
}

//删除动态数组
void deletedemo() {
	int  *pi = new int[10];
	delete[] pi;//必须用[]删除动态的数组
	
	unique_ptr<int[]> up(new int[10]);
	up.release();//自动回调用delete[]将其销毁
}

//allocator类
void demo()
{
	allocator<A> alloc;//定义一个可以分配的string的allocator对象
	A* k = alloc.allocate(10);//分配n个初始化的string内存，当然只是原始内存，为构造
	auto q = k;
	alloc.construct(k);//使用默认构造
	alloc.construct(k + 1, 2);
	alloc.construct(k + 3, 5);
	k->show();//0
	(k + 1)->show();//2
	(k + 2)->show();//随意一个地址值
	(k + 3)->show();//5
	

}

class TextQuery {
public:
	TextQuery();
	TextQuery(string str) {
		ifstream io(str, ios::app);
		int lineNum = 1;
		if (io.fail()) {
			cout << "文件打开失败" << endl;
			exit(0);
		}
		string line,word;//保存每一行的数据,每行中的数据
		while (getline(io, line)) {
			set<string> *s = new set<string>;
			istringstream rec(line);//把每一行数据保存到istringstream,
			while (rec >> word) {
				//循环中吧每个单词放到数组中
				s->insert(word);
			}
			mp.insert({ lineNum, *s });
			//删除s的空间
			delete s;
			lineNum++;
		}
		io.close();
	};
	void show();
	map<int, set<string>> getall() { return mp; };
	void check() {};
	vector<int> query(string s);
private:
	shared_ptr<ifstream> ki;
	vector<string> vc;
	map<int, set<string>>  mp;
};
//展现所有的读出的数据
void TextQuery::show() 
{
	for (auto m = mp.begin(); m != mp.end(); m++) {
		cout << m->first << endl;
		set<string> s = m->second;
		for (string st : s) {
			cout << st<<"     ";
		}
		cout << "\n";
	}
}
//查询这个字符在第几行
vector<int>  TextQuery::query(string str)
{
	vector<int> *vc = new vector<int>;
	for (auto m = mp.begin(); m != mp.end(); m++) {
		set<string> s = m->second;
		for (string st : s) {
			if (st == str) {
				vc->push_back(m->first);
				continue;
			}
		}
		
	}
	return *vc;
}

//文本查询程序
void  runQueryies() 
{
	//打印所有数据并在第几行
	//TextQuery *tx = new TextQuery("e:/sgyt.txt");
	//tx->show();
	//delete tx;
	//打印这个字在第几行‘
	TextQuery *tx = new TextQuery("e:/sgyt.txt");
	vector<int> vc = tx->query("ws");
	for (auto k : vc) {
		cout << k << endl;
	}
	delete tx;
}

//这个是书上的写的，对内存有了很好的管理
class QueryResult1;

class TextQuery1 {
public:
	using line_no = vector<string>::size_type;
	TextQuery1(ifstream&);
	QueryResult1 query(string&) const;
private:
	shared_ptr<vector<string>> file;//保存的输入文件
	map<string, shared_ptr<set<line_no>>> wm;//每个单词和它行号的集合
};

TextQuery1::TextQuery1(ifstream &is) : file(new vector<string>) {
	string text;
	while (getline(is, text))
	{
		file->push_back(text);//b保存文件中每一行
		int n = file->size() - 1;//保存此行文本
		istringstream line(text);
		string word;
		while (line >> word) //对行中每个单词
		{
			auto &lines = wm[word];//lines是一个shared_ptr
			if (!lines) //判断是否为空指针
			{
				lines.reset(new set<line_no>);//分配一个新的set
			}
			lines->insert(n);//将此行号插入set中
		}
	}
}*/

/*int main()
{
	runQueryies();
	return 0;
}*/
