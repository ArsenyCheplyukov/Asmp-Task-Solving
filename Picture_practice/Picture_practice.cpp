﻿include <iostream>

File* file;
char* file_name = "file.txt";
file = fopen(file_name, "r");
char load_string[256]
//тут надо как-то сравнить матрицу изображения с содержимым файла ???
//Т.е. первый пиксель изображения сравнивается с первым символом строки файла, потом 2-ой
//пиксель изображения сравнивается со вторым символом строки файлв и т.д.
//Если находим первое не совпадение, пере ходим к закрытию файла, а дальше к по пиксельной 
//записи матрицы изображения в файл, см выше.

while (!file.eof())
{
    fgets(load_string, 256, '\n');
    file << load_string << endl;

}
fclose(file);