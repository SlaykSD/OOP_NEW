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
		char* Invers(char*)const;
		int add_column(char*, char*)const;
		const int auto_len();
		int copy_rc(const char* str, int i0 = 0);
		int convert_to_signmagnitude(const char* str);
		int insignificant0(const char* str, int i);
	public:
		//Constructors
		LongInteger();//Пустой конструктоор
		LongInteger(const char* a);
	//	LongInteger(int& a);
		LongInteger(long int& a);
		LongInteger(const LongInteger&);
		//Operators
		const LongInteger operator~()const;
		const LongInteger operator-()const;
		//const LongInteger operator+()const;
		friend std::istream& operator>>(std::istream& c, LongInteger&);
		friend std::ostream& operator<<(std::ostream& s, const LongInteger&);
		friend LongInteger operator +(const LongInteger&, const LongInteger&);
		friend LongInteger operator-(const LongInteger& left,const LongInteger& right) { return left + (-right); };
		const LongInteger& operator+=(const LongInteger& right) { *this = (*this + right); return *this; };
		const LongInteger& operator-=(const LongInteger& right) { *this = *this + (-right); return *this; };
		const LongInteger operator *(const int th);
		const LongInteger operator /(const int th);
		const char* getInfo() const;
		int getlen() const { return len; };
	};
}