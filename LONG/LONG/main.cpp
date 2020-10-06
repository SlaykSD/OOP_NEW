// LONG.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "class_LI.h"
#include <iostream>
#include <limits.h>

int getN_Int(int* a) {
    bool good = true;
    do
    {
        std::cin >> *a;
        if (!(good = std::cin.good()))
            std::cout << "Error! Please, repeat your input(INTEGER): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!good);
    return 1;
}
int main()
{
    using LI = LInteger::LongInteger;
    using std::cout;
    using std::endl;
    int n = 0;
    while (std::cin >> n, n > 0) {
        char* str = new char[228];
        cout << "Create some number max_size [50]: ";
        std::cin >> str;
        cout<<endl;
        LI a(str);
        cout << "Your number: ";
        a.Output(std::cout);
        cout << "Use a method divisions: ";
        a.DIV();
        a.Output(std::cout);
        cout << "Use a method multiplications: ";
        a.Multiply10();
        a.Output(std::cout);
              
        std::istream& i = std::cin;
        LI b;
        cout << "Create the other some number max_size [50]: ";
        b.Input(i);
        b.Output(std::cout);
        int ff;
        cout << "Input INTEGER max_size [50] to ADD : ";
        getN_Int(&ff);
        b.add(ff);
        cout << endl;
        b.Output(std::cout);
        cout << "Input INTEGER max_size [50](function ADD): ";
        getN_Int(&ff);
        b.add(ff);
        cout << endl;
        b.Output(std::cout);
        cout << "Input INTEGER max_size [50](function SUB): ";
        getN_Int(&ff);
        b.sub(ff);
        cout << endl;
        b.Output(std::cout);
        delete[] str;
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
