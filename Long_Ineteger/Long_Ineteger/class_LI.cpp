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
	LI::LongInteger(const char* a)//ѕередаем готовмое число(массив )
	{
		int l = strlen(a);
		if (len_max < l)
			throw "Invalid size. Ovewflow";
		len = l;
		LongInteger();
		//знак -  первый разр€д храним в пр€мом коде!!
		if (a[0] == '+' || a[0] == '-' || (((int)a[0] >= 48) && ((int)a[0] <= 57)))//проверка числа
		{
			if (a[0] == '+' || (((int)a[0] >= 48) && ((int)a[0] <= 57)))
			{
				LI::a[0] = '0';
			}
			else
			{
				LI::a[0] = '9';
			}
		}
		else
			throw "Incorrect number";
		// опировка
		for (int i = len_max + 1; i > 0; i--)
		{
			l--;
			if (l == 0)
			{
				if ((((int)a[0] >= 48) && ((int)a[0] <= 57)))
				{
					LI::a[i] = a[0], len = strlen(a);
						break;
				}
				len = strlen(a) - 1;// + или минус в начале
				break;
			}
			LI::a[i] = a[l];
			l--;
		}
	}
	LI::LongInteger(int& a)
	{
		//п–о¬е–ка на Overflow	
		int i = 10, k  = 1;
		while (a / i > 0)
		{
			i *= 10;
			k++;
		}
		if (k > len_max)
			throw "Invalid size. Ovewflow";
		if (a > 0)
			LI::a[0] = '0';
		else
			LI::a[0] = '9';
		int SZ = len_max + 1;
		while (a > 0)
		{
			LI::a[SZ] = (char)((int)'0' + a % 10);
			SZ--;
			a /= 10;
		}
		for (int j = 1; j < SZ; ++j)
			LI::a[j] = '0';
		len = len_max + 1 - SZ;
	}	
	LI::LongInteger(long int& a)
	{
		//п–о¬е–ка на Overflow	
		int i = 10, k = 1;
		while (a / i > 0)
		{
			i *= 10;
			k++;
		}
		if (k > len_max)
			throw "Invalid size. Ovewflow";
		if (a > 0)
			LI::a[0] = '0';
		else
			LI::a[0] = '9';
		int SZ = len_max + 1;
		while (a > 0)
		{
			LI::a[SZ] = (char)((int)'0' + a % 10);
			SZ--;
			a /= 10;
		}
		for (int j = 1; j < SZ; ++j)
			LI::a[j] = '0';
		len = len_max + 1 - SZ;
	}

}