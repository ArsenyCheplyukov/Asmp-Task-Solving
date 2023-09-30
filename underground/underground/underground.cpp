// underground.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#define error1 "error in input"
#define error2 "error in output"
struct inputFile {
     int allStations; 
	 int firstStation;
	 int endingStation;
};
inputFile reading() {
	inputFile stations = {0};
	std::ifstream fin;
	fin.open("INPUT.txt");
	if (!fin) {
		std::cout << error1 "\n";
	}
	else {
		fin >> stations.allStations >> stations.firstStation >> stations.endingStation;
	}
	fin.close();
	return stations;
}
bool biggestNumber() {
	inputFile stations = reading();
	if (stations.firstStation < stations.endingStation) {
		return true;
	}
	else return false;
}
int distanceClockwise() {
	bool bigNumber     = biggestNumber() ;
	inputFile stations = reading();
	int rightDistance{ 0 };
	 if (bigNumber == true) {
		  rightDistance = stations.endingStation - stations.firstStation -1;
	 }
	  else {
		  rightDistance = stations.firstStation - stations.endingStation - 1;
	  }
	return rightDistance;
}
int dictanceAnticlockwise() {
	bool bigNumber     = biggestNumber();
	inputFile stations = reading();
	int leftDistance{ 0 };
	if (biggestNumber() == true) {
		leftDistance = stations.allStations - stations.endingStation + stations.firstStation - 1;
	}
	else {
		leftDistance = stations.allStations - stations.firstStation + stations.endingStation - 1;
	}
	return leftDistance;
}
int minimumDistance() {
	int clockwise     = distanceClockwise();
	int anticlockwise = dictanceAnticlockwise();
	if (clockwise > anticlockwise) {
		return anticlockwise;
	}
	else {
		return clockwise;
	}
}
void writing() // ввод значений конструкции file с указанием на input 
{
	std::ofstream fout;
	fout.open("OUTPUT.txt"); //вывод значения в output.txt 
	if (!fout) {
		std::cout << error2 "\n";
	}
	else {
		fout << minimumDistance(); '\n';
		}
	fout.close();
}
int main()
{
	writing();
	return 1;
}


