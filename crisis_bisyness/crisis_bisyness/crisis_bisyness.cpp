// crisis_bisyness.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector> 
#include <algorithm>
#include <functional>

struct inputFile
{
	int numberOfInt;
	long long money;
	std::vector<long> data;
};

inputFile reading()
{
	inputFile products = { 0 };
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << "error1\n";
	}
	else {
		fin >> products.numberOfInt;
		fin >> products.money;
		fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < products.numberOfInt; ++i) {
			long num;
			fin >> num;
			products.data.push_back(num);
			std::cout << num;
		}
	}
	fin.close();
	return products;
}

int RightFind(inputFile &input)
{
	int a = 0;
	std::sort(input.data.begin(), input.data.end());
	for (int i = 0; i < input.numberOfInt; ++i) {
		if(input.money >= input.data[i]) {
		    input.money -= input.data[i];
			a += 1;
		}
		else {
			return a;
		}
	}
}

void writing(inputFile &input) // ввод значений конструкции file с указанием на input 
{
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		fout << RightFind(input) << "\n";
	}
	fout.close();
}
int main()
{
	inputFile input = reading();
	writing(input);
	//Почему 1????? Любое отличное от 0 значение это ошибка
	 //return 1;
	return 0;
}
