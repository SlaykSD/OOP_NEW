#define _CRT_SECURE_NO_WARNINGS

#include "dialog.h"
#include <math.h>
#include <iostream>

namespace Chain_Line {
	CH_Line::CH_Line(double ad) :x1(-1), x2(1)
	{
		if (ad <= 0)
			throw std::exception("Invalid height");
		a = ad;
	}
	CH_Line::CH_Line(const double x1, const double x2, double ad) :x1(x1), x2(x2)
	{
		if (ad <= 0)
			throw std::exception("Invalid height");
		a = ad;
	}


	CH_Line& CH_Line::setX1(const double x1)
	{
		this->x1 = x1;
		return *this;
	}

	CH_Line& CH_Line::setX2(const double x2)
	{
		this->x2 = x2;
		return *this;
	}
	//Ìåòîäû ïî ðàáîòå ñ öåïî÷êîé
	double CH_Line::f(double x) const
	{
		//Y(x) = a *cosh( x/a)
		return  a * (exp(x / a) + exp(-x / a)) / 2;
	}
	CH_Line& CH_Line::setHeight(double a)
	{
		if (a <= 0)
			throw std::exception("Invalid height");
		CH_Line::a = a;
	}
	double CH_Line::L(double l)const
	{
		if (l <= 0)
			throw std::exception("Invalid lenght");
		return  CH_Line::a * (exp(l / 2 * CH_Line::a) - exp(-l / 2 * CH_Line::a));
	}
	double CH_Line::ch(double x) const
	{
		return (exp(x) + exp(-x)) / 2;
	}
	double CH_Line::sh(double x) const
	{
		return (exp(x) - exp(-x)) / 2;
	}
	double CH_Line::L2()const
	{
		if ((x1 * x2) > 0)//Ïî ðàçíûå ñòîðîíû
			return a * sh(x1 / a) + a * sh(x2 / a);
		else// Ïî îäíó ñòîðîíó
			return abs(a * sh(x1 / a) - a * sh(x2 / a));
	}
	double CH_Line::R(double x)const
	{
		return this->a * (pow(this->a * (exp(x / CH_Line::a) - exp(-(x) / CH_Line::a)) / 2, 2));
	}
	Point& CH_Line::Center_Curvature(double x) const
	{
		Point* p;
		p = new Point;
		p->x = a * (ch(x / a) * sh(x / a) + log(ch(x / a) - sh(x / a)));
		p->y = 2 * a * ch(x / a);
		return *p;
	}
	double CH_Line::Integral(void)const
	{
		return a * a * (sh((x2) / a) - sh((x1) / a));// a^2(sh(x2/a)- sh(x1/a))
	}
}