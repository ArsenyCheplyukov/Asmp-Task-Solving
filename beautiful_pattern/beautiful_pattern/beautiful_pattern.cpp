// beautiful_pattern.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>

struct inputFile
{
	std::vector<std::string> pattern;
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
		for (int i = 0; i < 4; ++i) {
			std::string str;
			std::getline(fin, str);
			input.pattern.push_back(str);
			std::cout << str << "\n";
		}
		fin.close();
	}
	return input;
}
int answer(const inputFile &design) {
	if ((design.pattern.at(0)[0] == design.pattern.at(0)[1] & design.pattern.at(0)[1] == design.pattern.at(1)[0] & design.pattern.at(1)[0] == design.pattern.at(1)[1] ) ||
		(design.pattern.at(1)[0] == design.pattern.at(1)[1] & design.pattern.at(1)[1] == design.pattern.at(2)[0] & design.pattern.at(2)[0] == design.pattern.at(1)[1] ) ||
		(design.pattern.at(2)[0] == design.pattern.at(2)[1] & design.pattern.at(2)[1] == design.pattern.at(3)[0] & design.pattern.at(3)[0] == design.pattern.at(3)[1])) {
		return 123;
	}
	else  if ((design.pattern.at(0)[2] == design.pattern.at(0)[1] & design.pattern.at(0)[1] == design.pattern.at(1)[2] & design.pattern.at(1)[2] == design.pattern.at(1)[1]) ||
			(design.pattern.at(1)[2] == design.pattern.at(1)[1] & design.pattern.at(1)[1] == design.pattern.at(2)[2] & design.pattern.at(2)[2] == design.pattern.at(1)[1]) ||
			(design.pattern.at(2)[2] == design.pattern.at(2)[1] & design.pattern.at(2)[1] == design.pattern.at(3)[2] & design.pattern.at(3)[2] == design.pattern.at(3)[1])) {
			return 123;
		  }
	else if (design.pattern.at(0)[2] == design.pattern.at(0)[3] & design.pattern.at(0)[3] == design.pattern.at(1)[2] & design.pattern.at(1)[2] == design.pattern.at(1)[3] ||
		     design.pattern.at(1)[2] == design.pattern.at(1)[3] & design.pattern.at(1)[3] == design.pattern.at(2)[2] & design.pattern.at(2)[2] == design.pattern.at(1)[3] ||
		     design.pattern.at(2)[2] == design.pattern.at(2)[3] & design.pattern.at(2)[3] == design.pattern.at(3)[2] & design.pattern.at(3)[2] == design.pattern.at(3)[3]) {
		     return 123;
	     }  else {
			return 321; 
		 }
}
void writing(const inputFile &input) // ввод значений конструкции file с указанием на input 
{
	int ans = answer(input);
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		if (ans == 123) {
			fout << "NO" << "\n";
		}
		else {
			fout << "YES" << "\n";
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

