// simple_numbers_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

struct inputFile
{
	int N;
	std::vector<int> numbers;
};

inputFile reading()
{
	inputFile input = {};
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << "error1\n";
	}
	else {
		fin >> input.N;
		int H = 0;
		for (int i = 0; i < input.N; ++i) {
			fin >> H;
			input.numbers.push_back(H);
		}
		fin.close();
	}
	return input;
}


std::vector <int> development(std::vector <int> nmbr)
{
	std::vector <int> bint;
	for (auto number : nmbr) {
		int dev = 0;
		for (int counter = 1; counter <= number; ++counter) {
			if (number % counter == 0) {
				number /= counter;
				dev++;
			}
		}
		bint.push_back(dev);
	}
	return bint;
}


auto answers(inputFile & design)
{
	std::vector <int> fa = design.numbers;
	std::vector <int> dev1_string = development(fa);
	auto maximumNumber = std::max_element(dev1_string.begin(), dev1_string.end());
	std::vector <int> dev2_string;
	for (int g = 0; g < design.N; ++g) {
		if (*maximumNumber == dev1_string.at(g)) {
			dev2_string.push_back(fa.at(g));
		}
	}
	auto answer = std::min_element(dev2_string.begin(), dev2_string.end());
	return *answer;
}

void writing(inputFile &input)
{
	int answer = answers(input);
	std::ofstream fout;
	fout.open("OUTPUT.txt");
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		fout << answer;
		fout.close();
	}
}


int main()
{
	inputFile input = reading();
	writing(input);
	return 0;
}
