// prince_and_dragon.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>
class base
{
public:
	int damage;
	int number;
	int regeneration;
	std::string answer;
	int output;

	void reading()
	{
		std::ifstream fin;
		fin.open("INPUT.txt");
		if (!fin) {
			std::cout << "error1\n";
		}
		else {
			fin >> damage;
			fin >> number;
			fin >> regeneration;
			fin.close();
		}
	}
	void answr()
    {
		if (damage >= number) {
			output = 1;
			answer = "YES";
		}
		else {
			if (damage > regeneration) {
				answer = "YES";
				output = (number - damage - 1) / (damage - regeneration) + 2;
			}
			else {
				answer = "NO";
			}
		}
	}
	void writing() // ввод значений конструкции file с указанием на input 
	{
		std::ofstream fout;
		fout.open("OUTPUT.txt"); //вывод значения в output.txt 
		if (!fout) {
			std::cout << "error2!\n";
		}
		else {
			if (answer == "YES") {
				fout << output;
			}
			else {
				fout << "NO";
			}
			fout.close();
		}
	}
};
int main()
{
	base npt;
	npt.reading();
	npt.answr();
	npt.writing();
	return 0;
}
