// pizza.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector> 
#include <algorithm>
#include <functional>
class Base {
private:
		short input;
	    std::vector<short> array;
public:
	void reading()
	{
		std::ifstream fin;
		fin.open("INPUT.txt");
		if (!fin) {
			std::cout << "error1\n";
		}
		else {
			fin >> input;
			std::cout << input;
			fin.close();
		}
	}
	int dinamical()
	{
	
		array.push_back(2);
		for (short i = 1; i < input; ++i) {
			array.push_back(array.at(i - 1) + i +1);
			std::cout << array.at(i);
		}
		return array.at(input - 1);
	}
	void writing() // ввод значений конструкции file с указанием на input 
	{
		std::ofstream fout;
		fout.open("OUTPUT.txt"); //вывод значения в output.txt 
		if (!fout) {
			std::cout << "error2!\n";
		}
		else {
			fout << dinamical() << "\n";
		}
		fout.close();
	}
};
int main()
{
	Base input;
	input.reading();
	input.writing();
	return 0;
}


