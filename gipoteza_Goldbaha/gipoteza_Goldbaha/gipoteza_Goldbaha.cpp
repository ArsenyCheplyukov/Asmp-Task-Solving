// gipoteza_Goldbaha.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

long reading()
{
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << "error1\n";
	}
	else {
		long number;
		fin >> number;
		return number;
	}
}
bool isPrime(const long &numb) 
{
	for (int h = 2; h < sqrt(numb); ++h) {
		if (numb % h == 0) return false;
		return true;
	}
}
long development(const long &number)
{
	for (int i = 2; i < (number / 2); ++i) {
		if ((isPrime(i) == true ) & ( isPrime(number - i) == true)) {
			long output = i;
			return output;
		}
	}
}
/*
  bool IsPrime(int n){
	int i;
	for i=2..sqrt(n)
	 if(n mod i = 0) return false;
	return true;
  }

  read(n);

  for i=2 .. n div 2
	if(IsPrime(i) and IsPrime(n-i)){
	  write(i,' ',n-i);
	  break;
	}
*/

void writing()
{
	long input = reading();
	long output = development(input);
	std::ofstream fout;
	fout.open("OUTPUT.txt");
	if (!fout) {
		std::cout << "error2!\n";
	}
	else {
		fout << output;
		fout << " ";
		fout << (input - output);
		fout.close();
	}
}


int main()
{
	writing();
	return 0;
}
