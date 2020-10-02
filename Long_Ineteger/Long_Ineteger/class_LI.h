#pragma once
namespace LInteger
{
	class LongInteger
	{
	private:
		int len;
		int static const len_max = 50;
		char a[len_max+1];//+1 за счет знака
	public:
		LongInteger();//Пустой конструктоор
		LongInteger(const char* a);//Конструктор для числа 
		LongInteger(int& a);
		LongInteger(long int& a);

	};
}
