#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <string>

struct SInputData 
{  // обьявление всего того что используется в input.txt
	size_t ticketsCount; // а именно колличество строк 1ый символ
	std::map<int, std::string> ticketData;
};

size_t getSumOfThreeDigits(size_t num)
{
	size_t sum = 0;
	size_t value = num;
	while (value) {
		size_t digit = value % 10;
		sum += digit;
		value /= 10;
	}
	return sum;
} 
/*  можно удалить - но можешь потестить и взять на вооружение
size_t getSumOfThreeDigits(const std::string &str)
{
	if (str.length() != 3) { // error
		return -1;
	}
	size_t sum = 0;
	for (int i = 0; i < 3; ++i) {
		size_t digit = (str[i] - '0'); // convert string to int (one character)
		sum += digit;
	}
	return sum;
}*/

std::string luckynumb(const SInputData &numbers, size_t ticket)
{
	const size_t diff_delta = 1;

	std::string ticketData = numbers.ticketData.at(ticket);

	std::string leftPart = ticketData.substr(0, 3);
	std::string rightPart = ticketData.substr(3, 3);
	size_t leftNum = atoi(leftPart.c_str());
	size_t rightNum = atoi(rightPart.c_str());

	size_t leftSum = getSumOfThreeDigits(leftNum);
	size_t rightSum_plus_delta = getSumOfThreeDigits(rightNum + diff_delta);
	size_t rightSum_minus_delta = getSumOfThreeDigits(rightNum - diff_delta);
	
	std::string result = "No";

	if (leftSum == -1 || rightSum_plus_delta == -1 || rightSum_minus_delta == -1) { // error
		return result;
	}
	if (leftSum == rightSum_plus_delta ||
		leftSum == rightSum_minus_delta) {
		result = "Yes";
	}
	return result;
}


SInputData reading() 
{ // счёт значений
	SInputData numbers = { 0 };
	//структура file с именем numbers 
	std::ifstream fin;
	fin.open("INPUT.txt"); // получение переменных из input.txt 
	if (!fin) {
		std::cout << "error1!";
	}
	else {
		fin >> numbers.ticketsCount;    // ввод значения колличества строк конструкции file numbers с input.txt
		for (size_t i = 0; i < numbers.ticketsCount; ++i) {
			fin >> numbers.ticketData[i];
		}
	}
	fin.close();

	return numbers;
}

bool writing(const SInputData &input)  // ввод значений конструкции file с указанием на input
{
	if (!input.ticketsCount) { // error
		return false;
	}
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << "error2!";
		return false;
	}
	else {
		for (size_t j = 0; j < input.ticketsCount; j++) { // вывод значений YES и NO
			fout << luckynumb(input, j) << "\n";;
		}
		fout.close();
	}
	return true;
}

int main()
{
	SInputData input = reading(); 
	return writing(input) ? 0 : 1;

	// if (<условие>) {...}
	// else {...}
	// Конструкцию выше можно упростить используя <условие> ? : ...
	// где ? - это if, а : - это else
	// получается если вызов writing(input) - вернет true тогда мы выходим из программы корректно с кодом 0
	// иначе выходим с кодом 1
	// вот еще пример:
	// const int v = 10;
	// int value = (v==10) ? 1 : 0; 
	// значение value будет 1, но если мы изменим v на другое тогда 0
}

