// LONG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "class_LI.h"
#include <iostream>

int main()
{
    using LI = LInteger::LongInteger;
    using std::cout;
    using std::endl;
    int n = 0;
    while (std::cin >> n, n > 0) {
        /*
        char* str = new char[228];
        cout << "Create some number max_size [50]: ";
        std::cin >> str;
        cout<<endl;
        LI a(str);
        a.Output(std::cout);
        a.DIV();
        a.Output(std::cout);
        a.Multiply10();
        a.Output(std::cout);
              
        std::istream& i = std::cin;
        LI b;
        cout << "Create the other some number max_size [50]: ";
        b.Input(i);
        b.Output(std::cout);
         */
        LI b;
        int ff;
        cout << "Input INTEGER max_size [50]: ";
        std::cin >> ff;
        b.add(ff);
        ff = -2133;
        b.add(ff);
        b.Output(std::cout);
        std::cin >> ff;
        b.sub(ff);
        b.Output(std::cout);
       // delete[] str;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
