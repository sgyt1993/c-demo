#include<iostream>
#include<vector>
#include<string>
using namespace std;
using std::string;
/*int main()
{
	string s("some string");
	if (s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
		cout << *it << endl;
	}
}*/
/*int main()
{
	string s("some string");
	for (auto it = s.begin(); it != s.end() &&  !isspace(*it); it++) {
		*it = toupper(*it);
	};
	cout << s[1] << endl;
	return 0;
}*/
/*int main()
{
	string text = "s is mee";
	auto beg = text.begin(), end = text.end();
	auto mid = text.begin() + (end - beg) / 2;//��ʼ��״̬�µ��м��
	while (mid != end && *mid != sought) {
		if (sought < *mid) {
			end = mid;
		}
		else {
			beg = mid + 1;
		}
		mid = beg + (end - beg) / 2;
	}

}*/

/*int main()
{
	int arr[10];
	int *parr[42];
	int a1[] = { 1,2,3 };
	int a3[5] = {1,2,3};//�ȼ���a3[] = {1,2,3,0,0}
	string a4[3] = { "hi","bye" };//�ȼ���a4[] = {"hi","bye",""}
	char a5[] = "aaaaaaa";
	cout << a5[2] << endl;
	return 0;
}*/

/*int main()
{
	string nums[] = { "one","two","three" };
	string *p = &nums[2];
	cout << *p << endl;//three
	string *p2 = nums;//�ȼ���p2 = &nums[0]
	cout << *p2 << endl;//one
	return 0;
}*/

/*int main()
{
	int ia[] = { 0,1,23,3,4,5 };
	auto ia2(ia);//ia2��һ�����ε�ָ�룬ָ��ia[0]
	cout << *ia2 << endl;
}*/

/*int main()
{
	int arr[] = { 1,2,3,4,5 };
	int *p = &arr[0];
	++p;//pָ��arr[1]
	cout << *p << endl;//2
	return 0;
}*/

/*int main()
{
	int ia[] = { 0,1,2,3,4,5,6 };
	int *beg = begin(ia);//ָ��ia����Ԫ�ص�ָ��
	cout << *beg << endl;//0
	int *last = end(ia);//ָ��iaβԪ�ص���һλ�õ�ָ�룻
	last--;
	cout << *last << endl;//6
	return 0;
}*/

/*int main()
{
	int ia[] = { 0,2,4,6,8 };
	int *p = &ia[2];
	int j = p[1];//p[1]�ȼ���*��p+1�����͵���ia[3]��Ԫ��
	int k = p[-2];//p[-2]�ȼ���*��p-2��,�͵���ia[0]��Ԫ��
	return 0;
}*/

/*int main()
{
	char ca[] = { 'c','+','+' };
	cout << strlen(ca) << endl;
}*/

/*int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	int ia1[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };//�����ʼ����iaһ����Ч��
	int ic[3][4] = { { 0 },{ 4 },{ 8 } };//��ʾ�ĳ�ʼ��ÿ�е��׸�Ԫ��
	int ic1[3][4] = { 0,3,6,9 };//��ʾ�ĳ�ʼ����1�У�����Ԫ��ִ�г�ʼ��
	return 0;
}*/

/*int main()
{
	int ia[3][4] = {
		{0,1,2,3},
		{4,5,6,7},
		{8,9,10,11}
	};
	for (const auto &row : ia) {
		for (auto co1 : row) {
			cout << co1 << endl;
		}
	}

	return 0;

}*/

/*int main()
{
	
	return 0;
}*/

/*#include<set>
#include<map>
int main()
{
	//set<string> se{ "a","c","v","wdaw","awd","www" };
	map<string, string> mp{ {"s","a"} ,{"b","c"} };
	
	cout << mp["s"] << endl;
	return 0;
}*/


