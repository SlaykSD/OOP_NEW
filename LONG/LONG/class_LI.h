#pragma once
#include <iostream>
namespace LInteger
{
	class LongInteger
	{
	private:
		int len;
		int static const len_max = 50;
		char* Invers(char*)const;
		int AddColumn(char*, char*, int k = len_max, bool flag = false, bool zero = true)const;
		const int auto_len();
		char a[len_max+1];//+1 �� ���� �����
	public:
		//Constructors
		LongInteger();//������ ������������
		LongInteger(const char* a);//����������� ��� ����� 
		LongInteger(int& a);
		LongInteger(long int& a);
		LongInteger(const LongInteger&);
		//�������+ ������
		int getlen() const { return len; }
		const char* getInfo(char*) const;
		std::ostream& Output(std::ostream&) const;//������
		std::istream& Input(std::istream&);//����� 
		//����������� �����
		LongInteger& add(const LongInteger&, bool flag = false);
		LongInteger& sub(const LongInteger& x) 
		{ 
			add(x, true);
			return *this; 
		}
		LongInteger& DIV();
		LongInteger& Multiply10();

	};
}
