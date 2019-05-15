#include<iostream>
#include<string>
#include "StringDemo.h"
using namespace std;
using std::string;
class Point
{
public:
	Point & combine( Point &po);
	void setPoint(int x, int y);
	void printPoint();
private:
	int xPos;
	int yPos;
};
void Point::setPoint(int x, int y) {
	xPos = x;
	yPos = y;
}
void Point::printPoint() {
	cout << "x=" << xPos << endl;
	cout << "y=" << yPos << endl;
}
Point & Point::combine( Point &po) {
	po.setPoint(1, 3);
	return *this;
}
/*int main()
{
	Point m;
	m.combine(m);
	m.printPoint();
	return 0;
}*/





/*class Point
{
	public:
		Point() = default;
		void setPoint(int x, int y) { 
			xpos = x;
			ypos = y;
		}
		void printPoint(){
			cout << "x=" << xpos << endl;
			cout << "y=" << ypos << endl;
		}
	private:
		int xpos;
		int ypos;
};*/

/*int main()
{
	Point m;
	m.setPoint(10, 20);
	m.printPoint();
	return 0;
}*/



