// Bus_numbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>

struct inputFile
{
	int numberOfSrtings;
	std::vector<std::string> data;
};

struct answers 
{
	std::vector<bool> ans;
};

inputFile reading()
{
	inputFile numbers = { 0 };
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) 
	{
		std::cout << "error1\n";
	}
	else 
	{
		fin >> numbers.numberOfSrtings;
		fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < numbers.numberOfSrtings; ++i) 
		{
			std::string str;
			std::getline(fin, str);
			numbers.data.push_back(str);
		}
	}
	fin.close();
	return numbers;
}

bool first_check(const inputFile &input, const int &i)
{
	if (input.data.size() == 6) 
	{
		if ((input.data.at(i)[0] >= 'A') && (input.data.at(i)[0] <= 'z') && (input.data.at(i)[1] >= '0') && (input.data.at(i)[1] <= '9') && 
			(input.data.at(i)[2] >= '0') && (input.data.at(i)[2] <= '9') && (input.data.at(i)[3] >= '0') && (input.data.at(i)[3] <= '9') &&
			(input.data.at(i)[4] >= 'A') && (input.data.at(i)[4] <= 'z') && (input.data.at(i)[5] >= 'A') && (input.data.at(i)[5] <= 'z')) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool second_check(const inputFile &input, const int &i) 
{
	if (input.data.at(i)[0] == 'A' || input.data.at(i)[0] == 'B' || input.data.at(i)[0] == 'C' || input.data.at(i)[0] == 'E' ||
		input.data.at(i)[0] == 'H' || input.data.at(i)[0] == 'K' || input.data.at(i)[0] == 'M' || input.data.at(i)[0] == 'O' ||
		input.data.at(i)[0] == 'P' || input.data.at(i)[0] == 'T' || input.data.at(i)[0] == 'X' || input.data.at(i)[0] == 'Y' ||
		input.data.at(i)[0] == 'a' || input.data.at(i)[0] == 'c' || input.data.at(i)[0] == 'e' || input.data.at(i)[0] == 'k' ||
		input.data.at(i)[0] == 'o' || input.data.at(i)[0] == 'p' || input.data.at(i)[0] == 'x' || input.data.at(i)[0] == 'y') 
	{
		if (input.data.at(i)[4] == 'A' || input.data.at(i)[4] == 'B' || input.data.at(i)[4] == 'C' || input.data.at(i)[4] == 'E' ||
			input.data.at(i)[4] == 'H' || input.data.at(i)[4] == 'K' || input.data.at(i)[4] == 'M' || input.data.at(i)[4] == 'O' ||
			input.data.at(i)[4] == 'P' || input.data.at(i)[4] == 'T' || input.data.at(i)[4] == 'X' || input.data.at(i)[4] == 'Y' ||
			input.data.at(i)[4] == 'a' || input.data.at(i)[4] == 'c' || input.data.at(i)[4] == 'e' || input.data.at(i)[4] == 'k' ||
			input.data.at(i)[4] == 'o' || input.data.at(i)[4] == 'p' || input.data.at(i)[4] == 'x' || input.data.at(i)[4] == 'y') 
		{
			if (input.data.at(i)[5] == 'A' || input.data.at(i)[5] == 'B' || input.data.at(i)[5] == 'C' || input.data.at(i)[5] == 'E' ||
				input.data.at(i)[5] == 'H' || input.data.at(i)[5] == 'K' || input.data.at(i)[5] == 'M' || input.data.at(i)[5] == 'O' ||
				input.data.at(i)[5] == 'P' || input.data.at(i)[5] == 'T' || input.data.at(i)[5] == 'X' || input.data.at(i)[5] == 'Y' ||
				input.data.at(i)[5] == 'a' || input.data.at(i)[5] == 'c' || input.data.at(i)[5] == 'e' || input.data.at(i)[5] == 'k' ||
				input.data.at(i)[5] == 'o' || input.data.at(i)[5] == 'p' || input.data.at(i)[5] == 'x' || input.data.at(i)[5] == 'y') 
			{
				return true;
			}

			else 
			{ 
				return false; 
			}
		}
		else 
		{ 
			return false; 
		}
	}
	else 
	{ 
		return false; 
	}
}

answers conclude(const inputFile &input, const int &i, answers &answr) 
{
	if ((first_check(input, i) != false) && (second_check(input, i) != false)) 
	{
	answr.ans.push_back(true);
	}
	else 
	{ 
		answr.ans.push_back(false); 
	}
	return answr;
}

std::string answer(const inputFile &input, const int &i, answers answr) 
{
	answers numbers = conclude(input, i, answr);
	if (numbers.ans.at(i) == 0) 
	{
		return "NO";
	}
	else 
	{ 
		return "YES"; 
	}
}

void writing(const inputFile &input) // ввод значений конструкции file с указанием на input 
{
	answers answr = { };
	answr.ans.resize(input.numberOfSrtings);
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) 
	{
		std::cout << "error2!\n";
	}
	else 
	{
		for (int a = 0; a < input.numberOfSrtings; ++a) 
		{
			fout << answer(input, a , answr) << "\n";
		}
	}
	fout.close();
}

int main()
{
	inputFile input = reading();
	writing(input);
	return 0;
}
