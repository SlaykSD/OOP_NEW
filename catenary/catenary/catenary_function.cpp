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
	//Äèàëîãîâûå Ôóíêöèè!

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
	int getN_Int(int* a) {
		int n;
		do {
			n = scanf("%d", a);
			if (n < 0)
				return 0;
			if (n == 0 || *a < 0) {
				printf("%s\n", "Error! Please, repeat your input: ");
				scanf("%*[^\n]");
			}
		} while (n == 0 || *a < 0);
		return 1;
	}
	int getDouble(double* a)
	{
		int n;
		do {
			n = scanf("%lf", a);
			if (n < 0)
				return 0;
			if (n == 0) {
				printf("%s\n", "Error! Please, repeat your input: ");
				scanf("%*[^\n]");
			}
		} while (n == 0);
		return 1;
	}
	int dialog_info(CH_Line& catenary)
	{
		double x1, x2;
		x1 = catenary.getX1();
		x2 = catenary.getX2();
		double height;
		height = catenary.getHeight();
		printf("Points: (%.2f,%.2f) and (%.2f,%.2f) ; Height this catenary: [%.2f]\n", x1, catenary.f(x1), x2, catenary.f(x2), height);
		return 1;
	}
	int dialog_function(CH_Line& catenary)
	{
		double x;
		std::cout << "Input \"x\" coordinate" << std::endl;
		if (!getDouble(&x))
		{
			std::cerr << "EOF deceted" << "\n";
			return 0;
		}
		std::cout << "F(" << x << ") = " << catenary.f(x) << std::endl;
		return 1;
	}
	int dialog_lenght(CH_Line& catenary)
	{
		double L;//äëèííà íàøåé öåïè
		double p, p1, p2;
		p1 = catenary.getX1();
		p2 = catenary.getX2();
		double l;
		if ((-1 == p1) && (1 == p2))
		{
			//Ïðåäëàãàåì ââåñòè äëèííó ïî x
			std::cout << "Input proection lenght on the  x-axes" << std::endl;
			if (!getDouble(&l))
			{
				std::cerr << "EOF deceted" << "\n";
				return 0;
			}
			L = catenary.L(l);
			std::cout << "Length relative to the projection equal: " << L << std::endl;
			return 1;
		}
		//Åñëè ó íàøåé ëèíèè åñòü 2 òî÷êè
		L = catenary.L2();
		std::cout << "Length relative to the coordinate equal: " << L << std::endl;
		return 1;
	}
	int dialog_radius(CH_Line& catenary)
	{
		double R, x;
		std::cout << "Input x- coordinate" << std::endl;
		if (!getDouble(&x))
		{
			std::cerr << "EOF deceted" << "\n";
			return 0;
		}
		R = catenary.R(x);
		std::cout << "Radius relative to the coordinate equal: " << R << std::endl;
		return 1;
	}
	int dialog_center(CH_Line& catenary)
	{
		double  x;
		Point p;
		std::cout << "Input x- coordinate" << std::endl;
		if (!getDouble(&x))
		{
			std::cerr << "EOF deceted" << "\n";
			return 0;
		}
		p = catenary.Center_Curvature(x);
		std::cout << "Your coordinate center of curvature x = " << p.x << " and y = " << p.y << std::endl;
		return 1;
	}
	int dialog_integral(CH_Line& catenary)
	{
		std::cout << "Your area under the graph: " << catenary.Integral() << std::endl;
		return 1;
	}
	int dialog_set(CH_Line& catenary)
	{
		const char* errmsg = "";
		double a;
		std::cout << "Input height (parameter a): ";
		do {
			std::cout << errmsg;
			errmsg = "You are wrong. Repeat, please\n";
			if (!getDouble(&a))
			{
				std::cerr << "EOF deceted" << "\n";
				return 0;
			}
		} while (a <= 0);
		catenary.setHeight(a);
		double x1, x2;
		std::cout << "" << std::endl;
		errmsg = "";
		do {
			std::cout << errmsg;
			errmsg = "You are wrong. Repeat, please\n";
			std::cout << "Input x1  (point of your catanery): " << std::endl;
			if (!getDouble(&x1))
			{
				std::cerr << "EOF deceted" << "\n";
				return 0;
			}
			std::cout << "Input x2  (point of your catanery): " << std::endl;
			if (!getDouble(&x2))
			{
				std::cerr << "EOF deceted" << "\n";
				return 0;
			}
		} while (x1 == x2);
		catenary.setX1(x1), catenary.setX2(x2);
		return 1;
	}
}