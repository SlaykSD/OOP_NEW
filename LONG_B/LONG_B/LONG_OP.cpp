#include "LONG_OP.h"
#include <cctype> 

namespace LInteger
{
	using LI = LongInteger;
	LI::LongInteger() :len(0)//ѕустой конструктоор
	{
		for (int i = 0; i < len_max + 1; ++i)
		{
			a[i] = '0';
		}
	}
	const int LI::auto_len()
	{
		int i = 1;
		while (a[i] == '0')
			i++;
		len = len_max + 1 - i;
		return len;
	}
	LI::LongInteger(const char* a) : LongInteger()//ѕередаем готовмое число(массив )
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
				std::cout << "Your number is nor correct.The first symbol should be - or + or integer" << std::endl;
			if (a == "Owerflow")
				std::cout << "Your number is nor correct.Your number is too big " << std::endl;
		}
		if (j != l)
			copy_rc(a, j);
		else LI::a[0] = '0';
	}
	int LI::copy_rc(const char* str, int i0)
	{
		for (int i = len_max; i > len_max - len; i--)
		{
			LI::a[i] = str[i0 + len - 1];
			i0--;
		}
		return 0;
	}
	int LI::convert_to_signmagnitude(const char* str)
	{
		if (!(str[0] == '+' || str[0] == '-' || isdigit(str[0])))
			throw "Incorrcet input";
		int i = 0, j = 0;
		if (str[0] == '-' || str[0] == '+')
			i = 1;
		a[0] = str[0] == '+' || isdigit(str[0]) ? '0' : '9';
		int l = strlen(str);
		j = insignificant0(str, i);
		if (j == l)
			return l;
		while (i < l)
		{
			if (!(isdigit(str[i])))
			{
				break;
			}
			i++;
		}
		if (i - j > len_max)
			throw "Owerflow";
		len = i - j;
		return j;
	}
	int LI::insignificant0(const char* str, int i)
	{
		int l = strlen(str);
		if (l == 1)
			throw "Incorrcet input";
		while (i < l)
		{
			if (str[i] != '0')
			{
				if (!(isdigit(str[i])))
				{
					if (i == 1)
						throw "Incorrcet input";
					len = 0;
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
		for (int i = 0; i < len_max + 1; ++i)
			LI::a[i] = x.a[i];
		len = x.getlen();
	}

	LI::LongInteger(long int& a) :LongInteger()
	{
		//п–о¬е–ка на Overflow	
		if (a > 0)
			LI::a[0] = '0';
		else
			LI::a[0] = '9', a = -a;
		int i = 10, k = 1;
		while (a / i > 0)
		{
			i *= 10;
			k++;
		}
		if (k > len_max)
			throw "Invalid size. Ovewflow";
		int SZ = len_max;
		while (a > 0)
		{
			LI::a[SZ] = (char)((int)'0' + a % 10);
			SZ--;
			a /= 10;
		}
		len = len_max - SZ;
	}


	const LongInteger LI::operator~() const
	{
		if (a[0] == '0')
			return *this;
		LongInteger res; res.a[0] = '9';
		for (int i = 1; i < len_max + 1; ++i)
		{
			res.a[i] = (char)((int)'0' + (9 - ((int)a[i] - (int)'0')));
		}
		//+1?
		char arr[len_max + 2];
		char* p = &arr[0];
		for (int i = 0; i < len_max; ++i)
		{
			arr[i] = '0';
		}
		arr[len_max] = '1', arr[len_max + 1] = 0;
		AddColumn(res.a, p, len_max, false);
		res.auto_len();
		return res;
	}
	const LongInteger LI::operator-()const
	{
		LongInteger b = *this;
		for(int i=0;i<len_max+1;++i)
			if (a[i] !='0' )
			{
				b.a[0] = a[0] == '0' ? '9' : '0';
				break;
			}
		return b;
	}
	LongInteger operator +(const LongInteger& x1, const LongInteger& x2)
	{
		LongInteger cop2(~x2),cop1(~x1);// опи€ в котором будет жить наш доп код
		int k;
		try
		{
			k = x1.AddColumn(cop1.a, cop2.a);
		}
		catch (const char* a)
		{
			if (a = "Owerflow")
				std::cout << "Error in AddColumn. Max size:" << x1.len_max << "!!!!!" << std::endl;
			return 0;
		}
		cop1 = ~cop1, cop1.auto_len();
		return	cop1;
	}
	const LongInteger LI::operator *(const int th)
	{
		try
		{
			if (th != 10)
				throw "Error multiply";
			if (a[1] != '0')
				throw "Owerflow";
			LongInteger b = *this;
			b.len = len + 1;
			for (int i = 1; i < len_max; i++)
			{
				b.a[i] = b.a[i + 1];
			}
			b.a[len_max] = '0';
			return b;
		}
		catch (const char* a)
		{
			if (a == "Error multiply")
				std::cout << "Incorrect multiply" << std::endl;
			if (a == "Owerflow")
				std::cout << "Your number takes up all space" << std::endl;
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
			for (int i = len_max; i > 1; i--) {
				b.a[i] = b.a[i - 1];
				if (zero && (b.a[i] != '0' || b.a[i - 1] != '0'))
					zero = false;
			}
			b.a[1] = '0';
			if (zero)// 0 не должен быть <0 0 -положительный!!!!
				b.a[0] = '0';
			else
				b.len--;
			return b;
		}
		catch (const char*a)
		{
			if (a == "Error div")
				std::cout << "Incorrect division" << std::endl;
			LI b = *this;
			return b;
		}
	}
	int LI::AddColumn(char* str1, char* str2, int k, bool flag, bool zero) const
	{
		if (k > 0)
		{
			int sum = ((int)str1[k] + (int)str2[k] - 2 * (int)'0');
			if (flag)//в случае в прошлом сложении добавл€ем 1(по правилу столбика)
				sum++;
			flag = false;
			if (!(sum == 0 || sum == 10))
				zero = false;
			if (sum >= 10)
			{
				str1[k] = (char)((int)'0' + (sum - 10));
				flag = true;
			}
			else
				str1[k] = (char)((int)'0' + (sum));
			k--;
			AddColumn(str1, str2, k, flag, zero);
		}
		else
		{
			if (zero)
			{
				str1[0] = '0';
				return 0;
			}
			else
			{
				int sum = ((int)str1[k] + (int)str2[k] - 2 * (int)'0');
				if (flag)//в случае в прошлом сложении добавл€ем 1(по правилу столбика)
					sum++;
				if (str1[0] == str2[0] && str1[0] == '0' && sum == 1)
					throw "Owerflow";
				if (str1[0] == str2[0] && str1[0] == '9' && sum == 18)
					throw "Owerflow";
				str1[0] = (char)((int)'0' + sum % 10);
			}
			return 1;
		}
	}
	std::istream& operator>>(std::istream& c,LongInteger& x)
	{
		char a[x.len_max + 1];
		c >> a;
		int l = strlen(a);
		int j;
		try
		{
			j = x.convert_to_signmagnitude(a);
		}
		catch (const char* a)
		{
			if (a == "Incorrcet input")
				std::cout << "Your number is nor correct.The first symbol should be - or + or integer" << std::endl;
			if (a == "Owerflow")
				std::cout << "Your number is nor correct.Your number is too big " << std::endl;
			return c;
		}
		if (j != l)
			x.copy_rc(a, j);
		else x.a[0] = '0';
		return c;
	}
	std::ostream& operator<<(std::ostream& s, const LongInteger& x)
	{
		if (x.a[0] == '9')
			s << '-';
		if (x.len == 0)
			s << '0';
		for (int i = x.len_max + 1 - x.len; i < x.len_max + 1; ++i)
		{
			s << x.a[i];
		}
		s << std::endl;
		return s;
	}
	const char* LI::getInfo() const
	{
		char str[len_max + 2];
		if (a[0] == '9')
		{
			str[0] = '-';
			for (int i = len_max + 1 - len; i < len_max + 1; i++)
				str[i - (len_max - len)] = a[i];
			str[len + 1] = 0;
			return str;
		}
		for (int i = len_max + 1 - len; i < len_max + 1; i++)
			str[i - (len_max + 1 - len)] = a[i];
		str[len] = 0;
		return str;
	}

}