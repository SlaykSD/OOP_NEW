// LONG_B.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Operation.h"
#include <limits>

const char* msgs[] = { "0-> Exit",
"1-> get two's complement", //Addition code 
"2-> operator +",
"3-> operator -",
"4-> increase by 10",
"5-> decrease by 10",
"6-> Look at the biggest number in the world",
"7-> Set number" };
const char* INmsgs[] = { "0-> Nothing input",
"1-> Input string" ,
"2-> Input long int" };
const int Nmsg = sizeof(msgs) / sizeof(msgs[0]);
const int InN = sizeof(INmsgs) / sizeof(INmsgs[0]);
int(*operation[])(LInteger::LongInteger&) = { nullptr,
LInteger::dialog_ts,
LInteger::dialog_pos,
LInteger::dialog_neg,
LInteger::dialog_m10,
LInteger::dialog_d10,
LInteger::dialog_fun,
LInteger::dialog_set };

namespace LInteger
{
	using LI = LongInteger;
	using std::cout;
	using std::endl;

	int getN_Int(int* a) {
		bool good = true;
		do
		{
			std::cin >> *a;
			if (!(good = std::cin.good()))
				std::cout << "Error! Please, repeat your input(INTEGER): ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (!good);
		return 1;
	}
	int getN_Int(long int* a) {
		bool good = true;
		do
		{
			std::cin >> *a;
			if (!(good = std::cin.good()))
				std::cout << "Error! Please, repeat your input(LONG INTEGER): ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (!good);
		return 1;
	}
	int dialog(const char* msgs[], int N)
	{
		const char* errmsg = "";
		int rc, n;
		do {
			std::cout << errmsg;
			errmsg = "You are wrong. Repeat, please\n";
			for (int j = 0; j < N; ++j)
				puts(msgs[j]);
			puts("Make your choice: --> ");

			n = getN_Int(&rc);
			if (n == 0)
				rc = 0;
		} while (rc < 0 || rc >= N);
		return rc;
	}
	int dialog_ts(LongInteger& BIG)
	{
		cout << "Your twos compliment equal = ";
		LI res = ~BIG;
		cout << res.getSignMagnitude() << endl;
		return 1;
	}
	int dialog_pos(LongInteger& BIG)
	{
		cout << "Input the number you will add: ";
		LI cry;
		std::cin >> cry;
		BIG += cry;
		cout << "Current the number: "<< BIG << endl;
		return 1;
	}
	int dialog_neg(LongInteger& BIG)
	{
		cout << "Input the number you will sub: ";
		LI cry;
		std::cin >> cry;
		BIG -= cry;
		cout << "Caurrent the number: " << BIG << endl;
		return 1;
	}
	int dialog_m10(LongInteger& BIG)
	{
		cout << "Multiply your multiply by 10: ";
		BIG = BIG * 10;
		cout << BIG << endl;
		return 1;
	}
	int dialog_d10(LongInteger& BIG)
	{
		cout << "Your division number by 10: ";
		BIG = BIG / 10;
		cout << BIG << endl;
		return 1;
	}
	int dialog_fun(LongInteger& BIG)
	{
		cout << "Current the number:" << BIG <<endl;
		return 1;
	}
	int dialog_set(LongInteger& BIG)
	{
		const char* errmsg = "";
		int rc, n;
		do {
			std::cout << errmsg;
			errmsg = "You are wrong. Repeat, please\n";
			for (int j = 0; j < InN; ++j)
				puts(INmsgs[j]);
			puts("Make your choice: --> ");
			n = getN_Int(&rc);
			if (n == 0)
				rc = 0;
		} while (rc < 0 || rc >= InN);
		if(rc!=0)
			cout << "Input big number-> ";
		if (rc == 2)
		{
			long int ff;
			if (!getN_Int(&ff))
				return 0;
			LI res2(ff);
			BIG = (res2);
		}
		LI res;
		switch (rc)
		{
		case 0:
			BIG = res;
			break;
		case 1:
			std::cin >> BIG;
			break;
		default:
			break;
		}
		return 1;
	}
}
int main()
{

	LInteger::LongInteger BIG;
	int rc = 0;
	LInteger::dialog_set(BIG);
	while (rc = LInteger::dialog(msgs, Nmsg))
		if (!operation[rc](BIG))
			break;
	return 0;
}

