// functions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <pch.h>
#include <fstream> 
#include <iostream> 
#include <cmath> 

int everlastsumm(float p, float q) // заголовок функции 
{
	float d = 1 - q; // инициализируем переменную d через q (float - тип с плавающей запятой) 
	float sum = p / d; // нахождение значения бесконечной геометрической прогрессии 
	return sum;
}

struct file
{ // переменные считываемые с input.txt 
	float a;
	float b;
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
		fin >> numbers.a >> numbers.b;
	}
	fin.close();
	return numbers;
}

void writing(const file &input)
{
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout<< "error2!";
	}
	else {
		fout<< everlastsumm(input.a, input.b) << "\n";
	}
	fout.close();
}

int main()
{
	file input = reading();
	writing(input);
	return 1;
}