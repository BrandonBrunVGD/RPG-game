#pragma once
#include"Equipment.h"
#include"Character.h"

class Merchant{
private:

public:

	Merchant();
	virtual ~Merchant();

	void merchant(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves);
	void displayMerchantInventory(std::vector<Equipment>& inventory);
	void merchantBuy(Character& player, std::vector<Equipment>& inventory);
	void merchantSell(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves);

	std::vector<Equipment> merchantInventory;
	std::vector<Equipment>::iterator merchantIter;
};

