// recursive_practice_project.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "factorial.h" 
int main()
{
	int x;
	std::cout << "write number" "\n";
	std::cin >> x;
	std::cout << factorial(x);
	return 1;
}

