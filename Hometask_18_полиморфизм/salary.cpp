
//Задача 2: Система оплаты труда
//Условие :
//Создайте базовый класс Employee и производные классы HourlyEmployee(почасовая оплата) 
// и SalariedEmployee(фиксированная зарплата).Реализуйте метод calculatePay(), 
// который считает зарплату в зависимости от типа сотрудника.
#include <iostream>

class Employee
{
protected:
	double salary;
public:
	Employee(double salary)
	{
		setSalary(salary);
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	virtual double calculatePay() = 0;
	
};

class SalariedEmployee: public Employee
{
private:
	int number_of_working_days;
	int number_of_days_worked;
public:

	SalariedEmployee(int number_of_working_days, int number_of_days_worked, double salary): Employee(salary)
	{
		setDays(number_of_working_days, number_of_days_worked);
	}
	void setDays(int number_of_working_days, int number_of_days_worked)
	{
		this->number_of_working_days = number_of_working_days;
		this->number_of_days_worked = number_of_days_worked;
	}
	double calculatePay() 
	{
		return double((salary / (double)number_of_working_days) * number_of_days_worked);
	}
};

class HourlyEmployee: public Employee
{
private:
	int std_number_of_working_hours;
	int number_of_hours_worked;

public:
	HourlyEmployee(int std_number_of_working_hours, int number_of_hours_worked, double salary) : Employee(salary)
	{
		setHours(std_number_of_working_hours, number_of_hours_worked);
	}
	void setHours(int std_number_of_working_hours, int number_of_hours_worked)
	{
		this->std_number_of_working_hours = std_number_of_working_hours;
		this->number_of_hours_worked = number_of_hours_worked;
	}
	double calculatePay()
	{
		return double(number_of_hours_worked * (salary / (double)std_number_of_working_hours));
	}

};



int main()
{
	HourlyEmployee Sergey(160, 110, 80000);
	SalariedEmployee Egor(160, 160, 100000);

	std::cout << Sergey.calculatePay() << "\n";
	std::cout << Egor.calculatePay();
}

