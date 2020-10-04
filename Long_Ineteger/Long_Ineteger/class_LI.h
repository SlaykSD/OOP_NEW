#pragma once
#include <iostream>
namespace LInteger
{
	class LongInteger
	{
	private:
		int len;
		int static const len_max = 50;
		char* Invers(char*)const;
		int AddColumn(char*, char*, int k = len_max, bool = false)const;
		const int auto_len();
		char a[len_max+1];//+1 за счет знака
	public:
		//Constructors
		LongInteger();//Пустой конструктоор
		LongInteger(const char* a);//Конструктор для числа 
		LongInteger(int& a);
		LongInteger(long int& a);
		LongInteger(const LongInteger&);
		//Сеттеры+ геттер
		int getlen() const { return len; }
		char* getInfo() const;
		std::ostream& Output(std::ostream&) const;//геттер
		std::istream& Input(std::istream&);//сетер 
		//Возможности класа
		LongInteger& add(const LongInteger&, bool flag = false);
		LongInteger& sub(const LongInteger&) { add(a, true); }
		LongInteger& DIV();
		LongInteger& Multiply10();

		
	};
}
