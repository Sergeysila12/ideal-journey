//Все задачи в одном файле
//
//1) Объявить вектор целых чисел и, используя только итератор и цикл,
// вывести все значения
//Повторить процедуру для структуры list
//Сравните код, что бы лучше понять механику итератора
//
//2) Написать программу, которая будет запрашивать у пользователя целые числа, 
// пока он не введёт 0
//числа необходимо хранить в векторе
//вывести среднее арифметическое значение для элементов вектора,
// а так же минимальное и максимальное
//
//3) объявить список(list) из 10 элементов, 
// используя только цикл и итераторы вывести все элементы кратные 3




#include <iostream>
#include <vector>
#include <list>
#include <forward_list>


int main()
{
	std::vector<int> U = { 1,2,3,4,5,6,7,8,9 };
	std::vector <int>::iterator IT_V = U.begin();
	while (true)
	{
		std::cout << *IT_V<< " ";
		IT_V++;
		if (IT_V== U.end())
		{
			break;
		}
	}
	std::cout <<std:: endl;
	std::list<int> L = { -1,-2,-3,-4,-5,-6,-7,-8,-9 };
	std::list<int>::iterator IT_L = L.begin();
	while (true)
	{
		std::cout << *IT_L<<" ";
		IT_L++;
		if (IT_L == L.end())
		{
			break;
		}
	}
	std::cout << std::endl;
	std::cout << "Input numbers: ";
	std::cout << std::endl;
	std::vector<int> Y;
	int value;

	do
	{
		std::cin>>value;
		Y.push_back(value);

	} while (value!=0);

	std::cout << std::endl;
	std::vector <int>::iterator IT_Y = Y.begin();

	int sum=0;
	int MAX=*IT_Y;
	int MIN=*IT_Y;
	int count = 0;

	do
	{
		if (MAX< *IT_Y)
		{
			MAX = *IT_Y;
		}
		if (MIN> *IT_Y&& *IT_Y!=0)
		{
			MIN = *IT_Y;
		}
		count++;
		sum += *IT_Y;
		IT_Y++;

	} while (*IT_Y != 0); 

	float average= (float) sum / (float)count;
	

	std::cout << "Maximum="<< MAX<<"\t";
	std::cout << "Minimum=" << MIN << "\n";
	std::cout << "Average number="<< average;

	std::list<int> List_10 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::list<int>::iterator IT_L10 = List_10.begin();


	std::cout << std::endl;
	while (true)
	{
		if (*IT_L10%3==0)
		{
			std::cout << *IT_L10 << " ";
		}
		IT_L10++;
		if (IT_L10 == List_10.end())
		{
			break;
		}
	}


	/*{
		std::cout << "Input numbers: ";
	};*/
   // std::cout << "Hello World!\n";
}

