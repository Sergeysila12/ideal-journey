
//Задача 1: Геометрические фигуры
//Создайте базовый класс Rectangle с полями width и height и методом area().
//Производный класс ColoredRectangle добавляет поле color(строка) и метод display(),
//который выводит площадь и цвет.

#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>


class Rectangle
{
private:
    int width;
    int height;
public:
    Rectangle(int width, int height)
    {
        setWidth(width);
        setHeight(height);
    }
    void setWidth(int width)
    {
        if (width > 0)
            this->width = width;
        else
            throw " ";
    }
    void setHeight(int height)
    {
        if (height > 0)
            this->height = height;
        else
            throw " ";
    }
    int area()
    {
        return width * height;
    }
};

class ColoredRectangle : public Rectangle
{
private: 
    std::string color;
public: 
    ColoredRectangle(int width, int height, std::string color) : Rectangle(width, height)
    {
        setColor(color);
    }
    void setColor(std::string color)
    {
        this->color = color;
    }
  
    void display()
    {
        std::cout << color << std::endl;
       std::cout << area() << std::endl;
    }
};



int main()
{
    ColoredRectangle A(10, 15, "RED");

    A.display();

 
}

