#include "pch.h"
#include <iostream>
int factorial(int x) {
	if (x > 1) {
		return x * factorial(x - 1);
	}
	else {
		return 1;
	}
}