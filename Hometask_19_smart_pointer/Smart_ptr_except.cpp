
#include <iostream>
#include <memory>
#include <stdexcept>

class Device
{
private:
	std::string message;
public:
	Device(const std::string& message)
	{
		this->message = message;

	}
	void show()
	{
		std::cout << message;
	}
};

class Controller
{
private:
	std::shared_ptr<Device> ctrl_ptr;
public:
	Controller(const std::string& word)
	{
		settingPtr(word);
	}

	void settingPtr(std::string word)
	{
		std::shared_ptr<Device> ctrl_ptr{ std::make_shared<Device>(word) };
		ctrl_ptr->show();
	}
};

class Child;
class Parent
{
private:
	std::string name;
	std::shared_ptr<Child> kid;
public:
	Parent(const std::string& name)
	{
		this->name = name;
	}
	void setBinding(const std::shared_ptr<Child>&N)
	{
		kid = N;
	}
	~Parent()
	{}
};
class Child
{
private:
	std::string name;
	std::weak_ptr<Parent> father;
public:
	Child(const std::string& name)
	{
		this->name = name;
	}
	void setBinding(const std::weak_ptr<Parent>& N)
	{
		father = N;
	}
	~Child()
	{}
};

void divade(int a, int b)
{
	if (b == 0)
	{
		throw std::invalid_argument("invalid argument //-//");
	}

}


int main()
{
	Controller phone("www.print.com");
	Controller pager(" //-//-//");

	std::shared_ptr<Parent> Ivan_father{ std::make_shared<Parent>("Ivan") };
	std::shared_ptr<Child> Petr_kid{ std::make_shared<Child>("Petr") };
	std::weak_ptr<Parent> wptr(Ivan_father);

	Ivan_father->setBinding(Petr_kid);
	Petr_kid->setBinding(wptr);

	Ivan_father.reset();
	Petr_kid.reset();

	try
	{
		divade(5, 1);
	}
	catch (const std::invalid_argument& a)
	{
		std::cout << a.what();
	}
	catch (...)
	{
		std::cout << "The function was called incorrectly";
	}
}

