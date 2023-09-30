// OOP_fourth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
class FileWork {
private:
	long long int m_input1;
	long long int m_input2;
	long long int m_lenght;
	long long int m_output;
public:

	void get_reading() {                 // геттер reading
		std::ifstream fin;
		fin.open("INPUT.txt");
		if (!fin) {
			std::cout << "error1";
		}
		else {
			fin >> m_input1 >> m_input2;
		}
		fin.close();
	}
	void min_lenght() {
		m_lenght = sqrt(m_input1*m_input2);
	}
	void squareMatch() { 
			if ((m_lenght*m_lenght) == (m_input1 * m_input2)) {
				m_output = m_lenght;
			} else {
				m_output = 0;
		}
	}
	void set_output() {               // сеттер output 
		std::ofstream fout;
		fout.open("OUTPUT.txt"); //вывод значения в output.txt 
		if (!fout) {
			std::cout << "error2!";
		}
		else {
			fout << m_output << '\n';
		}
		fout.close();
	}
};
int main()
{

	FileWork file_work;
	file_work.get_reading();
	file_work.min_lenght();
	file_work.squareMatch();
	file_work.set_output();
	return 0;
}
