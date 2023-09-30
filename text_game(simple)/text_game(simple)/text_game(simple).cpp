// text_game(simple).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
const int My_Max_Health      = 500;
const int Default_Score      = 100;
struct Stats
{
	int health;
	int damage;
};
enum Monsters {
	Archer,Mage,Swordman,
};
int random(int Max, int Min) {
	srand(time(0));
	return Min + rand() % Max;
}

int Items(int i) {
	if (i == 1) {
		std::cout << "You choose fireball." << '\n';
		return 85;
	}
	else if (i == 2) {
		std::cout << "You choose sword. Reasonable choise. But it has some rate of random." << '\n';
		return 60 + random(50, 1);
	}
	else
		std::cout << "You choose poison. May be you have some reasons to choose it. It has huge rate of random" << '\n';
	return 35 + random(100, 1);
}
Monsters monster() {
	int random_numb = random(3, 1);
	if (random_numb == 1) {
		std::cout << "You saw someone with bow and some arrows. He looks agressive. " << '\n';
		return Archer;
	}
	else if (random_numb == 2) {
		std::cout << "You saw that someone trying to use spells. He looks agressive." << '\n';
		return Mage;
	}
	else {
		std::cout << "You saw someone with sword. He trying to fight with you." << '\n';
		return Swordman;
	}
}
Stats Monsterstats() {
	Stats Monsterstats = {0};
	Monsters Monsters = monster();
	if (Monsters == Archer) {
		Monsterstats.health = 100;
		Monsterstats.damage = 75;
	}
	else if (Monsters = Mage) {
		Monsterstats.health = 75;
		Monsterstats.damage = 100;
	}
	else {
		Monsterstats.health = 85;
		Monsterstats.damage = 85;
	}
	return Monsterstats;
}
int health(int &health, int damage) {
	health = health - damage;
	return health;
}
int oneLoopGame(int &Myhealth, Stats &monsterstats, int My_Damage, int &score ) {
	if (monsterstats.health > 0) {
		if (Myhealth > 0) {
			std::cout << "Monster tries to fight you" << '\n';
			std::cout << "Monster struck you" << monsterstats.damage << "HP of damage" << '\n';
			Myhealth = health(Myhealth, monsterstats.damage);
			std::cout << "Now you have" << Myhealth << "HP" << '\n';
			std::cout << "You can fight monster back" << '\n';
			std::cout << "You struck monster" << My_Damage << "HP of damage" << '\n';
			monsterstats.health = health(monsterstats.health, My_Damage);
			std::cout << "Now monster have" << monsterstats.health << "HP" << '\n';
		}
		else {
			std::cout << "vou've been kiled. You end with the score of" << score << '\n';
			return score;
		}
	}
	else {
		std::cout << "You killed this monster and the next monster appeared." << '\n';
		monsterstats = Monsterstats();
		score += Default_Score;
	}
}
int game() {
	int Myhealth = My_Max_Health; int score(0); int i;
	std::cout << "Do you want to enter the dangeon? 1(yes), 2(no)" << '\n';
	std::cin >> i;
	if (i == 2) {
		return 0;
	}
	else {
		std::cout << "Darkness is watching for you. You sees that something unusual mooves in the dark." << '\n';
		Stats monsterstats = Monsterstats();
		while (1) {
			int i;
			std::cout << "do you want to continue learning dangeon? 1(Sure), 2(Run away)" << '\n';
			std::cin >> i;
			if (i == 2) {
				return score;
			}
			else {
				int a;
				std::cout << "What weapon do you choose. 1(fireball), 2(sword), 3(poison)" << '\n';
				std::cin >> a;
				int My_Damage = Items(a);
				oneLoopGame(Myhealth, monsterstats, My_Damage, score);
			}
		}
	}
}
int main()
{
	int score = game();
	std::cout << " You end with a score of " << score << '\n';
	return 0;
}

