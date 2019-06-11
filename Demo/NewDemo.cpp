#include<iostream>
#include<string>
using namespace std;

/*class NewClass
{
public:
	NewClass() = default;
	NewClass(string &s) :s(s) 
	{
		cout << "拷贝构造" << endl;
	};
	//new 赋值
	void *operator new(size_t size) 
	{
		cout << "new overload" << endl;
		if (void* men = malloc(size)) 
		{
			return men;
		}
		else 
		{
			throw bad_alloc();
		}
	}
	
	void operator delete(void* men) noexcept 
	{
		cout << "delete overload" << endl;
		free(men);
	}
private:
	string s;
};

int main() 
{
	string s = "ss";
	NewClass *nc = new NewClass(s);
	delete nc;
	return 0;
}*/

/*
	new overload
	delete overload
*/



/*int main()
{
	Base *base;
	Dervied* der = new Dervied();
	base = dynamic_cast<Base*>(der);
	base->Show();

	//这是第一种情况
	Base* base2 = new Dervied();
	if (Dervied *der2 = dynamic_cast<Dervied*>(base2))
	{
		cout << "第一种情况转换成功" << endl;
		der2->Show();
		cout << endl;
	}
	//这是第二种情况
	Base * base1 = new Base;
	if (Dervied *der1 = dynamic_cast<Dervied*>(base1))
	{
		cout << "第二种情况转换成功" << endl;
		der1->Show();
	}
	else
	{
		cout << "第二种情况转换失败" << endl;
	}
	delete(base2);
	delete(base1);
	return 0;
}*/


//typeid
/*int main()
{
	Base base;
	Dervied der;
	//普通赋值类型
	if (typeid(base) != typeid(der)) 
	{
		cout << "方一" << endl;
		cout << typeid(base).name() << endl;
		cout << typeid(der).name() << endl;
	}

	
	Dervied* der1 = new Dervied();
	Base* base1 = der1;
	if (typeid(*base1) == typeid(*der1))
	{

		cout << "在运行时两个对象类型一样" << endl;
		cout << typeid(*base1).name() << endl;
		cout << typeid(*der1).name() << endl;
	}
	else {
		//cout << "在运行时两个对象类型" << endl;
		//cout << typeid(*base1).name() << endl;
		//cout << typeid(*der1).name() << endl;
	}

	//指针类型
	if (typeid(base1) == typeid(der1)) 
	{
		//cout << "方二正确" << endl;
		//cout << typeid(base1).name() << endl;
		//cout << typeid(der1).name() << endl;
	}
	else 
	{
		cout << "base1指针不指向der1的指针" << endl;
		cout << typeid(base1).name() << endl;
		cout << typeid(der1).name() << endl;
	}


	if (typeid(base1) == typeid(Dervied))
	{
		//base指向Dervied
		//cout << "方三" << endl;
		//cout << typeid(Dervied).name() << endl;
		//cout << typeid(base1).name() << endl;
	}
	else {
		cout << "base1对象不指向指针" << endl;
		cout << typeid(Dervied).name() << endl;
		cout << typeid(base1).name() << endl;
	}


	if (typeid(*base1) == typeid(Dervied))
	{
		//base指向Dervied
		cout << "方四正确" << endl;
		cout << typeid(Dervied).name() << endl;
		cout << typeid(*base1).name() << endl;
	}
	return 0;
}*/



//type_info类
/*int main()
{
	Dervied* der1 = new Dervied();
	Base* base1 = der1;
	const type_info &k =  typeid(base1);
	cout << k.name() << endl;
	return 0;
}*/


//枚举类
/*int main() 
{
	enum Roster { Tom=1, Sharon, Bill, Teresa, John };
	cout << Tom << endl;
	cout << Sharon << endl;
	cout << Bill << endl;
	return 0;
}*/

class Screen 
{
public:
	Screen(string &s) :contents(s) {};
	int getcursor() const {
		return cursor;
	};
	int getheight() const {
		return height;
	};
	void set(int ht, int wd) {
		height = ht;
		width = wd;
	};
	void seth(int ht, int wd) {
		height = ht;
		width = wd;
	};
	//一定要为静态函数
	static const int Screen::*data() {
		return &Screen::height;
	}
	string contents;
private:
	int  cursor;
	int height, width;
};
/*int main()
{
	//string s = "ssss";
	//Screen myScreen(s);
	//Screen *pScreen =& myScreen;
	//pdata可以指向一个常量（非常量）Screen对象的string成员，只能读取成员，不能写入成员
	//const string Screen::*pdata;
	//pdata = &Screen::contents;
	//或者直接auto padta = &Screen::contents;
	//auto sl = myScreen.*pdata;//.*  解引用pdata以获得myScreen对象的contents成员
	//cout << "引用.*出来的成员指针" << sl << endl;
	//auto kl = pScreen->*pdata;//->*解引用pdata以获得pScreen所指对象的contents成员
	//cout << "指针->*出来的成员指针" << kl << endl;

	//数据成员指针指向函数
	string s = "ssss";
	Screen myScreen(s);
	myScreen.set(2, 3);
	Screen *pScreen =& myScreen;
	const int Screen::*pdata;
	pdata = Screen::data();
	auto si = myScreen.*pdata;
	cout << si << endl;
	auto ki = pScreen->*pdata;
	cout << ki << endl;
	return 0;
}*/

//成员函数指针
/*int main() 
{
	string s = "ssss";
	Screen myScreen(s);
	myScreen.set(2, 4);
	Screen *pScreen =& myScreen;
	//成员函数指针
	int (Screen::*pf)()  const= &Screen::getheight;
	auto k =  (myScreen.*pf)();
	cout << k << endl;
	//带参数的成员函数指针
	using  Act = void (Screen::*)(int h, int k);
	Act  act= &Screen::seth;
	(myScreen.*act)(3, 8);
	cout << myScreen.getheight() << endl;
	return 0;
}*/


//将成员函数用作可调用对象
#include<functional>
/*int main() 
{
	auto fp = &string::empty;
	string s;
	if ((s.*fp)()) {
		cout << "null" << endl;
	};

	//使用function生成一个可调用的对象
	function<bool (const string&)> fnc = &string::empty;
	string k;
	if (fnc(k)) 
	{
		cout << "null" << endl;
	}
	return 0;
}*/


/*class TextQuery 
{
public:
	class QueryResult;
	TextQuery() = default;
	TextQuery(string &s) :text(s) {};
	string getText()
	{
		return text;
	};
	void  fun() {
		cout << "TextQuery fun" << endl;
	}
	static string sl;//直接访问静态成员
	string sk;
private:
	string text;
};

class TextQuery ::QueryResult 
{
public:
	QueryResult() = default;
	QueryResult(string &s) :result(s) {};
	string getTextQuerySl()
	{
		return sl;
	};
private:
	string result;
};

int main() 
{
	
	return 0;

}*/

//union  

//使用union类型的对象只有一个成员，该成员的类型可能是一项类型中的任意一种
/*union Token 
{
	//默认情况成员是共有的（struct一样）
	char cval;
	int ival;
	double dval;
};

int main()
{
	Token first_token = { 'a'};//初始化cval成员
	Token last_token;//未初始化的Token
	Token *pt = new Token;//指向一个未初始化的Token对象的指针
	last_token.cval = 'z';//通过访问符赋值
	pt->dval = 2.3;
	pt->ival = 4;
	cout << pt->dval << endl;
	cout << pt->ival << endl;
	return 0;
}*/

//类型转换
#include"dynamicDemo.h"
char st[] = "dwdw";

