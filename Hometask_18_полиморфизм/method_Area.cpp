

#include <iostream>
#include <cmath>

class Shape 
{
protected:
    std::string name;
public:
	Shape(std:: string name)
	{
		setName(name);
	}
    virtual double area() = 0;

	void setName( std:: string name)
	{
		this->name = name;
	}
	std::string& getName()
	{
		return name;
	}
};

class Triangle: public Shape
{
private:
	double length_a;
	double length_b;
	double length_c;
	double perimetr;
public:
	Triangle(double length_a, double length_b, double length_c, std::string name) : Shape ( name)
	{
		setArgumets(length_a, length_b, length_c);
	}
	void setArgumets(double length_a, double length_b, double length_c)
	{
		this->length_a = length_a;
		this->length_b = length_b;
		this->length_c = length_c;
		this->perimetr = length_a+ length_b+ length_c;
	}
	double area() override
	{
		double p = perimetr / 2.0;
		return double ( sqrt(p * (p - length_a) * (p - length_b) * (p - length_c)));
	}
};

class Rectangle: public Shape
{
private:
	double side_a;
	double side_b;
public:
	Rectangle(double side_a, double side_b, std::string name): Shape(name)
	{
		setArgumets(side_a, side_b);
	}
	void setArgumets(double side_a, double side_b)
	{
		this->side_a = side_a;
		this->side_b = side_b;
	}
	double area() override
	{
		return double(side_a * side_b);
	}
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double r, std::string name): Shape(name)
	{
		setArgumets(r);
	}
	void setArgumets(double r)
	{
		this->radius = r;
	}
	double area() override
	{
		return double(3.14 * radius * radius);
	}
};



int main()
{
	Shape* ShapeArray[3];
	ShapeArray[0] = new Triangle(12, 18, 11.5, "TriangleBlue");
	ShapeArray[1] = new Rectangle ( 10.0, 8.5, "RectangleRed");
	ShapeArray[2] = new Circle( 6.7, "CircleGreen");

	for (int i=0;i<3; i++ )
	{
		std::cout << ShapeArray[i]->getName()<<"\t square = " << ShapeArray[i]->area()<<"\n";
	}
   
}

