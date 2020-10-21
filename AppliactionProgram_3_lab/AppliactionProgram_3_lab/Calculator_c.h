
#pragma once
#include <vector>
#include "BigInt.h"
namespace BigInteger {
	int getInt(int* a);
	//absttract class which is observe changes
	class Observer
	{
	public:
		virtual void update() = 0;
	};

	class Observable
	{
	private:
		std::vector<Observer*> _obeserves;
	public:
		void addObserver(Observer* Observer)
		{
			_obeserves.push_back(Observer);
		}
		void notifyUpdate();
	};
	/////////////////// MODEL
	class BigIntModel :public Observable
	{
	public:
		BigIntModel(BigInt curr) :_curr(curr) {};
		BigInt getBigInt()const { return _curr; };
		BigIntModel& setBigInt(BigInt& tmp);
	private:
		BigInt _curr;
	};
	//////////////////VIEW
	class consoleView : public Observer
	{
	public:
		consoleView(BigIntModel* model);
		virtual void update();
		void inform(const char* msgs)const
		{
			std::cout << msgs;
		}
	private:
		void menu()const;
		BigIntModel* _model;
	};
	/////////////////CONTROLLER
	class Controller 
	{
	public:
		Controller(BigInt& tmp, consoleView *view):_view(view)
		{
			_model->setBigInt(tmp);
		}
		Controller(BigIntModel* tmp, consoleView* view) :_model(tmp), _view(view) { ; }
		int start();
	private:
		int dialog_pos(BigInt&);
		int dialog_neg(BigInt&);
		int dialog_m10(BigInt&);
		int dialog_d10(BigInt&);
		int dialog_set(BigInt&);
		int getCommand(void)const;
		//parameters

		BigIntModel* _model;
		consoleView* _view;
	};

}