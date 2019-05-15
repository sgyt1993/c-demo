#include<iostream>
#include<string>
using namespace std;
using std::string;
class Point 
{
public:
	Point() = default;
	Point(double xx, double yy) {
		x = xx;
		y = yy;
	}
	void GetXY();
	friend double Distance(Point &a, Point &b);
private:
	double x, y;
};

void Point::GetXY() 
{
	cout << "(" << x << "," << y << ")" << endl;
}

double Distance(Point &a, Point &b) 
{
	double length;
	length = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));//�������������е�˽�г�Ա
	return length;
}

/*int main() {
	Point p1(3.0, 4.0),p2(6.0, 8.0);
	p1.GetXY();
	p2.GetXY();
	double d = Distance(p1, p2);//��Ԫ�����ĵ��÷�����ͬ��ͨ�����ĵ���һ������Ҫ���Ա������������
	cout << d << endl;
	system("pause");
	return 0;
}*/