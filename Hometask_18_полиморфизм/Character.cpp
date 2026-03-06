// Задача 3: Игровые персонажи
//Условие:
//Создайте базовый класс Character с методом attack().
// Реализуйте производные классы Warrior, Mage и Archer, каждый из которых атакует по - разному.
// Используйте полиморфизм для управления атаками персонажей.
//Реализовать метод можно просто вписав в него cout
//

#include <iostream>

class Character
{
protected:
	std::string name;
public:
	Character(std::string name)
	{
		this->name = name;
	}
	virtual void attack() = 0;
};

class Warrior:public Character
{
public:
	Warrior(std::string name) : Character(name){}
	void attack() override
	{
		std::cout << "I'm a " << name;
	}
};

class Mage :public Character
{
public:
	Mage(std::string name) : Character(name) {}
	void attack() override
	{
		std::cout << "I'm a "<<name;
	}
};

class Archer :public Character
{
public:
	Archer(std::string name) : Character(name) {}
	void attack() override
	{
		std::cout << "I'm a "<<name;
	}
};


int main()
{
	Character* CharacterArray[3];
	CharacterArray[0] = new Warrior("Strongman");
	CharacterArray[1] = new Mage("Fireman");
	CharacterArray[2] = new Archer("Knight");
	for (int i = 0; i < 3; i++)
	{
		CharacterArray[i]->attack();
		std::cout <<std:: endl;
	}
}

