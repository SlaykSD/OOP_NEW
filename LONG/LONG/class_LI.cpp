#include "class_LI.h"
#include <string.h>
#include <cctype>

namespace LInteger
{
	using LI = LongInteger;
	LI::LongInteger() :len(0)//Пустой конструктоор
	{
		for (int i = 0; i < LEN_MAX + 1; ++i)
		{
			a[i] = '0';
		}
	}
	LI::LongInteger(const char* a) : LongInteger()//Передаем готовмое число(массив )
	{
		int l = strlen(a);
		int j;
		try
		{
			j = convert_to_signmagnitude(a);
			if (j != l)
				copy_rc(a, j);
			else LI::a[0] = '0';
		}
		catch (const char* a)
		{
			if (a == "Incorrect input")
				std::cout << "Your number is not correct.The first symbol should be - or + or integer" << std::endl;
			if (a == "Owerflow")
				std::cout << "Your number is not correct.Your number is too big " << std::endl;
		}
	}
	int LI::copy_rc(const char* str, int i0)
	{
		for (int i = LEN_MAX; i > LEN_MAX - len; i--)
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
		int i = 0, j;
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
		if (i - j > LEN_MAX)
			throw "Owerflow";
		len = i - j;
		return j;
	}
	int LI::insignificant0(const char* str, int i)
	{
		int l = strlen(str);
		if (l == 1)
			throw "Incorrect input";
		while (i < l)
		{
			if (str[i] != '0')
			{
				if (!(isdigit(str[i])))
				{
					if (i == 1)
						throw "Incorrect input";
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
		for (int i = 0; i < LEN_MAX + 1; ++i)
			LI::a[i] = x.a[i];
		len = x.getlen();
	}
	LI::LongInteger(int& a) :LongInteger()
	{
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
		if (k > LEN_MAX)
			throw "Invalid size. Ovewflow";
		int SZ = LEN_MAX;
		while (a > 0)
		{
			LI::a[SZ] = (char)((int)'0' + a % 10);
			SZ--;
			a /= 10;
		}
		len = LEN_MAX - SZ;
	}
	LI::LongInteger(long int& a) :LongInteger()
	{
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
		if (k > LEN_MAX)
			throw "Invalid size. Ovewflow";
		int SZ = LEN_MAX;
		while (a > 0)
		{
			LI::a[SZ] = (char)((int)'0' + a % 10);
			SZ--;
			a /= 10;
		}
		len = LEN_MAX - SZ;
	}
	const char* LI::getInfo(char* str) const
	{
		if (a[0] == '9')
		{
			str[0] = '-';
			for (int i = LEN_MAX + 1 - len; i < LEN_MAX + 1; i++)
				str[i - (LEN_MAX - len)] = a[i];
			str[len + 1] = 0;
			return str;
		}
		for (int i = LEN_MAX + 1 - len; i < LEN_MAX + 1; i++)
			str[i - (LEN_MAX + 1 - len)] = a[i];
		str[len] = 0;
		return str;
	}
	std::ostream& LI::output(std::ostream& s) const
	{
		if (a[0] == '9')
			s << '-';
		if (len == 0)
			s << '0';
		for (int i = LEN_MAX + 1 - len; i < LEN_MAX + 1; ++i)
		{
			s << a[i];
		}
		s << std::endl;
		return s;
	}
	std::istream& LI::input(std::istream& c)
	{
		char a[LEN_MAX + 1];
		c >> a;
		int l = strlen(a);
		int j;
		try
		{
			j = convert_to_signmagnitude(a);
		}
		catch (const char* a)
		{
			if (a == "Incorrect input")
				std::cout << "Your number is not correct.The first symbol should be - or + or integer" << std::endl;
			if (a == "Owerflow")
				std::cout << "Your number is not correct.Your number is too big " << std::endl;
			return c;
		}
		if (j != l)
			copy_rc(a, j);
		else LI::a[0] = '0';
		return c;
	}
	const int LI::auto_len()
	{
		int i = 1;
		while (a[i] == '0')
			i++;
		len = LEN_MAX + 1 - i;
		return len;
	}
	LongInteger& LI::add(const LongInteger& x, bool fl)
	{
		char* arr = new char[len + 2];
		char* arr2 = new char[x.getlen() + 2];
		x.getInfo(arr2);
		if (fl)
		{
			a[0] = a[0] == '0' ? '9' : '0';
		}
		getInfo(arr);
		LongInteger cop2(arr2);LongInteger cop1(arr);
		delete[] arr;
		delete[] arr2;
		compute_invers(cop1.a), compute_invers(cop2.a);
		int k;
		try
		{
			k = add_column(cop1.a, cop2.a);
		}
		catch (const char* a)
		{
			if (a == "Owerflow")
				std::cout << "Error in AddColumn. Max size:" << LEN_MAX << "!!!!!" << std::endl;
			return *this;
		}
		compute_invers(cop1.a), cop1.auto_len();
		len = cop1.len;
		for (int i = 0; i < LEN_MAX + 1; i++)
			a[i] = cop1.a[i];
		if (fl && k)
		{
			a[0] = a[0] == '0' ? '9' : '0';
		}
		return	*this;
	}
	char* LI::compute_invers(char* str) const
	{
		if (str[0] == '9')
		{
			for (int i = 1; i < LEN_MAX + 1; ++i)
			{
				str[i] = (char)((int)'0' + (9 - ((int)str[i] - (int)'0')));
			}
			char arr[LEN_MAX + 2];
			char* p = &arr[0];
			for (int i = 0; i < LEN_MAX; ++i)
			{
				arr[i] = '0';
			}
			arr[LEN_MAX] = '1', arr[LEN_MAX + 1] = 0;
			add_column(str, p);
		}
		return str;
	}
	int LI::add_column(char* str1, char* str2) const
	{
		bool flag = false;
		bool zero = true;
		for (int i = LEN_MAX; i > 0; i--)
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
	LongInteger& LI::div()
	{
		bool zero = true;
		for (int i = LEN_MAX; i > 1; i--) {
			a[i] = a[i - 1];
			if (zero && (a[i] != '0' || a[i - 1] != '0'))
				zero = false;
		}
		a[1] = '0';
		if (zero)
		{
			a[0] = '0';
			if (len > 0)
				len = 0;
		}
		else
			len--;
		return *this;
	}
	LongInteger& LI::multiply10()
	{
		if (a[1] != '0')
			throw "Owerflow";
		len++;
		for (int i = 1; i < LEN_MAX; i++)
		{
			a[i] = a[i + 1];
		}
		a[LEN_MAX] = '0';
		return *this;
	}

}