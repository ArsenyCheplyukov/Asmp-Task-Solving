// OOD_fifth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <fstream>
#include <cmath>
class FileWork {
private:
    int m_min;
	int m_max;
public:
      FileWork(int min, int max) {
		 m_min = min;
		 m_max = max;
	}
	friend FileWork operator+(const FileWork &n1, const FileWork &n2);
	friend FileWork operator+(const FileWork &n, int value);
	friend FileWork operator+(int value, const FileWork &n);
	int getmin() const { return m_min; }
	int getmax() const { return m_max; }
};
FileWork operator+(const FileWork &n1, const FileWork &n2) {
	int min = n1.m_min > n2.m_min ? n2.m_min : n1.m_min;
	int max = n1.m_max < n2.m_max ? n2.m_max : n1.m_max;
	return FileWork(min, max);
}
FileWork operator+(const FileWork &n, int value) {
	int min = n.m_min < value ? n.m_min : value;
	int max = n.m_max > value ? n.m_max : value;
	return FileWork(min, max);
}
FileWork operator+(int Value, const FileWork &n) {
	return n + Value;
}
int main()
{
	FileWork v1(12, 15);
	FileWork v2(23, 45);
	FileWork v3(2, 5);
	FileWork numbSum = v1 + v2 + 6 + 9 + v3 + 17;
	std::cout << "Min: " << numbSum.getmin() << "Max:" << numbSum.getmax() << '\n';
	return 0;
}
