// containers_practice.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <utility>

int main()
{
	int i; int size = 10;
	int array[10];
	for (i = 0; i < size; ++i) {
		std::cin >> array[i];
	}
	for (int startIndex = 0; startIndex < size - 1; ++startIndex)
	{
		// В переменной smallestIndex хранится индекс наименьшего значения, которое мы нашли в этой итерации
		// Начинаем с того, что наименьший элемент в этой итерации - это первый элемент (индекс 0)
		int smallestIndex = startIndex;

		// Затем ищем элемент поменьше в остальной части массива
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			// Если мы нашли элемент, который меньше нашего наименьшего элемента
			if (array[currentIndex] < array[smallestIndex])
				// запоминаем его
				smallestIndex = currentIndex;
		}
		// smallestIndex теперь наименьший элемент 
		// меняем местами наше начальное наименьшее число с тем, которое мы обнаружили
		std::swap(array[startIndex], array[smallestIndex]);

	}
	for (i = 0; i < 10; ++i) {
		std::cout << array[i] << '\n';
	}
}

