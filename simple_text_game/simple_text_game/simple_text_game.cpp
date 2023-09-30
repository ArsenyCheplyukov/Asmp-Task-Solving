// simple_text_game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
const int Archer_Damage       = 20;
const int max_Archer_Health   = 200;
const int Swordman_Damage     = 25;
const int max_Swordman_Health = 150;
const int Mage_Damage         = 70;
const int max_Mage_Damage     = 100;
int My_Health                 = 250;
enum Monsters
{
   Monsters_Archer,
   Monsters_Swordman,
   Monsters_Mage,
};
struct Stats
{
	int health;
	int damage;
};
struct survive
{
	int health;
	int score;
};
enum MyItems
{
	Item_Sword,
	Item_Poison,
	Item_Fireball,
};
Stats Monster_Stats(Monsters monsters) {
	Stats stats = { 0 };
	if (monsters == Monsters_Archer) {
		stats.health = max_Archer_Health;
		stats.damage = Archer_Damage;
	}
	else if (monsters == Monsters_Swordman) {
		stats.health = max_Swordman_Health;
		stats.damage = Swordman_Damage;
	}
	else if (monsters == Monsters_Mage) {
		stats.health = max_Mage_Damage;
		stats.damage = Mage_Damage;
	}
	return stats;
}
int random() {
	return rand() % 3 + 1;
}
int My_heals_points(int My_health, Stats stats) {
	std::cout << "your health is " << My_health << '\n';
	std::cout << "you take " << stats.damage << "HP damage " << '\n';
	return My_health - stats.damage;
}
int Monsters_health(Stats &stats, int damage) {
	std::cout << "monster stats are :" << "health " << stats.health << '\n';
	return stats.health - damage;
}
int kill_result() {
	int i = random();
	if (i == 1) {
	   return  My_Health;
	}
	else if (i == 2) {
	   return  My_Health/2;
	}
	else  {
		return  My_Health/5;
	}
}
Monsters monsters() {
	int i = random();
	if (i == 1) {
		return Monsters_Archer;
	}
	else if (i == 2) {
		return Monsters_Swordman;
	}
	else  {
		return Monsters_Mage;
	}
}
int your_choose() {
	int i;
	std::cout << "choose your weapon" << '\n' << "1-poison, 2 - sword, 3 - fireball" << '\n';
	std::cin >> i;
	if (0 < i & i < 4) {
		return i;
	}
	else {
		return 0;
	}
}
int weapon_damage() {
	int i = your_choose();
	   if (i == 1) {
		   return 25 + rand() % 100;
	   }
	   else if (i == 2) {
		   return 50 + rand() % 50;
	   }
	   else  {
		   return 75;
	   }
}
survive base(int &hills) {
	int i = 0; int score(100);
	survive surviver = { 0 };
		Monsters monster = monsters();
		Stats state = Monster_Stats(monster);
		int health = Monsters_health(state, i);
		if (hills > 0) {
			while (health > 0) {
				int monstdamage = weapon_damage();
				health = Monsters_health(state, monstdamage);
				hills = My_heals_points(hills, state);
			}
		}
		surviver.health = hills + kill_result();
		surviver.score = score;
		return surviver;
}

int main()
{
	int hill = My_Health;
	while (1) {
		int i;
		survive surviver = { 0 };
		std::cout << "Do you want to statrt or resume? Yes(1), No(0)" << '\n';
		std::cin >> i;
		if (i == 1) {
			survive surv = base(hill);
			return surv.score;
		}
		else {
			survive surv = base(hill);
			while (surv.health > 0) {
				surviver.score += surv.score;

			}
			return 1;
		}
	}
}


