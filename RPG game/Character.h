#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

#include "Equipment.h"
#include "Location.h"

class Enemy;

class Character {
protected:

	std::string m_pname;
	std::string m_pclass;
	std::string m_porigin;

	int m_php;
	int m_pmaxhp;
	int m_pexp;
	int m_pmaxexp;
	int m_plevel;
	int m_pmaxLevel;

	int m_pbasephysdmg;
	int m_pbasemagdmg;

	int m_pphysdmg;
	int m_pmagdmg;
	int m_pdefence;

	int m_pdexterity;
	int m_pstrength;
	int m_pconstitution;
	int m_pwisdom;
	int m_pintelligence;
	int m_pcharisma;

	int m_pcoins;
	int m_pskillpoints;
	bool m_inCombat;
	bool m_ableToFlee;
	

public:

	Character();
	virtual ~Character();
	//initalize character
	void newCharacter(Character& player);
	void setClass();
	void initOrigin();
	void setOrigin();
	void setName();
	//character classes
	void initCrusher();
	void initProtector();
	void initRunner();
	void initSeeer();
	void initSpeaker();
	void initMind();
	//character stats
	void displayClassStats();
	void displayOriginStats();
	void displayAllStats();
	//character actions
	void combat(Enemy& enemy, Character& player, Location& home);
	
	void levelUp(std::vector<Equipment>& weapon);
	void useSkillPoints();

	int getPExp() { return m_pexp; }
	int getPLevel() { return m_plevel; }
	int getPPhysDmg() { return m_pphysdmg; }
	int getPMagDmg() { return m_pmagdmg; }
	int getPHp() { return m_php; }
	int getPMaxHp() { return m_pmaxhp; }
	int getPCoins() { return m_pcoins; }
	int getPDefence() { return m_pdefence; }
	std::vector<Equipment>& getPInventory() { return playerInventory; }
	std::vector<Equipment>& getEquipedWeapon() { return equipedWeapon; }
	std::vector<Equipment>& getEquipedHelmet() { return equipedHelmet; }
	std::vector<Equipment>& getEquipedChest() { return equipedChest; }
	std::vector<Equipment>& getEquipedGreaves() { return equipedGreaves; }

	void setPHp(int hp) { m_php = hp; }
	void setPMaxHp(int maxhp) { m_pmaxhp = maxhp; }
	void setPExp(int exp) { m_pexp = exp; }
	void setPCoins(int coins) { m_pcoins = coins; }
	void setPPhysDmg(int phys) { m_pphysdmg = phys; }
	void setPMagDmg(int mag) { m_pmagdmg = mag; }
	void setPDefence(int def) { m_pdefence = def; }
	void setAbleToFlee(bool flee) { m_ableToFlee = flee; }

	std::vector<Equipment> playerInventory;
	std::vector<Equipment> equipedWeapon;
	std::vector<Equipment> equipedHelmet;
	std::vector<Equipment> equipedChest;
	std::vector<Equipment> equipedGreaves;

	void Inventory(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves);
	void displayInventory(std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves);
};

