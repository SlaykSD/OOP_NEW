#include <iostream>
#include "dialog.h"
#include <limits>

using namespace Chain_Line;
const char* msgs[] = { "0. EXIT","1.Get an information about catenary ",
						"2.Get F(X) relative to the variable {X}",
						"3.Get the catenary length",
						"4.Get radius curvature",
						"5.Get (x,y) - coordinates of center curvature ",
						"6.Get INTEGRAL your catenary",
						"7.Change points your catenary" };

const int Nmsg = sizeof(msgs) / sizeof(msgs[0]);
//Создадим массив функий
int (*Operation[])(CH_Line&) { nullptr, dialog_info, dialog_function, dialog_lenght, dialog_radius, dialog_center, dialog_integral, dialog_set };

namespace Chain_Line{

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
		bool good = true;
		do
		{
			std::cin >> *a;
			if (!(good = std::cin.good()))
				std::cout<< "Error! Please, repeat your input(INTEGER): ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (!good);
		return 1;
	}
	int getDouble(double* a)
	{
		bool good = true;
		do
		{
			std::cin >> *a;
			if (!(good = std::cin.good()))
				std::cout << "Error! Please, repeat your input(DOUBLE): ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (!good);
		return 1;
	}
	int dialog_info(CH_Line& catenary)
	{
		double x1, x2;
		x1 = catenary.getX1();
		x2 = catenary.getX2();
		double height;
		height = catenary.getHeight();
		std::cout << "Points: (" << x1 << "," << catenary.f(x1) << ") and (" << x2 << "," << catenary.f(x2) << ") " << std::endl;
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

int main() {
	CH_Line catenary;
	int rc = 0;
	dialog_set(catenary);
	while (rc = dialog(msgs, Nmsg))
		if (!Operation[rc](catenary))
			break;
	return 0;
}