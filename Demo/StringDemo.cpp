#include<iostream>
#include<string>
/*int main()
{
	std::cout << "\tHi\n" << std::endl;
	std::cout << "���" << "\n" << "����" << std::endl;
	return 0;
}*/

/*int main()
{
	extern long double Id = 3.1415926;
	long double a{ Id }, b = { Id };
	long double c{ Id }, d = Id;
	std::cout << "a:" << a << "b:" << b << "c:" << c << "d:" << d << std::endl;
	return 0;
}*/
/*int reused = 42;
int main()
{
	int unique = 0;
	std::cout << reused << ":" << unique << std::endl;
	int reused = 0;
	std::cout << reused << ":" << unique << std::endl;
	std::cout << ::reused << ":" << unique << std::endl;
	return 0;
}*/

/*int main()
{
	int i = 1024;
	int r = i;
	i = i - 24;
	std::cout << "i:" << i << "\n" << "r:" << r << std::endl;//i:1000,r:1024
	return 0;
}*/

/*int main()
{
	int ival = 42;
	int *p = &ival;
	std::cout << p << std::endl;
	return 0;
}*/

/*int main()
{
	int i = 42;
	int *pi = 0;
	int *pi2 = &i;
	int *pi3;
	pi3 = pi2;
	std::cout << "*pi:" << *pi << std::endl;
	std::cout << "*pi2:" << *pi2 << std::endl;
	std::cout << "*pi3:" << *pi3 << std::endl;
	std::cout << "pi3" << pi3 << std::endl;
	pi2 = 0;
	std::cout << "..............................pi2=0"<<std::endl;
	std::cout << "*pi:" << *pi << "\n" << "*pi2:" << *pi2 << "\n" << "*pi3:" << *pi3 << "\n" << "pi3" << pi3 << std::endl;
	return 0;
}*/

/*int main()
{
	double obj = 3.14, *pd = &obj;
	//void*���Խ����κ����ͣ�
	void *pv = &obj;
	std::cout << "pv:" << pv << std::endl;
	std::cout << "pd:" << pd << std::endl;
	std::cout << "*pd:" << *pd << std::endl;
	std::cout << "&obj" << &obj << std::endl;
	double *k = pd;
	std::cout << "k:" << k << std::endl;
	std::cout << "*k:" << *k << std::endl;
	//�����void*ֻҪǿת�ͺ�
	double *c = (double*)pv;
	std::cout << "c" << c << std::endl;
	std::cout << "*c" << *c << std::endl;
	return 0;
}*/

/*int main()
{
	int ival = 1024;
	int *pi = &ival;//piָ��һ��int�͵���
	int **ppi = &pi;//ppiָ��һ��int �͵�ָ��

	std::cout << "The value of ival\n"
		<< "direct value:" << ival << "\n"
		<< "indirect value" << *pi << "\n"
		<< "doubly indirect value" << **ppi << std::endl;
	return 0;
}*/

/*int main()
{
	int i = 42;
	int *p;//p��һ��ָ��
	int *&r = p;//r��ָ��p������
	std::cout << r << "::" << p << std::endl;
	std::cout << *&r << "::" << *p << std::endl;
	r = &i;//r������һ��ָ�룬��˸�r��ֵ��&i������pָ����i
	*r = 0;//������r�õ�i��Ҳ����pָ��Ķ��󣬽�i��ֵ��Ϊ0
	std::cout << *&r << "::" << *p << std::endl;
	return 0;
}*/

/*int main()
{
	int k = 3;
	int &c = k;
	std::cout << "c:" << c << "k:" << k << std::endl;
	c = 3 - 1;
	std::cout << "c:" << c << "k:" << k << std::endl;
	return 0;
}*/

//Const

/*int main()
{
	int i = 42;
	int &k = i;
	const int &ci = i;
	std::cout << "i:" << i << "ci:" << ci << "k:"<<k<<std::endl;
	i = i - 4;
	std::cout << "i:" << i << "ci:" << ci << "k:" << k << std::endl;
	return 0;

}*/

/*using std::string;
int main()
{
	string s1;
	string s2 = s1;
	string s3 = "hiya";
	string s4(10, 'c');


	return 0;
}*/

/*using std::string;
using namespace std;
int main()
{
	string str = "sky hellow";
	if (str.empty()) {
		cout << str.size() << endl;
	}
	cout << "........................................................." << endl;
	for (auto c : str) {
		cout << c << endl;
	}
	return 0;
}*/

/*using namespace std;
int main() {
	string s("Hello World!!!");
	//punct_cnt �����ͺ�s.size�ķ�������һ�����μ�2.5.3��
	decltype(s.size()) punct_cnt = 0;
	for (auto c : s) {
		if (ispunct(c))
			++punct_cnt;
	}
	cout << punct_cnt << "punctuation characters in" << s << endl;	
	return 0;
}*/
/*using std::string;
using namespace std;
int main()
{
	string s("Hello World!!!");
	for (auto &c : s) {
		cout << c << endl;
		c = toupper(c);
	}
	cout << s << endl;
	return 0;
}*/
/*using std::string;
using namespace std;
int main()
{
	const string hexdigits = "0123456789ABCDEF";
	cout << "Enter a series of numbers between 0 and 15"
		<< "separated by space .hit enter when finished"
		<< endl;
	string result;
	string::size_type n;
	while (cin >> n) {
		if (n < hexdigits.size()) {
			result += hexdigits[n];
		}
		
	}
	cout << "you hex number is:" << result << endl;
	return 0;
}*/
/*#include<vector>
using namespace std;
using std::string;
int main()
{
	vector<string> v1 = { "a","an","the" };
	vector<string> v2 = { "c","k" };
	vector<int>ivec(10, -1);//10�����͵�Ԫ�أ�ÿ��������ʼ��Ϊ-1
	vector<string> svec(10, "h1");//10��string����ΪԪ�أ�
	vector<int> iv(10);//10��Ԫ�أ�ÿ������ʼ��Ϊ0
	vector<string> sv(10);//10��Ԫ�أ�ÿ�����ǿ�string����
	return 0;
}*/

/*(#include<vector>
using namespace std;
using std::string;
int main() 
{
	string word;
	vector<string> text(10);
	while (cin >> word) {
		text.push_back(word);
	}
	for (int i = 1; i < text.size(); i++) {
		cout << text[i] << endl;
	}
	return 0;
}
*/
/*#include<vector>
using namespace std;
using std::string;
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	for (auto &c : v) {
		c *= c;
	}
	for (auto c : v) {
		cout << c << endl;
	}
	return 0;
}*/
