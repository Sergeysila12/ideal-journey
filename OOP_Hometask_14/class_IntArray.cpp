
//Реализуйте класс IntArray, который хранит динамический массив целых чисел.
//Требования:
//
//Конструктор с параметром size(создает массив заданного размера)
//
//Деструктор(освобождает память)
//
//Конструктор копирования(создает глубокую копию)
//
//Метод set(index, value) для изменения элемента
//
//Метод print() для вывода массива на консоль
//

#include <iostream>


class IntArray
{
private:
    int* ptr=nullptr;
    int size;
public:
    IntArray(int size)
    {
        this->size = size;
        if (ptr != nullptr)
        {
            delete[] ptr;
        }
        this->ptr = new int[this->size];

        for (int i = 0; i < size; i++)
        {
           this-> ptr[i] = i;
        }
    }
    IntArray(const IntArray& other)
    {
        this->size = other.size;

        this->ptr = new int[other.size];

        for (int i = 0; i < other.size; i++)
        {
           this-> ptr[i] = other.ptr[i];
        }
    }

    ~IntArray()
    {
        delete[] ptr;
    }

    void set(int index, int value)
    {
        this->ptr[index] = value;
    }
    void print()
    {
        for (int i = 0; i < (this-> size); i++)
        {
            std::cout << "ptr "<< this->ptr[i]<<std::endl;
        }
    }
};


int main()
{
    IntArray a(25);

    a.set (5, 100);

    a.print();
  
    IntArray c(a);

    c.print();
}

