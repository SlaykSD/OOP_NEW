#pragma once
#include <iostream>
namespace LInteger
{
	class LongInteger
	{
	private:
		//parametr
		int len;
		int static const len_max = 50;
		char a[len_max + 1];//+1 за счет знака
		//Metods
		char* Invers(char*)const;
		int AddColumn(char*, char*, int k = len_max, bool flag = false, bool zero = true)const;
		const int auto_len();
		int copy_rc(const char* str, int i0 = 0);
		int correct(const char* str);
		int insignificant0(const char* str , int i);
	public:
		//Constructors
		LongInteger();//Пустой конструктоор
		LongInteger(const char* a);//Конструктор для числа 
		LongInteger(int& a);
		LongInteger(long int& a);
		LongInteger(const LongInteger&);
		//Сеттеры+ геттер
		int getlen() const { return len; }
		const char* getInfo(char*) const;
		std::ostream& Output(std::ostream&) const;//геттер
		std::istream& Input(std::istream&);//сетер 
		//Возможности класа
		LongInteger& add(const LongInteger&, bool flag = false);
		LongInteger& sub(const LongInteger& x) 
		{ 
			add(x, true);
			return *this; 
		}
		LongInteger& DIV();
		LongInteger& Multiply10();

	};
}
