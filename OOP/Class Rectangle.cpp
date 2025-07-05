

// Написать класс "Прямоугольник" (Rectangle)
//-Поля: width(ширина), height(высота) - private
//- Конструкторы : по умолчанию(ширина = 0, высота = 0) и с параметрами
//- Методы :
//    setWidth(double w), setHeight(double h) - с проверкой на неотрицательность
//    getWidth(), getHeight()
//    getArea() - вычисление площади
//    getPerimeter() - вычисление периметра
//

#include <iostream>
#include <math.h>
// В решении приведена формула равнобедренного треугольника по осн-ю и высоте


class Rectangle
{
private:
    double width;
    double height;
public:
    Rectangle()
    {
        width = 0;
        height = 0;
    }
    Rectangle(double width, double height)
    {
        setHeight(height);
        setWidth(width);
    }
    void setWidth(double w)
    {
        if (w>0)
        {
            width = w;
        }
        else { width = 0; "Error Width. Please, input again\n"; }
    
    }
    void setHeight(double h)
    {
        if (h > 0)
        {
            height = h;
        }
        else{   height = 0;  "Error Height. Please, input again\n"; }

    }
    double getArea()
    {
        double S = 0.5 * height * width;
        return S;
    }   
    double  getPerimeter()
    {
        double P = width + 2.0 * sqrt(pow((width / 2.0), 2) + height * height);
        return P;
    }

        

};


int main()
{
    Rectangle t1{ 8.6, 12 };

    std::cout << "Perimeter: " << t1.getPerimeter() << "\nSquare: " << t1.getArea()<<std::endl;
}

