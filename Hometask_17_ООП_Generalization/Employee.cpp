

//Задача 3: Сотрудники компании
//Базовый класс Employee с полями name и salary.
//Производный класс Manager добавляет поле department и метод printInfo().


#include <iostream>

#include <string>


class Employee
{
protected:
    std::string name;
    double salary;
public:
    Employee(std::string name, double salary)
    {
        this->name = name;
        this->salary = salary;
    }
};

class  Manager: public Employee
{
private:
    std::string department;

public:
    Manager(std::string name, double salary, std::string department): Employee( name,  salary)
    {
        this->department = department;
    }
    void printInfo()
    {
        std::cout << this->department << std::endl;
        std::cout << this->name << std::endl;
        std::cout << this->salary << std::endl;
    }
};






int main()
{
    Manager Ivan("Ivan", 20000, "press");
    Ivan.printInfo();
}

