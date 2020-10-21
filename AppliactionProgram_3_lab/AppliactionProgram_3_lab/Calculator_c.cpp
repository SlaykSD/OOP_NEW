#pragma once
#include "Calculator_c.h"
#include <vector>

namespace BigInteger
{
	const char* msgs[] = { "0-> Exit",
"1->  +",
"2->  -",
"3-> increase by 10",
"4-> decrease by 10",
"5-> Look",
"6-> Set" };
	const int Nmsgs = sizeof(msgs) / sizeof(msgs[0]);
	int getInt(int* a) {
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
	void Observable::notifyUpdate()
	{
		int size = _obeserves.size();
		for (int i = 0; i < size; i++)
		{
			_obeserves[i]->update();
		}
	}
	BigIntModel& BigIntModel::setBigInt(BigInt& tmp)
	{
		_curr = tmp;
		notifyUpdate();
		return *this;
	}
	consoleView::consoleView(BigIntModel* model)
	{
		_model = model;
		_model->addObserver(this);
	}
	void consoleView::update()
	{
		std::cout << "Current number: ";
		std::cout << _model->getBigInt() << std::endl;
		menu();
	}
	void consoleView::menu()const
	{
		for (int j = 0; j < Nmsgs; ++j)
			puts(msgs[j]);
		puts("Make your choice: --> ");
	}
	int Controller::start()
	{
		BigInt Big;
		_model->setBigInt(Big);
		int command = 1;
		while (command)
		{
			//There should be mas of function expedcy by rc
			command = getCommand();
			if (command == 0)
				return 0;
			switch (command)
			{
			case 1:
				dialog_pos(Big);
				break;
			case 2:
				dialog_neg(Big);
				break;
			case 3:
				dialog_m10(Big);
				break;
			case 4:
				dialog_d10(Big);
				break;
			case 6:
				dialog_set(Big);
				break;
			default:
				break;
			}
			_model->setBigInt(Big);
		}
		return 0;
	}
	int Controller::getCommand(void)const
	{
		int rc;
		const char* err = "";
		do {
			_view->inform(err);
			getInt(&rc);
			err = "You are wrong. Repeat, please\n";
		} while (rc < 0 || rc >= Nmsgs);
		return rc;
	}
	using std::cout;
	using std::cin;
	using std::endl;
	int Controller::dialog_pos(BigInt& BIG)
	{
		_view->inform("Input the number you will add: ");
		BigInt cry;
		std::cin >> cry;
		BIG += cry;
		return 1;
	}
	int Controller::dialog_neg(BigInt& BIG)
	{
		_view->inform("Input the number you will sub: ");
		BigInt cry;
		std::cin >> cry;
		BIG -= cry;
		return 1;
	}
	int Controller::dialog_m10(BigInt& BIG)
	{
		_view->inform("Multiply your multiply by 10: ");
		BIG = BIG * 10;
		return 1;
	}
	int Controller::dialog_d10(BigInt& BIG)
	{
		_view->inform("Your division number by 10: ");
		BIG = BIG / 10;
		return 1;
	}
	int Controller::dialog_set(BigInt& BIG)
	{
		_view->inform("Input big number-> ");
		std::cin >> BIG;
		return 1;
	}
}