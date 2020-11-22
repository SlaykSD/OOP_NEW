#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
class A
{
protected:
    void foo()
    {
        cout << "foo() called\n";
    };

public:
    virtual void g() //обратите внимание на ключевое слово virtual
    {
        cout << "original g() called\n";
    };
} objA;

class B : public A
{
public:
    virtual void g() //обратите внимание на ключевое слово virtual
    {
        cout << "g() called\n\t";
        foo();
    };
private:
    sf::Texture texture;
} objB;

int main()
{
    objA.g();                     //Вызовется g() из объекта типа A, как и должно быть

    A* ptrA = (A*)(&objB); //берём адрес objB, приводим его к типу указателя на A и                         //записываем в ptrA

    ptrA->g();                   //вызываем g() из объекта типа B, хотя указатель думает,                                //что указывает на объект типа A (см. виртуальные функции)

    return 0;
}