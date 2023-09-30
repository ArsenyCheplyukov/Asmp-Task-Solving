// procedures.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <fstream> 
#include <iostream> 
#include <math.h> 
#include <cmath>
int faktorial(int numb)  // заголовок функции
{
	int rezult = 1; // инициализируем переменную rezult значением 1
	for (int i = 1; i <= numb; i++) // цикл вычисления значения n!
		rezult *= i; // накапливаем произведение в переменной rezult
	return rezult;  // печать значения n!
}
int main()
{
    int numb; int digit; // переменная для хранения значения n!
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << "error1!";
	}
	else {
		fin >> digit;
	}
	fin.close();
	// объявление функции нахождения n!
	std::ofstream fout;
	fout.open("OUTPUT.txt"); // запуск функции нахождения факториала
		if (!fout) {
			std::cout << "error2!";
		}
		else {
			fout << faktorial(digit) << "\n";
		}
		fout.close();
		return 1;
}