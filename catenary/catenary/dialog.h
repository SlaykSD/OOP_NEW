#pragma once
#include "Catenary.h"
namespace Chain_Line {
	int dialog_set(CH_Line&);
	int dialog_info(CH_Line&);
	int dialog_function(CH_Line&);
	int dialog_lenght(CH_Line&);
	int dialog_radius(CH_Line&);
	int dialog_center(CH_Line&);
	int dialog_integral(CH_Line&);
	int dialog(const char* [], int);
	int getN_Int(int* a);
	int getDouble(double* a);

}