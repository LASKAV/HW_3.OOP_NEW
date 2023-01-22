#pragma once
#include <iostream>

/*
Разработать класс MyString
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран и деструктор.
Также нужно реализовать статическую функцию-член, которая будет возвращать количество созданных объектов-строк.
Класс должен содержать:
1. Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
2. Конструктор, позволяющий создавать строку произвольного размера (принимает количество символов, из которых будет состоять строка);
3. Конструктор, который создаёт строку и инициализирует её строкой, полученной в виде параметра этого конструктора;
4. Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя (с клавиатуры).
5. Перегрузить оператор + (он будет работать как конкатенация строк)
6. Перегрузить оператор ++ (добавление к концу нашего объекта-строки одного символа 'x')
7. Перегрузить оператор -- (удаление одного символа из конца нашего объекта-строки)
8. Перегрузить оператор <
9. Перегрузка оператора + для ситуации: int + MyString (к строке ххх + MyString )
10. Добавить в класс MyString конструктор перемещения.
    (Исследовать ситуации, когда вызывается конструктор перемещения и когда вызывается конструктор копирования)
*/

class MYString                 // класс MYString
{
    char* String_;             // Строка 
    int Length_;               // Длина строки 
    static int creating_OBJ;   // Статическая функция (количество созданных объектов-строк)

public:
// _______________________________________________________________________________________________________________________________//
//                                                    Constructors
// _______________________________________________________________________________________________________________________________//
    MYString()                            // 1. (Конструктор по умолчанию, позволяющий создать строку длиной 80 символов)
    {
        Length_ = 80;                     // Длина 80 символов 
        String_ = new char[Length_ + 1];  // Строка с размером 80 символов + '\0'
        creating_OBJ++;
    }
// _______________________________________________________________________________________________________________________________
    MYString(size_t size)                 // 2. (Конструктор, позволяющий создавать строку произвольного размера)
    {
        std::cout << "Size = " << size << std::endl;
        Length_ = size;                   // Получаем размер от пользователя
        String_ = new char[Length_ + 1];  // Cоздаем строку размером от пользователя + '\0'
        creating_OBJ++;
    }
// _______________________________________________________________________________________________________________________________
    MYString(const char* temp_String)      // 3. (Конструктор, создаёт строку и инициализирует её строкой,
    {                                      //    полученной в виде параметра этого конструктора)    
        Length_ = strlen(temp_String);     // Принимаем строку от пользоваетля и узнаем ее размер 
        String_ = new char[Length_ + 1];   // Наша строка принимает размер строки от пользователя
        strcpy_s(String_, Length_ + 1, temp_String);  // копируем строку от пользователя + избегаем переполнение буфера
        //       | <- <- <- <- (BUFF) <- <- <- |
        creating_OBJ++;
    }
// _______________________________________________________________________________________________________________________________
    MYString(const MYString& temp_String)      // 4. (Конструктор, копирования который создаёт строку,
    {                                          // полученной от пользователя (с клавиатуры) )
        Length_ = strlen(temp_String.String_);
        String_ = new char[Length_ + 100];
        strcpy_s(String_, Length_ + 100, temp_String.String_);
        creating_OBJ++;
    }
// _______________________________________________________________________________________________________________________________
    MYString(MYString&& temp_String)   noexcept    // конструктор перемещения
    {
        Length_ = temp_String.Length_;
        String_ = temp_String.String_;
        temp_String.String_ = nullptr;
        temp_String.Length_ = 0;
    }
// _______________________________________________________________________________________________________________________________//
//                                                    Overloads
// _______________________________________________________________________________________________________________________________//
    MYString operator+(const MYString& temp_String)     // 5. Перегрузить оператор + (он будет работать как конкатенация строк)
    {
        MYString temp_str;
        temp_str.Length_ = this->Length_ + temp_String.Length_;
        temp_str.String_ = new char[temp_str.Length_ + 1];
        strcpy_s(temp_str.String_, temp_str.Length_ + 1, String_);
        strcat_s(temp_str.String_, temp_str.Length_ + 1, temp_String.String_);
        return temp_str;
    }
// _______________________________________________________________________________________________________________________________//
    MYString operator++()             // 6. Перегрузить оператор ++ (добавление к концу нашего объекта-строки одного символа 'x')
    {
        char symbol[10]{ "xxx" };
        MYString temp_str;
        temp_str.Length_ = this->Length_ + strlen(symbol) + 1;
        temp_str.String_ = new char[temp_str.Length_ + 1];
        strcpy_s(temp_str.String_, temp_str.Length_ + 1, String_);
        strcat_s(temp_str.String_, temp_str.Length_ + 1, symbol);

        this->String_ = new char[temp_str.Length_ + 1];
        strcpy_s(String_, temp_str.Length_ + 1, temp_str.String_);

        return *this;
    }
    // _______________________________________________________________________________________________________________________________
    MYString operator--()             // 7. Перегрузить оператор -- (удаление одного символа из конца нашего объекта-строки)
    {
        MYString temp_str;  // Внутри метода класса создаем переменную
        temp_str.Length_ = strlen(this->String_);               //  применяем шаблонный алгоритм для строки с выделение памяти 
        temp_str.String_ = new char[temp_str.Length_ + 1];
        // Нам нужно перебрать массив и удалить один символа из конца
        int i = NULL;  // инициализируем переменную типа int для массива символов 
        for (i = 0; i < temp_str.Length_ - 1; i++)
        {
            temp_str.String_[i] = String_[i];  // передаем символы из объекта класса в наш временный объект 
        }
        temp_str.String_[i] = 0;  // конец строки объекта 
        this->String_ = new char[temp_str.Length_ + 1];  // для основоного объекта шаблонный алгоритм выделение памяти
        strcpy_s(String_, temp_str.Length_ + 1, temp_str.String_);  // копируем наш временный в основной с учетом -1 символ 

        return *this;  // возвращаем конст - указатель нашего объекта  
    }
    // _______________________________________________________________________________________________________________________________
    MYString operator<(const MYString& temp_str)  // 8. Перегрузить оператор <
    {
        int str3 = strcmp(String_, temp_str.String_);  // функция для сравнения двух строк лексично лексикографически.
        char* result_true = new char [20] {"True"};
        char* result_folse = new char [20] {"False"};
        char* result_ravelo = new char [20] {"Ravelo"};
        if (str3 < 1)
        {
            MYString Result(result_true);
            return Result;
        }
        else if (str3 > 1)
        {
            MYString Result(result_folse);
            return Result;
        }
        else if (str3 == 0)
        {
            MYString Result(result_ravelo);
            return Result;
        }
        delete[] result_folse;
        delete[] result_ravelo;
        delete[] result_true;
    }
    // _______________________________________________________________________________________________________________________________
    MYString operator+(int symbol)  // Перегрузка оператора + для ситуации: int + MyString (к строке ххх + MyString )
    {
        char* symb_x = new char[symbol + 1];
        for (size_t i = 0; i <= symbol; i++)
        {
            if (i < symbol)
            {
                symb_x[i] = { 'x' };
            }
            else if (i == symbol)
            {
                symb_x[i] = { '\0' };
            }
        }
        MYString temp_str;
        temp_str.Length_ = this->Length_ + strlen(symb_x) + 1;
        temp_str.String_ = new char[temp_str.Length_ + 1];
        strcpy_s(temp_str.String_, temp_str.Length_ + 1, String_);
        strcat_s(symb_x, temp_str.Length_ + 1, temp_str.String_);
        return symb_x;
        delete[] symb_x;
    }
    // _______________________________________________________________________________________________________________________________
    void InpuT()                           // Функция ввода данных
    {
        if (String_ != nullptr)            // Делаем проверку если строка 
        {                                  // содержит в себе что-то мы ее удаляем
            delete[] String_;
        }
        char Input_String[40];
        std::cout << "Enter a line : ";
        std::cin.getline(Input_String, 40);
        Length_ = strlen(Input_String) + 1;
        String_ = new char[Length_];
        strcpy_s(String_, Length_, Input_String);
    }

    void OutPut() const                          // Функция вывода данных
    {
        std::cout << "String received : " << String_ << std::endl;
    }

    static int Using_OBJ()
    {
        return creating_OBJ;
    }

    void SetString_(char* sim)
    {
        Length_ = strlen(sim);
        String_ = new char[Length_ + 1];
        strcpy_s(String_, Length_ + 1, sim);
    }
    void SetLength_(size_t size)
    {
        Length_ = size;
    }
    int GetLength_()
    {
        return Length_;
    }
    char* GetString_() const
    {
        return String_;
    }

    ~MYString()
    {
        creating_OBJ--;
        delete[] String_;
    }

};
// _______________________________________________________________________________________________________________________________
int MYString::creating_OBJ = 0;  //  статическое поле нужно обязательно инициализировать после создания класса
// _______________________________________________________________________________________________________________________________
