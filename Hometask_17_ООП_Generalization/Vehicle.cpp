
//
//Задача 2: Транспортные средства
//Базовый класс Vehicle с полями speed и model.
//Производный класс Car добавляет поле fuelType(строка) и метод showDetails().


#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <unordered_map>


class Vehicle
{
protected:
    int speed;
    std::string model;
public:
    Vehicle(int speed, std::string model)
    {
        setSpeed(speed);
        setModel(model);
    }
    void setSpeed(int speed)
    {
        this->speed = speed;
    }
    void setModel(std::string model)
    {
        this->model = model;
    }


};

class Car: public Vehicle
{
    private:
        std::string fuelType;
public:

    Car(int speed, std::string model, std::string fuelType): Vehicle( speed, model)
    {
        setFuel(fuelType);
    }
    void setFuel(std::string fuelType)
    {
        this->fuelType = fuelType;
    }
    void showDetail()
    {
        std::cout << fuelType<<std::endl;
        std::cout << this->speed <<std::endl;
        std::cout << this->model <<std::endl;
    }
};

int main()
{
    Car A(120, "LADA", "gasoline");
    A.showDetail();
}

