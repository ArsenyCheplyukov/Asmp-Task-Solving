// chess_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
struct inputFile {
	short x1;
	short y1;
	short x2;
	short y2;
};
struct field {
	short arr[8][8] = {
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1 },
	{ 1, 0, 1, 0, 1, 0, 1, 0 },
	{ 0, 1, 0, 1, 0, 1, 0, 1 }
	};
};
inputFile reading() {
	inputFile input = { 0 };
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << "error1";
	}
	else {
		fin >> input.x1 >> input.y1 >> input.x2 >> input.y2;
	}
	fin.close();
	return input;
}

bool findmatch(const inputFile &input) {
	inputFile xandy = input;
	field desk;
	int x1 = xandy.x1;
	int y1 = xandy.y1;
	int x2 = xandy.x2;
	int y2 = xandy.y2;
	int color1 = desk.arr[y1][x1];
	int color2 = desk.arr[y2][x2];
	if (color1 == color2) {
		return true;
	}
	else {
		return false;
	}
}
void writing(const inputFile &input) 
{
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!";
	}
	else {
		bool match = findmatch(input);
		if (!match) {
			fout << "NO" << '\n';
		}
		else {
			fout << "YES" << '\n';
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


