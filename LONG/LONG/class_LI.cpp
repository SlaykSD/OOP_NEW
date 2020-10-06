#include "class_LI.h"
#include <string.h>
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
	//ѕофиксить 
	LI::LongInteger(const char* a) : LongInteger()//ѕередаем готовмое число(массив )
	{
		int l = strlen(a);
		int j;
		try 
		{
			j = correct(a);
		}
		catch (const char* a)
		{
			if (a == "Incorrcet input")
				std::cout << "Your number is nor correct.The first symbol should be - or + or integer" << std::endl;
			if (a == "Owerflow")
				std::cout << "Your number is nor correct.Your number is too big " << std::endl;
		}
		if (j != l)
			copy_rc(a , j);
		else LI::a[0] = '0';
	}
	int LI::copy_rc(const char* str, int i0)
	{
		for (int i = len_max; i > len_max - len; i--)
		{
			LI::a[i] = str[i0 +len -1];
			i0--;
		}
		return 0;
	}
	int LI::correct(const char* str)
	{
		if (!(str[0] == '+' || str[0] == '-' || (((int)str[0] >= (int)'0') && ((int)str[0] <= (int)'9'))))
			throw "Incorrcet input";
		int i = 0, j = 0;
		if (str[0] == '-' || str[0] == '+')
			i = 1;
		if (str[0] == '+' || (((int)str[0] >= 48) && ((int)str[0] <= 57)))
		{
			a[0] = '0';
		}
		else
		{
			a[0] = '9';
		}
		int l = strlen(str);
		j = insignificant0(str, i);
		if (j == l)
			return l;
		while (i < l)
		{
			if (!(((int)str[i] >= 48) && ((int)str[i] <= 57)))
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
		while (i < l)
		{
			if (str[i] != '0')
			{
				if (!(((int)str[i] >= 48) && ((int)str[i] <= 57)))
				{
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
	LI::LongInteger(int& a) :LongInteger()
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
	const char* LI::getInfo(char* str) const
	{
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
	std::ostream& LI::Output(std::ostream& s) const
	{
		if (a[0] == '9')
			s << '-';
		if (len == 0)
			s << '0';
		for (int i = len_max + 1 - len; i < len_max + 1; ++i)
		{
			s << a[i];
		}
		s << std::endl;
		return s;
	}
	std::istream& LI::Input(std::istream& c)
	{
		char a[len_max + 1];
		c >> a;
		int l = strlen(a);
		int j;
		try
		{
			j = correct(a);
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
		return c;
	}
	const int LI::auto_len()
	{
		int i = 1;
		while (a[i] == '0')
			i++;
		len = len_max + 1 - i;
		return len;
	}
	LongInteger& LI::add(const LongInteger& x, bool fl)
	{
		char* arr = new char[len + 2];//1 идет на \0 второй на знак
		char* arr2 = new char[x.getlen() + 2];//1 идет на \0 второй на знак
		x.getInfo(arr2);
		if (fl)
		{
			if (a[0] == '0')
				a[0] = '9';
			else
				a[0] = '0';
		}
		getInfo(arr);
		LongInteger cop2(arr2);// опи€ в котором будет жить наш доп код
		LongInteger cop1(arr);
		delete[] arr;
		delete[] arr2;
		Invers(cop1.a), Invers(cop2.a);
		int k;
		try
		{
			k = AddColumn(cop1.a, cop2.a);
		}
		catch (const char* a)
		{
			if (a = "Owerflow")
				std::cout << "Error in AddColumn. Max size:" << len_max << "!!!!!" << std::endl;
			return *this;
		}
		Invers(cop1.a), cop1.auto_len();
		len = cop1.len;
		for (int i = 0; i < len_max + 1; i++)
			a[i] = cop1.a[i];
		if (fl && k)
		{
			if (a[0] == '0')
				a[0] = '9';
			else
				a[0] = '0';
		}
		return	*this;
	}
	char* LI::Invers(char* str) const//функци€ дл€ перевода в доп код
	{
		if (str[0] == '9')
		{
			for (int i = 1; i < len_max + 1; ++i)
			{
				str[i] = (char)((int)'0' + (9 - ((int)str[i] - (int)'0')));
			}
			//+1?
			char arr[len_max + 2];
			char* p = &arr[0];
			for (int i = 0; i < len_max; ++i)
			{
				arr[i] = '0';
			}
			arr[len_max] = '1', arr[len_max + 1] = 0;
			AddColumn(str, p, len_max, false);
		}
		return str;
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
	LongInteger& LI::DIV()//‘ункци€ делени€ на 10(цела€ часть)
	{
		bool zero = true;
		for (int i = len_max; i > 1; i--) {
			a[i] = a[i - 1];
			if (zero && (a[i] != '0' || a[i - 1] != '0'))
				zero = false;
		}
		a[1] = '0';
		if (zero)// 0 не должен быть <0 0 -положительный!!!!
			a[0] = '0';
		else
			len--;
		return *this;
	}
	LongInteger& LI::Multiply10()
	{
		if (a[1] != '0')
			throw "Owerflow";
		len++;
		for (int i = 1; i < len_max; i++)
		{
			a[i] = a[i + 1];
		}
		a[len_max] = '0';
		return *this;
	}

}