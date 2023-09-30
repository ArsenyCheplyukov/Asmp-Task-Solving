// ladder.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>
class base 
{
public:
	long long number;
	long output;
	void reading()
	{
		std::ifstream fin;
		fin.open("INPUT.txt");
		if (!fin) {
			std::cout << "error1\n";
		}
		else {
			fin >> number;
			std::cout << number;
			fin.close();
		}
	}
	void answer() 
	{
		long k = 1;
		while (number >= k) {
			number -= k;
			k += 1;	
			std::cout << k;
		}
			output = k-1;	
	}
	void writing() // ввод значений конструкции file с указанием на input 
	{
		std::ofstream fout;
		fout.open("OUTPUT.txt"); //вывод значения в output.txt 
		if (!fout) {
			std::cout << "error2!\n";
		}
		else {
			fout << output;
			fout.close();
		}
	}
};
int main()
{ 
	base npt;
	npt.reading();
	npt.answer();
	npt.writing();
	return 0;
}