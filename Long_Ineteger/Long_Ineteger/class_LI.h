#pragma once
namespace LInteger
{
	class LongInteger
	{
	private:
		int len;
		int static const len_max = 50;
		char a[len_max+1];//+1 �� ���� �����
	public:
		LongInteger();//������ ������������
		LongInteger(const char* a);//����������� ��� ����� 
		LongInteger(int& a);
		LongInteger(long int& a);

	};
}
