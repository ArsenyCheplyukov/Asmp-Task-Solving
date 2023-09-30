// OOD_overload.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
class Zero {
private:
	int m_numb1;
	int m_numb2;
public:
	Zero (int one = 0, int two = 0){
		m_numb1 = one; 
		m_numb2 = two;
	}
	bool operator! () const
	{
		return (m_numb1 == 0.0 && m_numb2 == 0.0);
	}
	Zero operator-() const;
	friend bool operator== (const Zero &c1, const Zero &c2);
	friend bool operator!= (const Zero &c1, const Zero &c2);
	int getZero1() { return m_numb1; }
	int getZero2() { return m_numb2; }
    };
    bool operator== (const Zero &c1, const Zero &c2)
    {
	return (c1.m_numb1 == c2.m_numb1 &&
		c1.m_numb2 == c2.m_numb2);
    }
    bool operator!= (const Zero &c1, const Zero &c2)
    {
	    return !(c1 == c2);
    }
Zero Zero::operator-() const {
	return Zero(-m_numb1);
}

int main()
{
	const Zero c1(8, 6);
	const Zero c2(9, 4);
	if (!c2 && !c1)
		std::cout << "numbers are null.\n";
	else
		std::cout << "numbers are not null.\n";
	std::cout << "you have" << (-c1).getZero1() << '\n';
	std::cout << "you have" << (-c2).getZero2() << '\n';
	if (c1 == c2) {
		std::cout << "numbers are equal" << '\n';
	}
	else if (c1 != c2) {
		std::cout << "numbers are not equal" << '\n';
	}
}


