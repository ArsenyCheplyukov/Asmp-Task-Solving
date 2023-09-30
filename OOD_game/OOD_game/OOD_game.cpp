// OOD_game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
#include <string>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()

// Генерируем рандомное число между min и max
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:
	std::string m_name;
	char m_symbol;
	int m_health;
	int m_damage;
	int m_gold;

public:
	Creature(std::string name, char symbol, int health, int damage, int gold) :
		m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
	{
	}

	char getSymbol() { return m_symbol; }
	const std::string& getName() { return m_name; }
	bool isDead() { return m_health <= 0; }
	int getGold() { return m_gold; }
	void addGold(int gold) { m_gold += gold; }
	void reduceGold(int coins) { m_gold -= coins; }
	void reduceHealth(int health) { m_health -= health; }
	int getHealth() { return m_health; }
	int getDamage() { return m_damage; }
};

	class Player : public Creature
	{
		int m_level = 1;
		int m_weapon = 0;
		int m_armor = 0;
		int m_numberOfPoison = 1;
		int m_agilty = 1;

	public:
		Player(std::string name)
			: Creature(name, '@', 100, 10, 100)
		{
		}

		void levelUp()
		{
			++m_level;
			++m_damage;
			++m_agilty;
		}

		int getLevel() { return m_level; }
		void setPoison() { ++m_numberOfPoison; }
		int getPoison() { return m_numberOfPoison; }
		int getArmor() { return m_armor; }
		void setArmor(int set_a) { m_armor = set_a; }
		int getAgility() { return m_agilty; }
		int getWeapon() { return m_weapon; }
		void setWeapon(int set_w) { m_weapon = set_w; }
		bool hasWon() { return m_level >= 20; }
	};

class Shop
{
protected:
	int upgrade_item = 1;
	enum ITEMS
	{
			NOOB_ARMOR,
			STARTER_ARMOR,
			COMMON_ARMOR,
			MEDIUM_ARMOR,
			ADVANCED_ARMOR,
			HERO_ARMOR,
			LEGENDARY_ARMOR,
			UNREAL_ARMOR,
			HEALTH_POISON,
			MAX_ITEMS,
	};
		struct ItemData
		{
			std::string name;
			int attack;
			int defence;
			int heal;
			int coast;
		};
		static ItemData itemData[MAX_ITEMS];
		ITEMS m_items;

		Shop::ItemData itemData[MAX_ITEMS]
		{
			{ "noob set", 3, 5, 0, 100},
			{ "starter set", 5, 7, 0, 200},
			{ "common set", 7, 10, 0, 300},
			{ "medium set", 10, 15, 0, 400},
			{ "advanced set", 15, 20 , 0, 600},
			{ "hero's set", 20, 25, 0 , 800},
			{ "legendary set", 30, 30, 0, 1500},
			{ "unreal set", 50, 50 ,0 , 5000},
			{ "health poison", 0, 0 , 50, 50},
		};
		void up()
		{
			while (upgrade_item > MAX_ITEMS)
			{
				++upgrade_item;
			}
		}
		void upgrade(Player &p)
		{
			if (p.getGold >= itemData[upgrade_item].coast)
			{
				std::cout << "You buy " << itemData[upgrade_item].name << "\n";
				p.setArmor(itemData[upgrade_item].defence);
				p.setWeapon(itemData[upgrade_item].attack);
				p.reduceGold(itemData[upgrade_item].coast);
				std::cout << "Now you have " << p.getGold;
			}
		}
		void buy_poison(Player &p)
		{
			if (p.getGold >= itemData[MAX_ITEMS].coast)
			{
				std::cout << "You buy " << itemData[MAX_ITEMS].name << "\n";
				p.reduceGold(itemData[MAX_ITEMS].coast);
				std::cout << "Now you have " << p.getGold << "of gold \n";
				std::cout << "Now you have " << p.getPoison << "of poison \n";
			}
		}
void ShopLoop(Player &p)
{
		if (p.getGold > 0)
		{
		char i;
		std::cout << "Welcome to the shop. Whould you want to upgrade or buy something? (Y)es or (N)o \n";
		std::cin >> i;
		while (i != 'Y' || i != 'y' || i != 'N' || i != 'n')
		{
			std::cout << "Mmm... What did you say? I did not hear. \n";
			std::cin >> i;
		}
		    if (i == 'Y' || i == 'y')
			{
			char a;
			std::cout << "Do you want to (U)pgrade or (B)uy \n";
			std::cout << "If you upgrade something, last set will automatically sell \n";
			std::cin >> a;
			    while (a != 'B' || a != 'b' || a != 'U' || a != 'u')
				{
				std::cout << "Mmm... What did you say? I did not hear. \n";
				std::cin >> a;
				}
				char n;
				std::cout << p.getArmor << "of armor and" << p.getWeapon << " of weapon \n";
				std::cout << p.getGold << "of gold"; std::cout << "Coast of next upgrade is " << itemData[upgrade_item].coast << "\n";
				std::cout << "Coast of poison is" << itemData[MAX_ITEMS].coast << "\n";
				std::cout << "You have numbers of " << p.getPoison;
				std::cout << "Do you want to (B)uy poisons or (U)pgrade your set or you (C)hange your destiny? \n";
				std::cin >> n;
				while (n != 'B' || n != 'b' || n != 'C' || n != 'c' || n != 'U' || n != 'u')
				{
				std::cout << "Mmm... What did you say? I did not hear. \n";
				std::cin >> n;
				}
				if (n == 'B' || n == 'b')
				{
				if (p.getGold >= itemData[MAX_ITEMS].coast) {
				buy_poison(p);
				}
			     	else
					{
					std::cout << "You don't have enought money \n";
					}
				}
				else if (n == 'U' || n == 'u')
				{
					if (p.getGold >= itemData[upgrade_item].coast) 
					{
					    upgrade(p);
					}
				    else
					{
					    std::cout << "You don't have enought money \n";
					}
				}
			else if (n == 'C' || n == 'c')
			{
			return;
			}
		}
		else {
		return;
		}
	}
}
};

