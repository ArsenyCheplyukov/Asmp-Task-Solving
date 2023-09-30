// ones_in_binary_code.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <fstream> 
#include <iostream> 
#include <cmath> 

int binaryones(int p) // заголовок функции 
{
	int sum = { 0 }; // "sum" прямой постоянной инициализации
	while (0 < p) {
		int c(0);    // "c" в прямой инициализации  
		c = p % 2; // остаток от деления
		sum += c; // нахождение колличества единиц в двоичном коде числа
		p = p / 2; 
	}
	return sum;
}

struct file
{ // переменные считываемые с input.txt 
	int a;
};

file reading()
{
	file numbers = { 0 }; //структура file с именем numbers 
	std::ifstream fin;
	fin.open("INPUT.txt"); // получение переменных из input.txt 
	if (!fin) {
		std::cout << "error1!";
	}
	else {
		fin >> numbers.a;  // ввод значения a конструкции file numbers с input.txt
	}
	fin.close();
	return numbers;
}

void writing(const file &input)  // ввод значений конструкции file с указанием на input
{
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!";
	}
	else {
		fout << binaryones(input.a) << "\n"; // вывод единиц в двоичном коде
	}
	fout.close();
}

int main()
{
	file input = reading();
	writing(input);
	return 1;
}
