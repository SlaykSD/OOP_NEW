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
		int AddColumn(char*, char*, int k = len_max, bool = false)const;
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
		char* getInfo() const;
		std::ostream& Output(std::ostream&) const;//������
		std::istream& Input(std::istream&);//����� 
		//����������� �����
		LongInteger& add(const LongInteger&, bool flag = false);
		LongInteger& sub(const LongInteger&) { add(a, true); }
		LongInteger& DIV();
		LongInteger& Multiply10();

		
	};
}
