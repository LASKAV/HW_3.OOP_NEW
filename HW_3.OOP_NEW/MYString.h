#pragma once
#include <iostream>

/*
����������� ����� MyString
����� ������ ��������� ������ ��� ����� ����� � ���������� � ������ ����� �� ����� � ����������.
����� ����� ����������� ����������� �������-����, ������� ����� ���������� ���������� ��������� ��������-�����.
����� ������ ���������:
1. ����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
2. �����������, ����������� ��������� ������ ������������� ������� (��������� ���������� ��������, �� ������� ����� �������� ������);
3. �����������, ������� ������ ������ � �������������� � �������, ���������� � ���� ��������� ����� ������������;
4. �����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������ (� ����������).
5. ����������� �������� + (�� ����� �������� ��� ������������ �����)
6. ����������� �������� ++ (���������� � ����� ������ �������-������ ������ ������� 'x')
7. ����������� �������� -- (�������� ������ ������� �� ����� ������ �������-������)
8. ����������� �������� <
9. ���������� ��������� + ��� ��������: int + MyString (� ������ ��� + MyString )
*/

class MYString                 // ����� MYString
{                              
    char* String_;             // ������ 
    int Length_;               // ����� ������ 
    static int creating_OBJ;   // ����������� ������� (���������� ��������� ��������-�����)

public:
// _______________________________________________________________________________________________________________________________//
//                                                    Constructors
// _______________________________________________________________________________________________________________________________//
    MYString()                            // 1. (����������� �� ���������, ����������� ������� ������ ������ 80 ��������)
    {                                     
        Length_ = 80;                     // ����� 80 �������� 
        String_ = new char[Length_ + 1];  // ������ � �������� 80 �������� + '\0'
        creating_OBJ++;
    }
// _______________________________________________________________________________________________________________________________
    MYString(size_t size)                 // 2. (�����������, ����������� ��������� ������ ������������� �������)
    {
        std::cout << "Size = " << size << std::endl;
        Length_ = size;                   // �������� ������ �� ������������
        String_ = new char[Length_ + 1];  // C������ ������ �������� �� ������������ + '\0'
        creating_OBJ++;                           
    }
// _______________________________________________________________________________________________________________________________
    MYString(const char* temp_String)      // 3. (�����������, ������ ������ � �������������� � �������,
    {                                      //    ���������� � ���� ��������� ����� ������������)    
        Length_ = strlen(temp_String);     // ��������� ������ �� ������������ � ������ �� ������ 
        String_ = new char[Length_ + 1];   // ���� ������ ��������� ������ ������ �� ������������
        strcpy_s(String_, Length_ + 1, temp_String);  // �������� ������ �� ������������ + �������� ������������ ������
        //       | <- <- <- <- (BUFF) <- <- <- |
        creating_OBJ++;
    }
// _______________________________________________________________________________________________________________________________
    MYString(const MYString& temp_String)      // 4. (�����������, ����������� ������� ������ ������,
    {                                          // ���������� �� ������������ (� ����������) )
        Length_ = strlen(temp_String.String_);
        String_ = new char[Length_ + 1];
        strcpy_s(String_, Length_ + 1, temp_String.String_);
        creating_OBJ++;
        
    }
// _______________________________________________________________________________________________________________________________//
//                                                    Overloads
// _______________________________________________________________________________________________________________________________//
    MYString operator+(const MYString& temp_String)     // 5. ����������� �������� + (�� ����� �������� ��� ������������ �����)
    {
        MYString temp_str;
        temp_str.Length_ = this->Length_ + temp_String.Length_;
        temp_str.String_ = new char[temp_str.Length_ + 1];
        strcpy_s(temp_str.String_, temp_str.Length_ + 1, String_);
        strcat_s(temp_str.String_, temp_str.Length_+ 1,temp_String.String_);
        return temp_str;
    }
// _______________________________________________________________________________________________________________________________//
    MYString operator++()             // 6. ����������� �������� ++ (���������� � ����� ������ �������-������ ������ ������� 'x')
    {
        char symbol[10]{"xxx"};
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
    MYString operator--()             // 7. ����������� �������� -- (�������� ������ ������� �� ����� ������ �������-������)
    {
        MYString temp_str;  // ������ ������ ������ ������� ����������
        temp_str.Length_ = strlen(this->String_);               //  ��������� ��������� �������� ��� ������ � ��������� ������ 
        temp_str.String_ = new char[temp_str.Length_ + 1];      
        // ��� ����� ��������� ������ � ������� ���� ������� �� �����
        int i = NULL;  // �������������� ���������� ���� int ��� ������� �������� 
        for (i = 0; i < temp_str.Length_ - 1; i++)
        {
            temp_str.String_[i] = String_[i];  // �������� ������� �� ������� ������ � ��� ��������� ������ 
        }
        temp_str.String_[i] = 0;  // ����� ������ ������� 
        this->String_ = new char[temp_str.Length_ + 1];  // ��� ���������� ������� ��������� �������� ��������� ������
        strcpy_s(String_, temp_str.Length_ + 1, temp_str.String_);  // �������� ��� ��������� � �������� � ������ -1 ������ 

        return *this;  // ���������� ����� - ��������� ������ �������  
    }
// _______________________________________________________________________________________________________________________________
    MYString operator<(const MYString& temp_str)  // 8. ����������� �������� <
    {
        int str3 = strcmp(String_, temp_str.String_);  // ������� ��� ��������� ���� ����� �������� �����������������.
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
    MYString operator+(int symbol)  // ���������� ��������� + ��� ��������: int + MyString (� ������ ��� + MyString )
    {
        char* symb_x = new char [symbol + 1];
        for (size_t i = 0; i <= symbol; i++)
        {
            if (i < symbol)
            {
                symb_x[i] = {'x'};
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
        strcat_s(symb_x, temp_str.Length_ + 1,temp_str.String_);
        return symb_x;
        delete[] symb_x;
    }
// _______________________________________________________________________________________________________________________________
    void InpuT()                           // ������� ����� ������
    {
        if (String_ != nullptr)            // ������ �������� ���� ������ 
        {                                  // �������� � ���� ���-�� �� �� �������
            delete[] String_;
        } 
        char Input_String[40];
        std::cout << "Enter a line : ";
        std::cin.getline(Input_String, 40);
        Length_ = strlen(Input_String) + 1;
        String_ = new char[Length_];
        strcpy_s(String_, Length_, Input_String);
    }

    void OutPut() const                          // ������� ������ ������
    {
        std::cout << "String received : " << String_ << std::endl;
    }

    static int Using_OBJ()
    {
        return creating_OBJ;
    }

    ~MYString()
    {
        creating_OBJ--;
        delete[] String_;
    }

};
// _______________________________________________________________________________________________________________________________
int MYString::creating_OBJ = 0;  //  ����������� ���� ����� ����������� ���������������� ����� �������� ������
// _______________________________________________________________________________________________________________________________