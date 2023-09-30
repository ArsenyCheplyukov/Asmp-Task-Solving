// binary_practice.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
const std::string error1 = "error in input";
const std::string error2 = "error in output";
struct inputFile {
	 char simpleNumb1; // число которое нужно перевести
	 int bitFlag;     // шаг числа
	 char simpleNumb2;
};
struct variable {
	int a;
	int b;
};
struct staff {    // функции которые появляются при работе с simpleNumb
	int fourFunc;
	int oneFunc;
	int twoFunc;
	int threeFunc;
	int fiveFunc;
	int sixFunc;
};
inputFile reading() {
	inputFile numbers = { 0 };
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << error1 << '\n';
	}
	else {
		fin >> numbers.simpleNumb1 >> numbers.simpleNumb2 >> numbers.bitFlag; // считывание чисел из структуры inputFile
	}
	fin.close();
	return numbers; // возвращаем структуру
}
variable convert_numb() {
	inputFile numbers = reading();
	variable iint     = { 0 };
	char ch1          = numbers.simpleNumb1;  
	char ch2          = numbers.simpleNumb2;
    int numb2         = static_cast<int>(ch2);
    int numb1         = static_cast<int>(ch1); // перевод символа типа char в integer
	iint.a            = numb1;
	iint.b            = numb2;
	return iint;                        // возвращаем переведённое число
}

staff practice() {                   // функции при работе с numb2
	inputFile numbers = reading();
	staff output      = { 0 };
	variable iint     = convert_numb();
	int numb1         = iint.a;
	int numb2         = iint.b;
	int bitFlag       = numbers.bitFlag;
	output.oneFunc    = numb2 | numb1;
	output.twoFunc    = numb2 & numb1;
	output.threeFunc  = numb2 ^ numb1;
	output.fourFunc   = ~numb2;
	output.fiveFunc   = numb2 >> bitFlag;
	output.sixFunc    = numb2 << bitFlag; 
	return output;                    // возвращаем staff 
}
void writing() // ввод значений конструкции file с указанием на input 
{
	staff output = practice();
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << error2 << '\n';
	}
	else {
		fout << output.oneFunc << '\n' << output.twoFunc << '\n' << output.threeFunc << '\n' << output.fourFunc <<
	    '\n' << output.fiveFunc << output.sixFunc << '\n';    // выводим то что происходит с numb2 в выполнении функций
	}
	fout.close();
}
int main()
{
	writing();
	return 1;
}

