// OOP_second.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

class Time {
private:
	int m_year;
	int m_mounth;
	int m_day;
public:
	Time(int day, int mounth, int year) {
		set_date(day, mounth, year);
	}
	void set_date(int day, int mounth, int year) {        // использование сеттеров
		m_day = day; m_mounth = mounth; m_year = year;
	}
	void get_date() {
		std::cout << " Date: " << m_day << ":" << m_mounth << ":" << m_year << '\n';
	}
};
int main()
{
	Time time(11,12,2013); 
	time.get_date();
	return 0;
}


