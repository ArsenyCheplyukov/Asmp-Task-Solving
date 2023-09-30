// OOP_third.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
class FileWork {
private:
	int m_input;
	int m_output;
public:

	void get_reading() {                 // геттер reading
			std::ifstream fin;
			fin.open("INPUT.txt");
			if (!fin) {
				std::cout << "error1";
			}
			else {
				fin >> m_input;
			}
			fin.close();
	}
	void DoSomething() {
		m_output = m_input;
	}
	void set_output() {               // сеттер output 
			std::ofstream fout;
			fout.open("OUTPUT.txt"); //вывод значения в output.txt 
			if (!fout) {
				std::cout << "error2!";
			}
			else {
				fout << m_output << "\n";
			}
			fout.close();
	}
};
int main()
{

	FileWork file_work;
	file_work.get_reading();
	file_work.DoSomething();
	file_work.set_output();
	return 0;
}
