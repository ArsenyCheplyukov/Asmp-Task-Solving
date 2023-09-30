// postulate_of_Bertran.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

long reading()
{
	long number;
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << "error1\n";
	}
	else {
		fin >> number;
		fin.close();
		std::cout << number;
		return number;
	}
}

bool IsPrime(const long &n) {
	for (long i = 2; i < sqrt(n) +1; ++i) {
		if ((n % i) == 0)
		{
			return true;
		}
	}
	return false;
}

long development(long integer)
{    
	long number = 0;
	for (long long i = integer + 1; i < (2 * integer); ++i) {
		if (!IsPrime(i)) {
			number += 1;
		}
	}
	std::cout << number;
	return number;
}

void writing(const long & number)
{
	std::ofstream fout;
	fout.open("OUTPUT.txt");
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		fout << development(number);
		fout.close();
	}
}


int main()
{
	long numb = reading();
	writing(numb);
	return 0;
}
