#pragma once
#include<string>
#include <vector>
#include "Character.h"
#include "Equipment.h"

class Character;

class Enemy {
private:

	std::string m_name;
	std::string m_origin;
	int m_level;

	int m_enemylightdmg;
	int m_enemyheavydmg;
	int m_enemyhp;
	int m_enemymaxhp;

	int m_enemyexp;
	int m_ecoins;

public:

	Enemy();
	virtual ~Enemy();

	void eAttack(Character& player);
	void eDeath(Character& player, std::vector<Equipment>& weapon);
	
	std::string getEnemyName() { return m_name; }
	int getEnemyHp() { return m_enemyhp; }
	int getEnemyMaxHp() { return m_enemymaxhp; }
	int getEnemyLevel() { return m_level; }

	void setEnemyHp(int hp) { m_enemyhp = hp; }
	void setEnemyMaxHp(int maxhp) { m_enemymaxhp = maxhp; }
	void setEnemyName(std::string name) { m_name = name; }
	void setEnemyLevel(int level) { m_level = level; }
	void setEnemylight(int light) { m_enemylightdmg = light; }
	void setEnemyHeavy(int heavy) { m_enemyheavydmg = heavy; }
	void setEnemyCoins(int coins) { m_ecoins = coins; }
};

