// Написать класс "Точка" (Point)
//-Поля: x, y(координаты, private)
//- Конструкторы : по умолчанию(x = 0, y = 0) и с параметрами(x, y)
//- Методы :
//    setX(int x), setY(int y) - для установки координат
//    getX(), getY() - для получения координат
//    - Дополнительно : метод вывода координат(print) или вывод в консоль
//

#include <iostream>

class Point
{
private:
	int x;
	int y;
public:

	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	Point() 
	{
		x = 0;
		y = 0;
	}
	void setX( int newx)
	{
		x = newx;
	}	
	void setY( int newy)
	{
		y = newy;
	}
	int getX()
	{
		return x;
	}	
	int getY()
	{
		return y;
	}
	void printCoords()
	{
		std::cout << "Point x: " << x << "\nPoint y: " << y << std::endl;
	}

};
int main()
{
	Point point_1(11,18);
	point_1.printCoords();
}

