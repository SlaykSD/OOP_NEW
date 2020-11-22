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
    virtual void g() //�������� �������� �� �������� ����� virtual
    {
        cout << "original g() called\n";
    };
} objA;

class B : public A
{
public:
    virtual void g() //�������� �������� �� �������� ����� virtual
    {
        cout << "g() called\n\t";
        foo();
    };
private:
    sf::Texture texture;
} objB;

int main()
{
    objA.g();                     //��������� g() �� ������� ���� A, ��� � ������ ����

    A* ptrA = (A*)(&objB); //���� ����� objB, �������� ��� � ���� ��������� �� A �                         //���������� � ptrA

    ptrA->g();                   //�������� g() �� ������� ���� B, ���� ��������� ������,                                //��� ��������� �� ������ ���� A (��. ����������� �������)

    return 0;
}