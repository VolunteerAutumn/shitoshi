#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
	string name;
	string type;
	int sides;
public:
	Shape() : name(""), type(""), sides(0) {}
	Shape(string n, string t, int s) : name(n), type(t), sides(s) {}
	virtual void Show()
	{
		cout << "Name: " << name << endl;
		cout << "Type: " << type << endl;
		cout << "Sides: " << sides << endl;
	}
	virtual float GetArea() = 0;
	virtual ~Shape() {}
};

// ====== CLASSES ======
class Rectangle : public Shape
{
private:
	float a;
	float b;
public:
	Rectangle(string n, float a, float b) : Shape(n, "Rectangle", 4), a(a), b(b) {
	}
	float GetArea() override { return a * b; }
	void Show() override
	{
		Shape::Show();
		cout << "Side A: " << a << endl;
		cout << "Side B: " << b << endl;
		cout << "Area: " << GetArea() << endl;
	}
	~Rectangle()
	{

	}
};

class Circle : public Shape
{
private:
	float r;
public:
	Circle(string n, float r) : Shape(n, "Circle", 0), r(r) {}
	float GetArea() override { return 3.14 * r * r; }
	void Show() override
	{
		Shape::Show();
		cout << "Radius: " << r << endl;
		cout << "Area: " << GetArea() << endl;
	}
	~Circle()
	{
	}
};

class RightTriangle : public Shape
{
private:
	float a;
	float b;
public:
	RightTriangle(string n, float a, float b) : Shape(n, "Right Triangle", 3), a(a), b(b) {}
	float GetArea() override { return (a * b) / 2; }
	void Show() override
	{
		Shape::Show();
		cout << "Side A: " << a << endl;
		cout << "Side B: " << b << endl;
		cout << "Area: " << GetArea() << endl;
	}
	~RightTriangle()
	{
	}
};

class Triangle : public Shape
{
private:
	float a;
	float b;
	float c;
public:
	Triangle(string n, float a, float b, float c) : Shape(n, "Triangle", 3), a(a), b(b), c(c) {}
	float GetArea() override
	{
		float p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	void Show() override
	{
		Shape::Show();
		cout << "Side A: " << a << endl;
		cout << "Side B: " << b << endl;
		cout << "Side C: " << c << endl;
		cout << "Area: " << GetArea() << endl;
	}
	~Triangle()
	{
	}
};

class Trapezium : public Shape
{
private:
	float base1;
	float base2;
	float side1;
	float side2;
public:
	Trapezium(string n, float base1, float base2, float side1, float side2) : Shape(n, "Trapezium", 4), base1(base1), base2(base2), side1(side1), side2(side2) {}
	float GetArea() override { 
		int height = sqrt(pow(side1, 2) - pow((pow(base2 - base1, 2) + pow(side1, 2) - pow(side2, 2)) / (2 * (base2 - base1)), 2));
		return ((base1 + base2) / 2) * height;
	}
	void Show() override
	{
		Shape::Show();
		cout << "Base 1: " << base1 << endl;
		cout << "Base 2: " << base2 << endl;
		cout << "Side 1: " << side1 << endl;
		cout << "Side 2: " << side2 << endl;
		cout << "Area: " << GetArea() << endl;
	}
	~Trapezium()
	{
	}
};

void TestShape(Shape* shape)
{
	shape->Show();
	cout << endl;
}

int main()
{
	Shape* shapes[5];
	shapes[0] = new Rectangle("ABCD", 5, 3);
	shapes[1] = new Circle("O", 4);
	shapes[2] = new RightTriangle("PQR", 3, 4);
	shapes[3] = new Triangle("XYZ", 3, 4, 5);
	shapes[4] = new Trapezium("EFGH", 3, 5, 4, 4);

	for (int i = 0; i < 5; i++)
	{
		TestShape(shapes[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		delete shapes[i];
	}
}
