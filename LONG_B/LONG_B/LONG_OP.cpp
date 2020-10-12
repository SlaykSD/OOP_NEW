#include "LONG_OP.h"
#include <cctype> 
#include <string>

namespace LInteger
{
	using LI = LongInteger;
	LI::LongInteger() :len(1)//Пустой конструктоор
	{
		a = new char[3];
		a[0] = a[1] = '0';
		a[2] = 0;
	}
	LI::LongInteger(const char* a) : LongInteger()
	{
		int l = strlen(a);
		int j;
		try
		{
			j = convert_to_signmagnitude(a);
		}
		catch (const char* a)
		{
			if (a == "Incorrcet input")
				std::cout << "Your number is not correct.The first symbol should be - or + or integer" << std::endl;
			if (a == "Owerflow")
				std::cout << "Your number is not correct.Your number is too big " << std::endl;
		}
		char sign = a[0];
		if (j != l)
		{
			copy_rc(a, j);
			LI::a[0] = sign;
		}
		else LI::a[0] = '0';
	}
	int LI::copy_rc(const char* str, int i0)
	{
		if (a != nullptr)
		{
			delete[] a;
		}
		a = new char[len + 2];
		for (int i = len; i > 0; i--)
		{
			LI::a[i] = str[i0 + len - 1];
			i0--;
		}
		a[len + 1] = 0;
		return 0;
	}
	int LI::convert_to_signmagnitude(const char* str)
	{
		if (!(str[0] == '+' || str[0] == '-' || isdigit(str[0])))
			throw "Incorrcet input";
		int i = 0, j;// j - the beginning index;  i - the ending index
		if (str[0] == '-' || str[0] == '+')
			i = 1;
		int l = strlen(str);
		if (l == i)
			throw "Incorrcet input";

		a[0] = str[0] == '+' || isdigit(str[0]) ? '0' : '9';
		j = insignificant0(str, i);//skip zero
		if (j == l)
		{
			return l;// if str - zero
		}
		while (i < l)//find end's index
		{
			if (!(isdigit(str[i])))
			{
				break;
			}
			i++;
		}
		len = i - j;
		return j;
	}
	int LI::insignificant0(const char* str, int i)const
	{
		int l = strlen(str);
		while (i < l)
		{
			if (str[i] != '0')
			{
				if (!(isdigit(str[i])))
				{
					if (i == 1)
						throw "Incorrcet input";
					return l;
				}
				break;
			}
			i++;
		}
		return i;
	}
	LI::LongInteger(const LongInteger& x)
	{
		try {
			len = x.len;
			a = new char[len + 2];
			for (int i = 0; i < len + 1; ++i)
			{
				a[i] = x.a[i];
			}
			a[len + 1] = 0;
		}
		catch (...) {
			std::cout << "Error of memory. Work empty constructor..." << std::endl;
			a = new char[3];
			a[0] = a[1] = '0';
			len = 1; a[2] = 0;
		}
	}

	LI::LongInteger(long int& a) :LongInteger()
	{
		char sign;
		if (a >= 0)
			sign = '0';
		else
			sign = '9', a = -a;
		int i = 10, k = 1;
		while (a / i > 0)
		{
			i *= 10;
			k++;
		}
		len = k;
		if (len != 1)
		{
			delete[] LI::a;
			LI::a = new char[len + 2];
			while (a > 0)
			{
				LI::a[k] = (char)((int)'0' + a % 10);
				k--;
				a /= 10;
			}
			LI::a[len + 1] = 0;
		}
		this->a[0] = sign;
	}


	const LongInteger LI::operator~() const
	{
		if (a[0] == '0')
			return *this;
		LongInteger res(*this); res.a[0] = '9';
		for (int i = 1; i < len + 1; ++i)
		{
			res.a[i] = (char)((int)'0' + (9 - ((int)a[i] - (int)'0')));
		}
		char* p = new char[len + 2];
		for (int i = 0; i < len + 1; ++i)
		{
			p[i] = '0';
		}
		p[len] = '1', p[len + 1] = 0;
		add_column(res.a, p);
		delete[] p;
		return res;
	}
	const LongInteger LI::operator-()const
	{
		LongInteger b = *this;
		for (int i = 0; i < len + 1; ++i)
			if (a[i] != '0')
			{
				b.a[0] = a[0] == '0' ? '9' : '0';
				break;
			}
		return b;
	}
	LongInteger operator +(const LongInteger& x1, const LongInteger& x2)
	{
		LongInteger cop2(x2), cop1(x1);//Копия в котором будет жить наш доп код
		//We need to addition new memeory if len x1!= len x2
		int k;
		if (x1.len != x2.len)
			if (x1.len > x2.len)
				cop2.change_of_length(x1.len - x2.len);
			else
				cop1.change_of_length(x2.len - x1.len);
		cop1 = ~cop1; cop2 = ~cop2;
		try
		{
			k = cop1.add_column(cop1.a, cop2.a);
		}
		catch (const char* a)
		{
			cop1.len += 1;
			LI b(cop1.a);
			if (cop1.a != nullptr)
				delete[] cop1.a;
			cop1.a = new char[cop1.len + 2];
			for (int i = 2; i < cop1.len + 2; ++i)
				cop1.a[i] = b.a[i - 1];
			cop1.a[1] = '1';
			if (a = "Owerflow1")//situation when overflow '1'
			{
				cop1.a[0] = '0';
			}
			if (a = "Owerflow2")//situation when overflow '18'
			{
				cop1.a[0] = '9';
			}
			return 0;
		}
		cop1 = ~cop1;
		int dif = cop1.insignificant0(cop1.a, 1);
		if (dif - 1 != 0)
			cop1.change_of_length(dif - 1, false);
		return	cop1;
	}
	LI::LongInteger(LongInteger& b, int difference) :len(b.len)
	{
		len += difference;
		a = new char[len + 2];
		a[0] = b.a[0];
		for (int i = 1; i <= difference; i++)
		{
			a[i] = '0';
		}
		for (int i = difference + 1; i < len + 1; i++)
		{
			a[i] = b.a[i - difference];
		}
		a[len + 1] = 0;
	}
	int LI::change_of_length(int difference, bool flag)
	{
		LI b(*this);
		if (a != nullptr)
			delete[]a;
		if (flag)
		{
			len += difference;
			a = new char[len + 2];
			a[0] = b.a[0];
			for (int i = 1; i <= difference; i++)
			{
				a[i] = '0';
			}
			for (int i = difference + 1; i < len + 1; i++)
			{
				a[i] = b.a[i - difference];
			}
			a[len + 1] = 0;
		}
		else
		{
			len -= difference;
			a = new char[len + 2];
			a[0] = b.a[0];
			for (int i = 1; i < len + 1; i++)
			{
				a[i] = b.a[i + difference];
			}
			a[len + 1] = 0;
		}
		return 1;
	}

