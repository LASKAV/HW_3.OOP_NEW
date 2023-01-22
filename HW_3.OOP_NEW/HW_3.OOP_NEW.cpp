#include "MYString.h"
#include <string.h>
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
11. Добавить перегрузку оператора присваивания копированием +
перегрузку оператора присваивания перемещением.

12. Добавить конструктор Initializer_list.
	Создать объект типа MyString с помощью этого конструктора.

1.  (+)
2.  (+)
3.  (+)
4.  (+)
5.  (+)
6.  (+)
7.  (+)
8.  (+)
9.  (+)
10. (+)

*/

void frame();              // прототип функции ( Рамка =) )
MYString& operator+(int symbol, MYString& temp);

const size_t BUFFER = 80;  // глобальная переменная для размеров массивов  
int main()
{
	// _______________________________________________________________________________________________________________________________//
	//                                                    Constructors
	// _______________________________________________________________________________________________________________________________//
	//  std::cout << "Constructor # 1" << std::endl;  // 1. (Конструктор по умолчанию, позволяющий создать строку длиной 80 символов)
	//  MYString Constructor_one;
	//  Constructor_one.InpuT();
	//  Constructor_one.OutPut();
	//  frame();  // Рамка =)
	// _______________________________________________________________________________________________________________________________
	//	std::cout << "Constructor # 2" << std::endl;  // 2. (Конструктор, позволяющий создавать строку произвольного размера)
	//	std::cout << "Enter size string : ";
	//	size_t size_c_tow = NULL;                     // создаем переменную которая будет передавать размер в конструктор 
	//	std::cin >> size_c_tow;
	//	std::cin.ignore();                            // Очищает любой ввод, оставшийся в памяти 
	//	MYString Constructor_two(size_c_tow);
	//	Constructor_two.InpuT();
	//	Constructor_two.OutPut();
	//	frame();
	// _______________________________________________________________________________________________________________________________
	//	std::cout << "Constructor # 3" << std::endl;                // 3. (Конструктор, создаёт строку и инициализирует её строкой, 
	//	char* temp_string_three = new char[BUFFER]{ "MyString" };   // полученной в виде параметра этого конструктора)
	//	MYString Constructor_three(temp_string_three);
	//	Constructor_three.OutPut();
	//	frame();
	//	
	// _______________________________________________________________________________________________________________________________
	//	std::cout << "Constructor # 4" << std::endl;     // 4. (Конструктор, копирования который создаёт строку,
	//	char* temp_string_four = new char[BUFFER];       // полученной от пользователя (с клавиатуры) )                                              
	//	std::cout << "Enter string : ";
	//	std::cin.getline(temp_string_four, BUFFER);
	//	//std::cin.ignore();                               // Очищает любой ввод, оставшийся в памяти
	//	MYString Constructor_four(temp_string_four);
	//	Constructor_four.OutPut();
	//	frame();
	// _______________________________________________________________________________________________________________________________//
	//                                                    Overloads
	// _______________________________________________________________________________________________________________________________//
	//  std::cout << "Overload (+) " << std::endl;       // 5. Перегрузить оператор + (он будет работать как конкатенация строк)
	//  char* temp_string_Overload_one = new char[BUFFER] { "string" };
	//  char* temp_string_Overload_two = new char[BUFFER] { "string" };
	//  MYString temp_string_Overload_O(temp_string_Overload_one);
	//  MYString temp_string_Overload_G(temp_string_Overload_two);
	//  MYString Overload_one = temp_string_Overload_O + temp_string_Overload_G;
	//  Overload_one.OutPut();
	//  delete[] temp_string_Overload_one;
	//  delete[] temp_string_Overload_two;
	//  frame();
	// _______________________________________________________________________________________________________________________________
	//  std::cout << "Overload (++) " << std::endl;   // 6. Перегрузить оператор ++ (добавление к концу нашего объекта-строки одного символа 'x')
	//  MYString Overload_two = temp_string_Overload_O;
	//  ++Overload_two;
	//  Overload_two.OutPut();
	//  frame();
	// _______________________________________________________________________________________________________________________________
	//	std::cout << "Overload (--) " << std::endl;  // 7. Перегрузить оператор -- (удаление одного символа из конца нашего объекта-строки)
	//	MYString Overlad_three = temp_string_Overload_G;
	//	Overlad_three.OutPut();
	//	--Overlad_three;
	//	Overlad_three.OutPut();
	//	frame();
	// _______________________________________________________________________________________________________________________________
	//	std::cout << "Overload (<) " << std::endl;  // 8. Перегрузить оператор <
	//	MYString Overlad_four = temp_string_Overload_O < temp_string_Overload_G;
	//	Overlad_four.OutPut();
	//	frame();
	// _______________________________________________________________________________________________________________________________
	//  std::cout << "Overload (int + MyString) " << std::endl;  // 9. Перегрузка оператора + для ситуации: int + MyString (к строке ххх + MyString )
	//  int num_X = 2;
	//  MYString Overlad_fifth = num_X + temp_string_Overload_O;
	//  Overlad_fifth.OutPut();
	//  frame();
	// _______________________________________________________________________________________________________________________________

	//  MYString Overlad_moving_one("Hello MyString");   // Перегрузка оператора присваивания перемещением
	//  Overlad_moving_one.OutPut();
	//  MYString Overlad_moving_two("MyString = Hello");
	//  Overlad_moving_two.OutPut();
	//  Overlad_moving_one = Overlad_moving_two;
	//  Overlad_moving_one.OutPut();
	// _______________________________________________________________________________________________________________________________
	//  Overlad_moving_one = std::move(Overlad_moving_two); // оператор присваивания с перемещением
	//  Overlad_moving_one.OutPut();
	// _______________________________________________________________________________________________________________________________
	std::cout << "Constructor initializer_list " << std::endl;
	MYString constr_init{ 'M','y',' ','s','t','r','i','n','g','\0'};
	constr_init.OutPut();
	// _______________________________________________________________________________________________________________________________
	return 0;

}

void frame()
{
	for (int i = 0; i < 35; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
}

MYString& operator+(int symbol, MYString& temp)  // Перегрузка оператора + для ситуации: int + MyString (к строке ххх + MyString )
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
	MYString str;
	str.SetLength_(strlen(symb_x) + strlen(temp.GetString_()) + 1);
	char* Temp_str = new char[str.GetLength_() + 1];
	strcpy_s(Temp_str, str.GetLength_() + 1, symb_x);
	strcat_s(Temp_str, str.GetLength_() + 1, temp.GetString_());
	str.SetString_(Temp_str);
	std::cout << Temp_str;
	delete[] Temp_str;
	delete[] symb_x;
	return str;
}
