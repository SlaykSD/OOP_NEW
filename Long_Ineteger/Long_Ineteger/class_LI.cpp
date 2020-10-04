#include "class_LI.h"
#include <string.h>
namespace LInteger
{
	using LI = LongInteger;
	LI::LongInteger() :len(0)//������ ������������
	{
		for (int i = 0; i < len_max + 1; ++i)
		{
			a[i] = '0';
		}
	}
	LI::LongInteger(const char* a): LongInteger()//�������� �������� �����(������ )
	{
		int l = strlen(a);
		if (len_max < l)
			throw "Invalid size. Ovewflow";
		//���� -  ������ ������ ������ � ������ ����!!
		if (a[0] == '+' || a[0] == '-' || (((int)a[0] >= (int)'0') && ((int)a[0] <= (int)'9')))//�������� �����
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
		//���������
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
				len = strlen(a) - 1;// + ��� ����� � ������
				break;
			}
			LI::a[i] = a[l];
			l--;
		}
	}
	LI::LongInteger(const LongInteger& x)
	{
		for (int i = 0; i < len_max + 1; ++i)
			LI::a[i] = x.a[i];
		len = x.getlen();
	}
	LI::LongInteger(int& a):LongInteger()
	{
		//�������� �� Overflow	
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
	LI::LongInteger(long int& a):LongInteger()
	{
		//�������� �� Overflow	
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
		len = len_max + 1 - SZ;
	}
	char* LI::getInfo() const
	{
		char* str = new char[len + 1];
		if (a[0] == '9')
		{
			str[0] = '-';
			for (int i = len_max + 1 - len; i < len_max + 1; i++)
				str[i - (len_max - len)] = a[i];
			return str;
		}
		for (int i = len_max + 1 - len; i < len_max + 1; i++)
			str[i - (len_max+1 - len)] = a[i];
		return str;
	}
	std::ostream& LI::Output(std::ostream& s) const
	{
		if (a[0] == '9')
			s << '-';
		for (int i = len_max - len; i < len_max + 1; ++i)
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
		if (len_max < l)
			throw "Invalid size. Ovewflow";
		if ((l - (a[0] == '-' ? 1 : 0)) != strspn(a + (a[0] == '-' ? 1 : 0), "0123456789"))
			throw "Data error!";
		//���� -  ������ ������ ������ � ������ ����!!
		if (a[0] == '+' || a[0] == '-' || (((int)a[0] >= (int)'0') && ((int)a[0] <= (int)'9')))//�������� �����
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
		//���������
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
				len = strlen(a) - 1;// + ��� ����� � ������
				break;
			}
			LI::a[i] = a[l];
			l--;
		}
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
	LongInteger& LI::add(const LongInteger& x, bool flag) 
	{
		char* arr2 = x.getInfo();
		if (!flag)
		{
			if (x.a[0] == '0')
				arr2[0] = '9';
			else
				arr2[0] = '0';
		}
			LongInteger cop2(arr2);//����� � ������� ����� ���� ��� ��� ���
			char* arr = getInfo();
			LongInteger cop1(arr);
			delete[] arr;
			delete[] arr2;
			Invers(cop1.a), Invers(cop2.a);
			try
			{
				AddColumn(cop1.a, cop2.a);
			}
			catch (std::exception)
			{
				std::cout << "Error in AddColumn" << std::endl;
				return *this;
			}
			Invers(cop1.a), cop1.auto_len();
			len = cop1.len;
			for (int i = 0; i < len_max + 1; i++)
				a[i] = cop1.a[i];
			return	*this;	
	}
	char* LI::Invers(char* str) const//������� ��� �������� � ��� ���
	{
		if (str[0] == '9')
		{
			for (int i = 1; i < len_max + 1; ++i)
			{
				str[i] = (char)((int)'0' + (9 - ((int)LI::a[0])));
			}
			//+1?
			char arr[len_max+1];
			char* p = &arr[0];
			for (int i = 0; i < len_max ; ++i)
			{
				arr[i] = '0';
			}
			arr[len_max] = '1';
			AddColumn(str, p, len_max, false);
		}
		return str;
	}
	int LI::AddColumn(char* str1, char* str2, int k, bool flag) const
	{
		if (k > 0)
		{
			k--;
			int sum = ((int)str1[k] + (int)str2[k] - 2 * (int)'0');
			if (flag)//� ������ � ������� �������� ��������� 1(�� ������� ��������)
				sum++;
			flag = false;
			if (sum >= 10)
			{
				str1[k] = (char)((int)'0' + (10 - sum));
				flag = true;
			}
			else
				str1[k] = (char)((int)'0' + (sum));
			AddColumn(str1, str2, k, flag);
		}
		else
		{
			int sum = ((int)str1[k] + (int)str2[k] - 2 * (int)'0');
			if (flag)//� ������ � ������� �������� ��������� 1(�� ������� ��������)
				sum++;
			if (str1[0] == str2[0] && flag)
			{
				//������������
				throw "Oweflow";
			}
			else
			{
				if (sum == 10)
					str1[0] = '0';
				if (sum == 18)
					str1[0] = '9';
				if(sum<10)
					str1[0] = (char)((int)'0' + (sum));
			}
			return 0;
		}
	}
	LongInteger& LI::DIV()//������� ������� �� 10(����� �����)
	{
		bool zero = true;
		for (int i = len_max; i > 1; i--) {
			a[i] = a[i - 1];
			if (zero && (a[i] != '0' || a[i - 1] != '0'))
				zero = false;
		}
		a[1] = '0';
		if (zero)// 0 �� ������ ���� <0 0 -�������������!!!!
			a[0] = '0';
		return *this;
	}
	LongInteger& LI::Multiply10()
	{
		if (a[1] != 0)
			throw "Owerflow";
		for (int i = 1; i < len_max; i++)
		{
			a[i] = a[i + 1];
		}
		a[len_max] = '0';
		return *this;
	}

}