class Monster : public Creature
{
public:
	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		SKELETON,
		ZOMBIE,
		WITHER,
		MAX_TYPES
	};

	struct MonsterData
	{
		const char* name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];
	Type m_type;

	Monster(Type type)
		: Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold), m_type(type)
	{
	}

	static Monster getRandomMonster()
	{
		int num = getRandomNumber(0, MAX_TYPES - 1);
		return Monster(static_cast<Type>(num));
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 40, 20, 100 },
	{ "orc", 'o', 20, 15, 50 },
	{ "slime", 's', 5, 5, 5 },
    { "skeleton", 'a', 15, 10, 25  },
    { "zombie", 'z', 10, 15 , 25 },
    { "wither", 'w', 30, 25, 150 },
};

// Этот метод обрабатывает атаку монстра игроком
void attackMonster(Player &p, Monster &m)
{
	// Если игрок мёртв, то он не может атаковать монстра
	if (p.isDead())
		return;

	std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

	// Здоровье монстра уменьшается от урона игрока
	m.reduceHealth(p.getDamage());

	// Если монстр мёртв, увеличиваем level игрока
	if (m.isDead())
	{
		std::cout << "You killed the " << m.getName() << ".\n";
		p.levelUp();
		std::cout << "You are now level " << p.getLevel() << ".\n";
		std::cout << "You found " << m.getGold() << " gold.\n";
		p.addGold(m.getGold());
	}
}

// Этот метод обрабатывает атаку игрока монстром
void attackPlayer(Monster &m, Player &p)
{
	// Если монстр мёртв, то он не может атаковать игрока
	if (m.isDead())
		return;

	// Здоровье игрока уменьшается от урона монстра
	p.reduceHealth(m.getDamage());
	std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
}

// Этот метод обрабатывает весь бой между игроком и рандомным монстром
void fightMonster(Player &p)
{
	// Сначала генерируем рандомного монстра
	Monster m = Monster::getRandomMonster();
	std::cout << "You have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";

	// Пока монстр или игрок не мёртв, бой продолжается
	while (!m.isDead() && !p.isDead())
	{
		std::cout << "(R)un or (F)ight: ";
		char input;
		std::cin >> input;
		if (input == 'R' || input == 'r')
		{
			// 50/50 шанс удачного побега
			if (getRandomNumber(1, 2) == 1)
			{
				std::cout << "You successfully fled.\n";
				return; // встречу с монстром удалось избежать
			}
			else
			{
				// Неудачная попытка побега даёт монстру право атаковать
				std::cout << "You failed to flee.\n";
				attackPlayer(m, p);
				continue;
			}
		}

		if (input == 'F' || input == 'f')
		{
			// Сначала атакует игрок, затем монстр
			attackMonster(p, m);
			attackPlayer(m, p);
		}
	}
}

	


void stage_game() {
	srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат

	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p(playerName);
	std::cout << "Welcome, " << p.getName() << '\n';
	std::cout << "In this game you should reach 10th stage. If you do it - you win, else - lose \n";
	std::cout << "In the start of the game you have 100 of gold, try to use it with your mind \n";

	Shop s = { 0 };
	s->ShopLoop(p);

	// Если игрок не мёртв и еще не победил, то игра продолжается
	while (!p.isDead() && !p.hasWon())
		fightMonster(p);

	// К этому моменту игрок либо мёртв, либо победил
	if (p.isDead())
	{
		std::cout << "You died at level " << p.getLevel() << " and with " << p.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << p.getGold() << " gold!\n";
	}
}
int main()
{
	stage_game();

	return 0;
}
