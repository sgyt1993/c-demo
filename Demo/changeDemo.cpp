#include<iostream>
#include<string>
using namespace std;
class c {
public:
	void change() const;
private:
	mutable int k;
};
void c::change() const 
{
	k++;//����û��mutable���Ǵ����
}