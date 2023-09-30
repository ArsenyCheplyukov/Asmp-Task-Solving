#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

struct inputFile
{
	int N;
	int lenght;
	std::vector<std::vector <int> > numbers;
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
		fin >> input.lenght;
		for (int i = 0; i < input.N; ++i) {
			for (int b = 0; b < 3; ++b) {
				fin >> input.numbers[i].at(b);
			}
		}
		fin.close();
	}
	return input;
}

double answerLoop(const inputFile & design)
{
	std::vector <double> endingString; int x; int y;
	for (int b = 0; b < design.N; ++b)                                              //перебор всех возможных комбинации с расстояниями
	{                                                                               ///между точками.
		for (int j = 0; j < design.N; ++j)                            
		{
			if (design.numbers[b][0] > design.numbers[j][0]) 
			{
				x = design.numbers[b][0] - design.numbers[j][0];                    // X-овая составляющая точек
			}
			else 
			{
				x = design.numbers[j][0] - design.numbers[b][0];
			}
			if (design.numbers[b][1] > design.numbers[j][1]) 
			{
				y = design.numbers[b][1] - design.numbers[j][1];                     /// Y-овая состовляющая точек
			}
			else 
			{
				y = design.numbers[j][1] - design.numbers[b][1];
			}
			double c = sqrt((x*x) + (y*y));                                           //поиск гипотенузы
			double halfAnswer = (c - design.numbers[b][2] - design.numbers[j][2]);    ///расстояние между краями тел
			if (halfAnswer/2 > design.lenght)                                       
			{
				double distance = halfAnswer / 2;                                     //расчёт прибавления для каждого тела
				endingString.push_back(distance);
			}
			else 
			{
				double distance = (halfAnswer / design.lenght) / 2;
				endingString.push_back(distance);
			}
		}
	}
	std::sort(endingString.begin(), endingString.end());                               /// поиск минимального 
	return endingString.at(0);;
}

void writing(inputFile &input)
{
	double answer = answerLoop(input);
	std::ofstream fout;
	fout.open("OUTPUT.txt");
	if (!fout) 
	{
		std::cout << "error2!\n";
	}
	else 
	{
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