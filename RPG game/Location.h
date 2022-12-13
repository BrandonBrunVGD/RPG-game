#pragma once

#include <string>
#include <vector>

#include "Equipment.h"

class Character;

class Location{
protected:

	std::string m_locName;
	int m_locLevel;

public:

	Location();
	virtual ~Location();

	void locTown();
	void locWishingWell(Character& player, std::vector<Equipment>& inventory);
	void locDungeon(Character& player, Location& home, std::vector<Equipment>& inventory);
	void locMerchant(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves);
	void locLocalCave();
	void locHome(Character& player);

	int getLocLevel() { return m_locLevel; }

	void setLocName(std::string name) { m_locName = name; }
	void setLocLevel(int lvl) { m_locLevel = lvl; }
};

