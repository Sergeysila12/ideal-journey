//Создайте класс для управления товарными позициями.
//Требования:
//
//Приватные поля : id, name, quantity, price
//
//Конструкторы :
//
//По умолчанию(пустой товар)
//
//С параметрами(id, name, quantity, price)
//
//
//Методы :
//
//    double totalValue() - общая стоимость позиции
//
//    void restock(int amount) - пополнение запаса
//
//    bool sell(int amount) - продажа(если достаточно товара)
//
//    void applyDiscount(float percent) - применение скидки


#include <iostream>


class Goods 
{
private:
    int ID;
    std::string name;
    int quantity;
    float price;
public:
    Goods()
    {
        this->ID = NULL;
        this->name = '\0';
        this->quantity = NULL;
        this->price = NULL;
    }
    Goods(int ID, std::string name, int quantity, float price)
    {
        this->ID = ID;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }
    double totalValue()  //общая стоимость позиции
    {
        return (float)quantity * price;
    }
    void restock(int amount) //пополнение запаса
    {
        this->quantity += amount;
    }
    bool sell(int amount) //продажа(если достаточно товара)
    {
        if (this->quantity>=amount)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void applyDiscount(float percent) // применение скидки
    {
        this->price *= (1 - (percent /100.0));
    }
};

int main()
{

    Goods();
   
    Goods Spoon (1, "Spoon", 350, 1.85); 
    Spoon.restock(15);
    Spoon.applyDiscount(10.15);
    std::cout << "GENERAL COST " << Spoon.totalValue() << std::endl;
}

