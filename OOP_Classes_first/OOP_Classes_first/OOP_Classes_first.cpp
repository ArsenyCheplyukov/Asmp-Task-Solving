// OOP_Classes_first.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
struct Input {
	int number;
	int sign;
};
class factorials {
private:
	int m_output;
public:
	Input reading() {
		Input input = { 0 };
		char explanation[20]; int i;
		std::ifstream fin;
		fin.open("INPUT.txt");
		if (!fin) {
			std::cout << "error1";
		}
		else {
			fin >> input.number;
			for (i = 1; i < 21; ++i) {
				int sign(0);
				fin >> explanation[i];
				if (explanation[i] == '!') {
					sign += 1;
				}
			}
		}
		fin.close();
		return input;
	}
	long factorial(int number, const int move) {
		if (number < 0)
			return 0; 
		if (number == 0) 
			return 1; 
		else 
			return number * factorial(number - move, move);
	}
	void writing(const long &input) 
	{


		std::ofstream fout;
		fout.open("OUTPUT.txt"); //вывод значения в output.txt 
		if (!fout) {
			std::cout << "error2!";
		}
		else {
			fout << m_output << '\n';
		}
		fout.close();
	}
};
int main()
{
	factorials inputFile;
	Input input = inputFile.reading();
	int numb = input.number;
	int m = input.sign;
	long output = inputFile.factorial(numb, m);
	inputFile.writing(output);
	return 0;
}


