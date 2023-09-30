// hero_creation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


//Прототип функции рисования. Это значит, что сама функция будет объявлена после тела main()
void draw(int x, int y);

int main(void)
{

	int gdriver = DETECT, gmode;
	void *ptr; //резервируем пустой указатель - стартовая ячейка памяти, 
	// начиная с которой мы будем хранить наше изображение
	int x, y, maxx;
	unsigned int size;

	initgraph(&gdriver, &gmode, "");

	maxx = getmaxx();
	//Начальные координаты
	x = 30;
	y = 30;

	//Цвет фона
	setbkcolor(2);

	//Рисуем героя
	draw(x, y);

	//Вычисляем, сколько изображение будет занимать в памяти
	size = imagesize(x - 10, y - 10, x + 10, y + 10);
	//Выделяем память начиная с того места, куда указывает указатель
	ptr = malloc(size);
	//Копируем в память изображение
	getimage(x - 10, y - 10, x + 10, y + 10, ptr);

	int key;
	int nx = x;
	int ny = y;


	do
	{
		key = getch(); //Обработка нажатия клавиш

		switch (key) {
		case 80: ny += 10; break;
		case 72: ny -= 10; break;
		case 77: nx += 10; break;
		case 75: nx -= 10; break;
		}

		//Стираем старое изображение наложением на него нового
		putimage(x - 10, y - 10, ptr, XOR_PUT);

		//Меняем координаты соответственно нажатой клавише
		x = nx;
		y = ny;

		//Выводим изображение
		putimage(x - 10, y - 10, ptr, XOR_PUT);

	} while (key != 27);

	//Освобождаем память
	free(ptr);
	//Закрываем графику
	closegraph();
	return 0;
}

//Функция рисования. Сюда можно запрограммировать любой рисунок
void draw(int x, int y)
{

	setcolor(14);
	setfillstyle(1, 14);
	moveto(x, y);
	pieslice(x, y, 20, 350, 10);
	setfillstyle(1, 4);
	fillellipse(x + 1, y - 4, 2, 2);
}
