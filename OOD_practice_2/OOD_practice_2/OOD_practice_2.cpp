// OOD_practice_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cmath>
#include <string>
class Object {
private:
	int m_parametr1;
	int m_parametr2;
	int m_bnumb;
	int m_endednumb;
public:
	Object(int a = 0, int b = 0) : m_parametr1(a), m_parametr2(b)
	{
		if (m_parametr1 > m_parametr2) {
			m_bnumb = m_parametr1;
		}
		else if (m_parametr1 <= m_parametr2) {
			m_bnumb = m_parametr2;
	   }
	}
	void working(int n) {
		m_endednumb = m_bnumb / n;
	}
	void print() {
		std::cout << m_endednumb;
	}
};
int main()
{
	Object object(134, 264);
	object.working(2);
	object.print();
	return 0;
}

