#pragma once
#include "LONG_OP.h"
namespace LInteger {
	int dialog(const char* [], int);
	int getN_Int(int* a);
	int getN_Int(long int* a);
	int dialog_ts(LongInteger&);
	int dialog_pos(LongInteger&);
	int dialog_neg(LongInteger&);
	int dialog_m10(LongInteger&);
	int dialog_d10(LongInteger&);
	int dialog_fun(LongInteger&);
	int dialog_set(LongInteger&);
}