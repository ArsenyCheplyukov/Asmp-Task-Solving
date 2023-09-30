// OOD_homework.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
class base
{
public:
	int numberOfString;
	std::vector <int> input;
	int maximumIndex;
	int minimumIndex;
	int output1;
	int output2;

	void reading()
	{
		std::ifstream fin;
		fin.open("INPUT.txt");
		if (!fin) {
			std::cout << "error1\n";
		}
		else {
			fin >> numberOfString;
			for (int i = 0; i < numberOfString; ++i) {
				int b;
				fin >> b;
				std::cout << b << "\n";
				input.push_back(b);
			}
			fin.close();
		}
	}
	void index()
	{
		int min = input.at(1);
		int max = input.at(1);
		int minindx;
		int maxindx;
		for (int i = 0; i < numberOfString; ++i) {
			if (min > input.at(i)) {
				min = input.at(i);
				minindx = i;
			}
			if (max < input.at(i)) {
				max = input.at(i);
				maxindx = i;
			}
		}
		minimumIndex = minindx;
		std::cout << minimumIndex << "\n";
		maximumIndex = maxindx;
		std::cout << maximumIndex << "\n";
	}
	void answer2()
	{
		output2 = 1;
		if (minimumIndex > maximumIndex) {
			for (int i = (maximumIndex + 1); i < minimumIndex; ++i) {
				output2 = output2 * input.at(i);
			}
		}
		else {
			for (int b = (minimumIndex + 1); b < maximumIndex; ++b) {
				output2 = output2 * input.at(b);
			}
		}
		std::cout << output2 << "\n";
	}

	void answer1()
	{
		int output1 = 0;
		for (int i = 0; i < numberOfString; ++i) {
			if (input.at(i) > 0) {
				output1 = output1 + input.at(i);
			}
		}
		std::cout << output1 << "\n";
	}
	void writing() // ввод значений конструкции file с указанием на input 
	{
		std::ofstream fout;
		fout.open("OUTPUT.txt"); //вывод значения в output.txt 
		if (!fout) {
			std::cout << "error2!\n";
		}
		else {
			fout << output1;
			fout << output2;
			fout.close();
		}
	}
};
int main()
{
	base npt;
	npt.reading();
	npt.index();
	npt.answer1();
	npt.answer2();
	npt.writing();
	return 0;
}
