#include<iostream>
#include<string>
using namespace std;

/*class NewClass
{
public:
	NewClass() = default;
	NewClass(string &s) :s(s) 
	{
		cout << "��������" << endl;
	};
	//new ��ֵ
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

	//���ǵ�һ�����
	Base* base2 = new Dervied();
	if (Dervied *der2 = dynamic_cast<Dervied*>(base2))
	{
		cout << "��һ�����ת���ɹ�" << endl;
		der2->Show();
		cout << endl;
	}
	//���ǵڶ������
	Base * base1 = new Base;
	if (Dervied *der1 = dynamic_cast<Dervied*>(base1))
	{
		cout << "�ڶ������ת���ɹ�" << endl;
		der1->Show();
	}
	else
	{
		cout << "�ڶ������ת��ʧ��" << endl;
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
	//��ͨ��ֵ����
	if (typeid(base) != typeid(der)) 
	{
		cout << "��һ" << endl;
		cout << typeid(base).name() << endl;
		cout << typeid(der).name() << endl;
	}

	
	Dervied* der1 = new Dervied();
	Base* base1 = der1;
	if (typeid(*base1) == typeid(*der1))
	{

		cout << "������ʱ������������һ��" << endl;
		cout << typeid(*base1).name() << endl;
		cout << typeid(*der1).name() << endl;
	}
	else {
		//cout << "������ʱ������������" << endl;
		//cout << typeid(*base1).name() << endl;
		//cout << typeid(*der1).name() << endl;
	}

	//ָ������
	if (typeid(base1) == typeid(der1)) 
	{
		//cout << "������ȷ" << endl;
		//cout << typeid(base1).name() << endl;
		//cout << typeid(der1).name() << endl;
	}
	else 
	{
		cout << "base1ָ�벻ָ��der1��ָ��" << endl;
		cout << typeid(base1).name() << endl;
		cout << typeid(der1).name() << endl;
	}


	if (typeid(base1) == typeid(Dervied))
	{
		//baseָ��Dervied
		//cout << "����" << endl;
		//cout << typeid(Dervied).name() << endl;
		//cout << typeid(base1).name() << endl;
	}
	else {
		cout << "base1����ָ��ָ��" << endl;
		cout << typeid(Dervied).name() << endl;
		cout << typeid(base1).name() << endl;
	}


	if (typeid(*base1) == typeid(Dervied))
	{
		//baseָ��Dervied
		cout << "������ȷ" << endl;
		cout << typeid(Dervied).name() << endl;
		cout << typeid(*base1).name() << endl;
	}
	return 0;
}*/



//type_info��
/*int main()
{
	Dervied* der1 = new Dervied();
	Base* base1 = der1;
	const type_info &k =  typeid(base1);
	cout << k.name() << endl;
	return 0;
}*/


//ö����
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
	//һ��ҪΪ��̬����
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
	//pdata����ָ��һ���������ǳ�����Screen�����string��Ա��ֻ�ܶ�ȡ��Ա������д���Ա
	//const string Screen::*pdata;
	//pdata = &Screen::contents;
	//����ֱ��auto padta = &Screen::contents;
	//auto sl = myScreen.*pdata;//.*  ������pdata�Ի��myScreen�����contents��Ա
	//cout << "����.*�����ĳ�Աָ��" << sl << endl;
	//auto kl = pScreen->*pdata;//->*������pdata�Ի��pScreen��ָ�����contents��Ա
	//cout << "ָ��->*�����ĳ�Աָ��" << kl << endl;

	//���ݳ�Աָ��ָ����
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

//��Ա����ָ��
/*int main() 
{
	string s = "ssss";
	Screen myScreen(s);
	myScreen.set(2, 4);
	Screen *pScreen =& myScreen;
	//��Ա����ָ��
	int (Screen::*pf)()  const= &Screen::getheight;
	auto k =  (myScreen.*pf)();
	cout << k << endl;
	//�������ĳ�Ա����ָ��
	using  Act = void (Screen::*)(int h, int k);
	Act  act= &Screen::seth;
	(myScreen.*act)(3, 8);
	cout << myScreen.getheight() << endl;
	return 0;
}*/


//����Ա���������ɵ��ö���
#include<functional>
/*int main() 
{
	auto fp = &string::empty;
	string s;
	if ((s.*fp)()) {
		cout << "null" << endl;
	};

	//ʹ��function����һ���ɵ��õĶ���
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
	static string sl;//ֱ�ӷ��ʾ�̬��Ա
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

//ʹ��union���͵Ķ���ֻ��һ����Ա���ó�Ա�����Ϳ�����һ�������е�����һ��
/*union Token 
{
	//Ĭ�������Ա�ǹ��еģ�structһ����
	char cval;
	int ival;
	double dval;
};

int main()
{
	Token first_token = { 'a'};//��ʼ��cval��Ա
	Token last_token;//δ��ʼ����Token
	Token *pt = new Token;//ָ��һ��δ��ʼ����Token�����ָ��
	last_token.cval = 'z';//ͨ�����ʷ���ֵ
	pt->dval = 2.3;
	pt->ival = 4;
	cout << pt->dval << endl;
	cout << pt->ival << endl;
	return 0;
}*/

//����ת��
#include"dynamicDemo.h"
char st[] = "dwdw";