	const LongInteger LI::operator *(const int th)
	{
		try
		{
			if (th != 10)
				throw "Error multiply";
			LongInteger b = *this;
			if (b.a[1] != '0')
			{
				b.change_of_length(1);
				for (int i = 1; i < b.len + 1; i++)
				{
					b.a[i] = b.a[i + 1];
				}
				b.a[b.len] = '0';
			}
			return b;
		}
		catch (const char* a)
		{
			if (a == "Error multiply")
				std::cout << "Incorrect multiply" << std::endl;
			LI b = *this;
			return b;
		}
	}
	const LongInteger LI::operator /(const int th)
	{
		try
		{
			if (th != 10)
				throw "Error div";
			bool zero = true;
			LongInteger b = *this;
			if (b.a[1] != '0')
			{
				for (int i = len; i > 1; i--) {
					b.a[i] = b.a[i - 1];
					if (zero && (b.a[i] != '0' || b.a[i - 1] != '0'))
						zero = false;
				}
				b.a[1] = '0';
				if (zero)// 0 не должен быть <0 0 -положительный!!!!
					b.a[0] = '0';
				else
					b.change_of_length(1, false);
			}
			return b;
		}
		catch (const char* a)
		{
			if (a == "Error div")
				std::cout << "Incorrect division" << std::endl;
			LI b = *this;
			return b;
		}
	}
	int LI::add_column(char* str1, char* str2) const
	{
		bool flag = false;
		bool zero = true;
		for (int i = len; i > 0; i--)
		{
			int sum = ((int)str1[i] + (int)str2[i] - 2 * (int)'0');
			if (flag)
				sum++;
			flag = false;
			if (!(sum == 0 || sum == 10))
				zero = false;
			if (sum >= 10)
			{
				str1[i] = (char)((int)'0' + (sum - 10));
				flag = true;
			}
			else
				str1[i] = (char)((int)'0' + (sum));
		}
		if (zero)
		{
			str1[0] = '0';
			return 0;
		}
		else
		{
			int sum = ((int)str1[0] + (int)str2[0] - 2 * (int)'0');
			if (flag)
				sum++;
			if (str1[0] == str2[0] && str1[0] == '0' && sum == 1)
				throw "Owerflow";
			if (str1[0] == str2[0] && str1[0] == '9' && sum == 18)
				throw "Owerflow";
			str1[0] = (char)((int)'0' + sum % 10);
		}
		return 1;
	}
	std::istream& operator>>(std::istream& c, LongInteger& x)
	{
		//Разобратсья с вводом
		std::string str;
		std::getline(c, str);
		const char* a = str.c_str();
		int l = strlen(a);
		int j;
		try
		{
			j = x.convert_to_signmagnitude(a);
		}
		catch (const char* a)
		{
			if (a == "Incorrcet input")
			{
				std::cout << "Your number is not correct.The first symbol should be - or + or integer" << std::endl;
			}
			if (a == "Owerflow")
				std::cout << "Your number is not correct.Your number is too big " << std::endl;
			return c;
		}
		char sign = x.a[0];
		if (j != l)
		{
			x.copy_rc(a, j);
			x.a[0] = sign;
		}
		else
			x.a[0] = '0';
		return c;
	}
	std::ostream& operator<<(std::ostream& s, const LongInteger& x)
	{
		if (x.a[0] == '9')
			s << '-';
		if (x.len == 1 && x.a[1]=='0')
			s << '0';
		if (x.a[1] != '0')
		{
			for (int i = 1; i < x.len + 1; ++i)
			{
				s << x.a[i];
			}
		}
		s << std::endl;
		return s;
	}
	const char* LI::getInfo() const
	{
		char* str = new char[len + 2];
		if (a[0] == '9')
		{
			str[0] = '-';
			for (int i = 0; i < len + 1; i++)
				str[i] = a[i];
			str[len + 1] = 0;
			return str;
		}
		for (int i = 0; i < len + 1; i++)
			str[i] = a[i];
		str[len] = 0;
		return str;
	}
	LongInteger& LI::operator=(const LongInteger& other)
	{
		if (this != &other)
		{
			if (a != nullptr)
			{
				delete[] a;
				a = nullptr;
			}
			len = other.len;
			copy_rc(other.a, 1);
			a[0] = other.a[0];

		}
		return *this;
	}
	LongInteger& LI::operator=(LongInteger&& other) noexcept
	{
		if (this != &other)
		{
			if (a != nullptr)
			{
				delete[] a;
				len = other.len;
				a = other.a;
				other.a = nullptr;
				other.len = 0;
			}
		}
		return *this;
	}
}