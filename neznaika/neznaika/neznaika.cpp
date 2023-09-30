// neznaika.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>
#include <cmath>

struct inputFile
{
	long double T1;
    long double T2;
	long double S1;
	long double S2;
	long double S;
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
		fin >> input.T1 >> input.T2 >> input.S1 >> input.S2 >> input.S;
		std::cout << input.T1 << input.T2 << input.S1 << input.S2 << input.S;
		fin.close();
	}
	return input;
}
std::string ans(const inputFile &design) {
	if (design.S > design.S1) {
		if (design.S1 <= design.S2) {
			std::cout << "NO";
			return "NO";
		}
		else {
			std::cout << "YES";
			return "YES";
		}
	}
	else {
		std::cout << "YES";
		return "YES";
	}
}
double answers(std::string str, inputFile & design) {
	if (str == "YES") {
		double time = 0;
		while (design.S > design.S1) {
			design.S -= design.S1;
			time += design.T1;
			design.S += design.S2;
			time += design.T2;
		}
		time += (round((design.S*design.T1) / design.S1)*100)/100;
		std::cout << time;
		return time;
	}
}
void writing(inputFile &input ) // ввод значений конструкции file с указанием на input 
{
	std::string wer = ans(input);
	double answr = answers(wer, input);
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		if (wer == "NO") {
			fout << "NO" << "\n";
		}
		else {
			fout << answr;
		}
		fout.close();
	}
}
int main()
{
	inputFile input = reading();
	writing(input);
	return 0;
}
