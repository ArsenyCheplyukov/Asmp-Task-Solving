// left_recursion.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h" 
#include <iostream> 
#include <fstream> 
#include <string>
#include <vector>

struct inputFile 
{
	int numberOfSrtings;
	//std::string array[1000];
	std::vector<std::string> data;
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
		fin >> products.numberOfSrtings;
		// move next line
		fin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < products.numberOfSrtings; ++i) {
			std::string str;
			std::getline(fin, str); 
			products.data.push_back(str);
			std::cout << str << "\n";
		}
	}
	fin.close();
	return products;
}

int recursion(const inputFile &input) 
{
	int count = 0;
	for (int i = 0; i < input.numberOfSrtings; ++i) {
		if (input.data.at(i)[3] == 'A') {
			count += 1;
		}
	}
	return count;
}
void writing(const inputFile &input) // ввод значений конструкции file с указанием на input 
{
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		fout << recursion(input) << "\n";
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
