// funny_game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <bitset>

int reading()
{
	int number;
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

std::vector<int> to_bin(const int &number)
{
	std::vector <int> numb;
	int dou = number;                                // перевод числа в "двоичный массив"
	while (dou > 1) {
		if (dou >= 2) {
			numb.push_back(dou % 2);
			dou /= 2;
		}
		else {
			numb.push_back(dou % 2);
		}
	}
	numb.push_back(dou);
	std::reverse(numb.begin(), numb.end());
	return numb;
}

int to_number(const std::vector <int> &bin) 
{
	std::vector<int> _bin(bin);
	std::reverse(_bin.begin(), _bin.end());
	int rtaint = 0;
	for (int y = 0; y < _bin.size(); ++y) {
		if (_bin.at(y) == 1) {
			rtaint += pow(2, y);
		}
	}
	return rtaint;
}


template <int BITS>
unsigned long rightRotation(unsigned int val, size_t shift)
{
	unsigned int result = -1;
	std::bitset<BITS> bs(val);
	result = ((bs >> shift) | (bs << (BITS - shift))).to_ulong();

	return result;
}

auto answer(const int &integer)
{
	std::vector <int> answers;
	answers.push_back(integer);
	std::vector <int> numbers = to_bin(integer);
	std::vector <int> rotation = numbers;
	int max = 0;
	for (;;) {
		std::rotate(rotation.rbegin(), rotation.rbegin() + 1, rotation.rend());
		int result = to_number(rotation);
		if (max < result) {
			max = result;
		}
		if (rotation == numbers) {
			break;
		}
	}
	return max;
}



void writing(const int & number)
{
	std::ofstream fout;
	fout.open("OUTPUT.txt");
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		fout << answer(number);
		fout.close();
	}
}



int main()
{
	int numb = reading();
	writing(numb);
	/*
	int bVal = 1212;
	const int BITS = 11;
	size_t shift = 0;
	unsigned long uMax = bVal;
	for (;;) {
		++shift;
		unsigned long rightRot = rightRotation<BITS>(bVal, shift);
		if (uMax < rightRot) {
			uMax = rightRot;
		}
		if (rightRot == bVal) {
			break;
		}
	}
	std::bitset<BITS> result(uMax);
	std::cout << "Max: " << uMax << " (" << result << ")" << std::endl;
	system("pause");*/
	return 0;
}
