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
	length = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));//它可以引用类中的私有成员
	return length;
}

/*int main() {
	Point p1(3.0, 4.0),p2(6.0, 8.0);
	p1.GetXY();
	p2.GetXY();
	double d = Distance(p1, p2);//友元函数的调用方法，同普通函数的调用一样，不要像成员函数那样调用
	cout << d << endl;
	system("pause");
	return 0;
}*/