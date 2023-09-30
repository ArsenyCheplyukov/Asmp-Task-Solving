// bulls_and_cows.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>


void reading(int & a, int & b)
{
    std::ifstream fin;
    fin.open("INPUT.txt");
    if (!fin) {
        std::cout << "error1\n";
    }
    else {
        fin >> a >> b;
    }
}

std::vector<int> converting(const int & nmbr) {
    int number = nmbr;
    std::vector<int> num;
    while (number > 9) {
        int K = number % 10;
        num.push_back(K);
        number = (number - K) / 10;
    }
    num.push_back(number);
    return num;
}

int bulls(const int & a, const int & b)
{
    std::vector<int> num1 = converting(a);
    std::vector<int> num2 = converting(b);
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (num1.at(i) == num2.at(i)) {
            ans += 1;
        }
    }
    return ans;
}

int cows(const int & a, const int & b)
{
    std::vector<int> num1 = converting(a);
    std::vector<int> num2 = converting(b);
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        for (int s = 0; s < 4; s++) {
            if (num1.at(i) == num2.at(s)) {
                ans += 1;
            }
        }
    }
    return ans;
}

void writing()
{
    int a = 0; int b = 0;
    reading(a, b);
    int bul = bulls(a, b);
    int cow = (cows(a, b) - bul);
    std::ofstream fout;
    fout.open("OUTPUT.txt");
    if (!fout) {
        std::cout << "error2!\n";
    }
    else {
        fout << bul << cow;
    }
}


int main()
{
    writing();
    return 0;
}