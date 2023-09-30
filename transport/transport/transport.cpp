// transport.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>
#include <cmath>

struct inputFile
{
	short N;
	double V;
	double L;
	std::vector<short> lenght;
	std::vector<short> time;
};

inputFile reading()
{
	inputFile input = { 0 };
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << "error1\n";
	}
	else {
		fin >> input.N >> input.V >> input.L;
		fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < (input.N * 2) ; ++i) {
			short str;
			fin >> str;
			if (i % 2 == 0) {
				input.lenght.push_back(str);
			}
			else {
				input.time.push_back(str);
			}
		}
		fin.close();
	}
	return input;
}

double all_time(const inputFile &input)
{
	int time1 = 0; 
	for (int i = 0; i < input.N; ++i) {
		time1 += input.time.at(i);
	}
	double time2 = (round((input.L / input.V)*6000))/100; 
	double time = time1 + time2;
	return time;
}
void writing(const inputFile &input) // ввод значений конструкции file с указанием на input 
{
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		fout << all_time(input) << "\n";
	}
	fout.close();
}
int main()
{
	inputFile input = reading();
	writing(input);
	return 0;
}
