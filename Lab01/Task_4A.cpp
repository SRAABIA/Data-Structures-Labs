#include <iostream>
using namespace std;
class Shape
{
protected:
	int length, width;

public:
	Shape()
	{
	}
	Shape(int l, int w)
	{
		length = l;
		width = w;
	}
};
class Rectangle : public Shape
{
public:
	Rectangle()
	{
	}
	Rectangle(int l, int w) : Shape(l, w)
	{
	}
	float Area()
	{
		return length * width;
	}
};
class Triangle : public Shape
{
public:
	Triangle()
	{
	}
	Triangle(int l, int w) : Shape(l, w)
	{
	}
	float Area()
	{
		return (length * width) / 2;
	}
};
int main()
{
	Triangle tt(2, 2);
	cout << "Area of triangle: " << tt.Area() << endl;
	Rectangle rr(9.1, 3);
	cout << "Area of Rectangle: " << rr.Area() << endl;
}
