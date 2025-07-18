

//Создайте класс `Book`.
//Требования:
//-Поля : `title` (название, строка), `author` (автор, строка), `year` (год издания, int), `pages` (количество страниц, int).
//- Конструктор по умолчанию(инициализирует пустыми значениями и нулями).
//- Конструктор с параметрами(название, автор, год, страницы).
//- Конструктор копирования.
//- Деструктор(выводит сообщение о том, что книга уничтожена, с указанием названия).
//- Методы:
//`bool isAntique()` - возвращает true, если книга издана раньше 1900 года.
//`void print()` - выводит информацию о книге.
//


#include <iostream>


class Book
{
private:
	std::string title;
	std::string author;
	int year;
	int pages;


public:
	Book()
	{
		this->title;
		this->author;
		this->year = NULL;
		this->pages = NULL;
	}
	Book(std::string title, std::string author, int year, int pages)
	{
		this->title = title;
		this->author = author;
		this->year = year;
		this->pages = pages;
	}
	Book(const Book& other)
	{
		this->year = other.year;
		this->pages = other.pages;
		this->title = other.title;
		this->author = other.author;
	}
	~Book()	{ }
	bool isAntique()
	{
		if (this->year<1900)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void print()
	{
		std::cout << "TITLE " <<this-> title << std::endl;
		std::cout << "Author " <<this->author << std::endl;
		std::cout << "Year " <<this->year << std::endl;
		std::cout << "Pages " <<this->pages << std::endl;
	}

};


int main()
{
	Book s();

	Book a("Wuthering Heights", "Emily Bronte", 1847, 316 );

	Book b(a);

	b.print();

}

