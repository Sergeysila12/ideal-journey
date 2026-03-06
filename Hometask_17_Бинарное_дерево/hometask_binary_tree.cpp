
//
//Задача 1: Подсчет частоты слов в тексте
//Напишите программу, которая читает текст и выводит, сколько раз каждое слово встречалось в нем.
// Для решения этой задачи отлично подойдёт словарь
//
//Задача 2 : Телефонная книга
//Реализуйте простую телефонную книгу.Команды :
//    add <имя> <телефон> — добавить / обновить номер.
//    find <имя> — найти номер.Если имени нет, вывести "Not found".
//    del <имя> — удалить запись.
//
//    команды необходимо получать через консоль
//




#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main()
{
	//std::string text= "There is an simple of text text that needs to be broken broken into words words.";
	std::string text;

	std::map<std::string, int> frequency;
	//int c=1;
	const int SIZE = 100;
	char array[SIZE];

	char c;
	int count = 0;
	//	int count2 = 1;
	std::cout << "Input text:  ";
	std::cout << std::endl;
	while (std::cin.get(c) && c != '\n')
	{
		//std::cin >> c;
		if (c != 0x20 && c != 0x2C && c != 0x2D && c != 0x2B && c != 0x2A && c != 0x22 && c != 0x27)
		{
			array[count++] = c;
		}
		else if (c == 0x20 && count >= 1)
		{
			array[count] = '\0';
			//std::string text(array);
			if (frequency.count(array) == 0)
			{
				std::pair<std::string, int> p(array, 1);
				frequency.insert(p);
			}
			else
			{
				frequency[array] += 1;
			}
			count = 0;
		}

	}
	if (count > 0) {
		array[count] = '\0';
		std::string word(array);
		frequency[word]++;  // std::map сам создаст запись с 0, если её нет
	}


	for (auto iter{ frequency.begin() }; iter != frequency.end(); iter++)
	{
		std::cout << iter->first << "\t" << iter->second << std::endl;
	}

	std::map<std::string, std::string > PhoneBook;
//	delete[] array;
	
	long int qw = 0;
	int ct = 0;
	std::string name;
	std::string phone;
	//std::vector<std::string> words;
	int flag = 1;
	char name_array[SIZE];
	char phone_array[SIZE];
	std::cout << "Input command: add, find or del. Press enter \n";
	while (std::cin.get(c) && c != '\n')
	{
		qw+= c;
	}
	if (qw ==297)
	{
		std::cout << "Input name and phone. Press enter \n";
		while (std::cin.get(c) && c != '\n')
		{
			//words.push_back(c);
			if (flag)
			{
				name_array[ct++] = c;
			}
			else if (flag==0)
			{
				phone_array[ct++] = c;
			}
			if (c == 0x20&& flag)
			{
				name_array[ct] = '\0';
				flag = 0;
			//	std::string name(array);
				ct = 0;
				//PhoneBook[name];
			}
		}
//	std::vector<std::string> words = { array };
//	words.shrink_to_fit();
	phone_array[ct] = '\0';
	std::string name = name_array;
	std::string phone = phone_array;

	//std::string phone (array);
	//std::pair<std::string, int> n (std::string word1 , std::string word2);

	PhoneBook[name] = phone;

	ct = 0;
	//	array[ct] = '\0';
	
	}
	else if (qw==417)
	{
		std::cout << "Input name to find a phone number. Press enter \n";
		ct = 0;
		while (std::cin.get(c) && c != '\n')
		{
			name_array[ct++] = c;
		}
		name_array[ct] = '\0';
		ct = 0;
		std::string name(name_array);
		auto it= PhoneBook.find(name);
		if (it!= PhoneBook.end())
		{
			std::cout << it->second << std::endl;
		}
		else
		{
			std::cout << "Not found" << std::endl;
		}
	}
	else if(qw==309)
	{
		std::cout << "Input name to delete a phone number. Press enter \n";
		ct = 0;
		while (std::cin.get(c) && c != '\n')
		{
			name_array[ct++] = c;
		}
		name_array[ct] = '\0';
		ct = 0;
		std::string name(array);
		PhoneBook.erase(name);
	}
	else
	{
		std::cout << "Input command again \n";
	}
	//delete[] name_array;
	//delete[] phone_array;

	for (auto iter{ PhoneBook.begin() }; iter != PhoneBook.end(); iter++)
	{
		std::cout << iter->first << "\t" << iter->second << std::endl;
	}
}

