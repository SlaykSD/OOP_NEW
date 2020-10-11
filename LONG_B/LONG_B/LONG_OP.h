#include <iostream>
namespace LInteger
{
	class LongInteger
	{
	private:
		//parametr
		int len;
		char* a;
		//Metods
		int AddColumn(char*, char*, int k , bool flag = false, bool zero = true)const;
		int copy_rc(const char* str, int i0 = 0);
		int convert_to_signmagnitude(const char* str);
		int insignificant0(const char* str, int i)const;
		int change_of_length(int difference, bool flag = true);
		LongInteger(LongInteger&, int difference);
	public:
		//Constructors
		LongInteger();//Delaults constuctor
		LongInteger(const char* a);
	//	LongInteger(int& a);
		LongInteger(long int& a);
		LongInteger(const LongInteger&);
		LongInteger(LongInteger&& old) :a(old.a), len(old.len) { old.a = nullptr, old.len = 0; };
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
		//destructor
		~LongInteger() 
		{
			if (a != nullptr)
				delete[] a;
		}
		//New option
		LongInteger& operator=(const LongInteger&); //Copy assignment operator.
		LongInteger& operator=(LongInteger&&) noexcept;// Move assignment operator.
	};
}