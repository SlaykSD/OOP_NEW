#pragma once
#include <iostream>
namespace LInteger
{
	class LongInteger
	{
	private:
		//parametr
		int len;
		int static const LEN_MAX = 50;
		char a[LEN_MAX + 1];
		//Metods
		char* compute_invers(char*)const;
		int add_column(char*, char*)const;
		const int auto_len();
		int copy_rc(const char* str, int i0 = 0);
		int convert_to_signmagnitude(const char* str);
		int insignificant0(const char* str , int i);
	public:
		//Constructors
		LongInteger();
		LongInteger(const char* a);
		LongInteger(int& a);
		LongInteger(long int& a);
		LongInteger(const LongInteger&);
		//setters
		int getlen() const { return len; }
		const char* getInfo(char*) const;
		std::ostream& output(std::ostream&) const;//setter
		std::istream& input(std::istream&);//getter
		//Opportunities of class
		LongInteger& add(const LongInteger&, bool flag = false);
		LongInteger& sub(const LongInteger& x) 
		{ 
			add(x, true);
			return *this; 
		}
		LongInteger& div();
		LongInteger& multiply10();
	};
}
