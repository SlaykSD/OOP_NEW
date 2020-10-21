#pragma once

#include <iostream>
#include "Calculator_c.h"
#include <limits>

int main()
{
	BigInteger::BigInt karloson;
	BigInteger::BigIntModel modelio(karloson);
	BigInteger::consoleView View(&modelio);
	BigInteger::Controller Father(&modelio, &View);
	Father.start();
}