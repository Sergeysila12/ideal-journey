
//Класс "Студент" (Student)
//-Поля:
//имя(name) - string
//возраст(age) - int
//средний балл(gpa) - double
//- Конструкторы : по умолчанию и с параметрами
//- Методы : геттеры и сеттеры для каждого поля с валидацией :
//имя: не пустое(можно не делать сложную проверку, но можно проверить, что строка не пустая)
//возраст : от 16 до 100 (условно)
//gpa : от 0.0 до 5.0 (или 10.0 - как принято в системе)
//- Метод : printInfo() - выводит информацию о студенте



#include <iostream>

class Student
{
private:
	std::string name;
	int age;
	double avarage_score;
public:
	Student()
	{
		name = "Undefined";
		age = 0;
		avarage_score = 0.0;

	}
	Student(std::string Newname, int Newage, int* arr, int size)
	{
		setName(Newname);
		setAge(Newage);
		setScore(arr, size);
	}
	void setName(std::string Newname)
	{
		if (sizeof(Newname) > 0)
		{
			name = Newname;
		}
		else
		{
			name = "Undefined";
		}
	}
	void setAge(int Newage)
	{
		if (Newage >= 16 && Newage <= 100)
		{
			age = Newage;
		}
		else
		{
			age = 0;
		}
	}
	void setScore(int* arr, int size)
	{
		double temp = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > 0.0 && arr[i] <= 5.0)
			{
				temp += arr[i];
			}
		}
		avarage_score = temp / (double)size;
	}
	int getAge() { return age; }
	std::string getName() { return name; }
	double getScore() { return avarage_score; }

	void PrintInfo()
	{
		std::cout << "Student name: " << getName()
			<< "\nAge: " << getAge() << "\nAvarage grade: " << getScore() << std::endl;
	}
};



int main()
{
	const int SIZE = 10;
	int  arr_s1[SIZE]{ 2,3,1,4, 4,1,5,4,3,2 };
	int  arr_s2[SIZE]{ 3,1,5,5, 4,3,5,4,3,5 };
	//int  arr_s3[SIZE]{ 1,3,1,4, 4,3,2,4,2,2 };

	Student student1("Sergey", 18, arr_s1, 10);
	Student student2 ("Ivan", 21, arr_s2, 10);

	student1.PrintInfo();
	std::cout << "------////////--------------------------------" << std::endl;
	student2.PrintInfo();


}

