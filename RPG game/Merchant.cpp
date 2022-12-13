#include "Merchant.h"

Merchant::Merchant() {

}
Merchant::~Merchant() {

}

void Merchant::displayMerchantInventory(std::vector<Equipment>& inventory) {

	for (int i = 0; i < inventory.size(); i++) {
		std::cout << i + 1 << ". " << inventory[i].getEquipmentName() << "\t\t" << inventory[i].getEquipmentValue() << " Coins" << std::endl;
	}
}
void Merchant::merchant(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves) {
	Equipment ironSword;
	ironSword.setEquipmentName("Iron Sword");
	ironSword.setType("Weapon");
	ironSword.setDescription("A Sword Forged In Iron.\n");
	ironSword.setEquipmentPhys(20);
	ironSword.setEquipmentValue(50);
	ironSword.setEquipable(true);
	ironSword.setEquiped(false);
	merchantInventory.push_back(ironSword);

	Equipment battleAxe;
	battleAxe.setEquipmentName("Northen Battle Axe");
	battleAxe.setType("Weapon");
	battleAxe.setDescription("A Heavy Battle Axe.\n");
	battleAxe.setEquipmentPhys(20);
	battleAxe.setEquipmentValue(50);
	battleAxe.setEquipable(true);
	battleAxe.setEquiped(false);
	merchantInventory.push_back(battleAxe);

	Equipment staff;
	staff.setEquipmentName("Magical Staff");
	staff.setType("Weapon");
	staff.setDescription("A Magical Staff Carved By The Dwarves.\n");
	staff.setEquipmentMag(20);
	staff.setEquipmentValue(50);
	staff.setEquipable(true);
	staff.setEquiped(false);
	merchantInventory.push_back(staff);

	Equipment wand;
	wand.setEquipmentName("Magical Wand");
	wand.setType("Weapon");
	wand.setDescription("A Magical Wand Carved By The Fairies.\n");
	wand.setEquipmentMag(20);
	wand.setEquipmentValue(50);
	wand.setEquipable(true);
	wand.setEquiped(false);
	merchantInventory.push_back(wand);

	Equipment ironHelmet;
	ironHelmet.setEquipmentName("Iron Helmet");
	ironHelmet.setType("Helmet");
	ironHelmet.setDescription("A Helmet Forged In Iron.\n");
	ironHelmet.setEquipmentDef(20);
	ironHelmet.setEquipmentValue(20);
	ironHelmet.setEquipable(true);
	ironHelmet.setEquiped(false);
	merchantInventory.push_back(ironHelmet);

	Equipment ironChestPlate;
	ironChestPlate.setEquipmentName("Iron ChestPlate");
	ironChestPlate.setType("Chest");
	ironChestPlate.setDescription("A ChestPlate Forged In Iron.\n");
	ironChestPlate.setEquipmentDef(50);
	ironChestPlate.setEquipmentValue(50);
	ironChestPlate.setEquipable(true);
	ironChestPlate.setEquiped(false);
	merchantInventory.push_back(ironChestPlate);

	Equipment ironGreaves;
	ironGreaves.setEquipmentName("Iron Greaves");
	ironGreaves.setType("Greaves");
	ironGreaves.setDescription("Greaves Forged In Iron.\n");
	ironGreaves.setEquipmentDef(30);
	ironGreaves.setEquipmentValue(30);
	ironGreaves.setEquipable(true);
	ironGreaves.setEquiped(false);
	merchantInventory.push_back(ironGreaves);

	Equipment redObsidionSword;
	redObsidionSword.setEquipmentName("Red Obsidion Sword");
	redObsidionSword.setType("Weapon");
	redObsidionSword.setDescription("A Firey Red Sword Forged In The Heart Of A Valcano.\n");
	redObsidionSword.setEquipmentPhys(200);
	redObsidionSword.setEquipmentValue(3000);
	redObsidionSword.setEquipable(true);
	redObsidionSword.setEquiped(false);
	merchantInventory.push_back(redObsidionSword);

	Equipment healthPotion;
	healthPotion.setEquipmentName("Health Potion");
	healthPotion.setEquipmentValue(10);
	healthPotion.setDescription("A Potion That Restores 50 HP.\n");
	healthPotion.setEquipable(false);
	merchantInventory.push_back(healthPotion);

	int buyorsell;

	do {
		std::cout << "------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Hello traveler!\nWhat can i do for ya?\n\n";

		std::cout << "1.Buy\n";
		std::cout << "2.Sell\n";
		std::cout << "3.Use Skill Points\n";
		std::cout << "0.Leave\n";
	
		std::cin >> buyorsell;
		switch (buyorsell) {
		case 1: merchantBuy(player, inventory);
			break;
		case 2: 
			if (inventory.size() == 0) std::cout << "You have nothing to sell!\n";				
			else merchantSell(player, inventory, weapon, helm, chest, greaves);
			break;
		case 3:
			player.useSkillPoints();
			break;
		case 0:
			std::cout << "See ya later!\n";
			break;
		default:
			break;
		}
	} while (buyorsell != 0);
}

void Merchant::merchantBuy(Character& player, std::vector<Equipment>& inventory) {

	int playerInput;
	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Your coins: " << player.getPCoins() << std::endl;
	std::cout << "What would you like to buy?\n\n";
	displayMerchantInventory(merchantInventory);
	std::cout << "0. Back\n";

	std::cin >> playerInput;
	playerInput -= 1;

	merchantIter = merchantInventory.begin();

	if ((playerInput + 1) != 0) {

		if (playerInput <= merchantInventory.size()) {

			std::cout << "You chose " << merchantInventory[playerInput].getEquipmentName() << "\n";

			if (player.getPCoins() >= merchantInventory[playerInput].getEquipmentValue()) { 

				if (player.getPCoins() >= merchantInventory[playerInput].getEquipmentValue()) {

					inventory.push_back(merchantInventory[playerInput]);
					//inventory[playerInput].setEquipmentValue(merchantInventory[playerInput].getEquipmentValue() - merchantInventory[playerInput].getEquipmentValue() * 0.5);

					player.setPCoins(player.getPCoins() - (merchantInventory[playerInput].getEquipmentValue())); //this is where it crashes

					std::cout << "\n\"Thank you for your purchase!\"\n";
					std::cout << "You bought: " << merchantInventory[playerInput].getEquipmentName();
					std::cout << " for " << (merchantInventory[playerInput].getEquipmentValue()) << " coins.\n";
					std::cout << merchantInventory[playerInput].getEquipmentName() << " was added to your inevntory!\n";
				}
				else std::cout << "You do not have enough coins!";
			}
			else std::cout << "\n\"Hey this aint a chairty, come back with enough coins!\"\n";
		}
		else std::cout << "\"Thats not an option!\"\n";
	}
}
void Merchant::merchantSell(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves) {
	
	bool back = false;
	int playerInput;
	do {
		std::cout << "------------------------------------------------------------------------------------------------------------\n";
		std::cout << "Your coins: " << player.getPCoins() << std::endl;
		player.displayInventory(inventory, weapon, helm, chest, greaves);
		std::cout << "0. Back\n";

		std::cout << "\nWhat would you like to sell?\n";
		std::cin >> playerInput;
		
		if (inventory.size() != 0) {
			if (playerInput == 0) { back = true; }
			else {
				playerInput -= 1; // Sets players input down by 1 to align with the vector
				std::cout << "\"You chose " << inventory[playerInput].getEquipmentName();

				std::cout << ". I will give you [" << inventory[playerInput].getEquipmentValue() << "]coins for it.\"" << std::endl;
				std::cout << "Do you accept? [Y] or [N]\n";

				char sellAnswer;
				std::cin >> sellAnswer;

				if (sellAnswer == 'y') { //subtracts players coins and removes item from inventory
					std::cout << "\"Nice doin business with ya!\"";
					player.setPCoins(player.getPCoins() + inventory[playerInput].getEquipmentValue());

					inventory.erase(inventory.begin() + playerInput);
				}
				else if (sellAnswer == 'n') {
					std::cout << "\"Unfortunate we couldnt work aout a deal!\"\n";
				}
			}
		}
		else {
			std::cout << "You have nothing to sell me!\n";
			back = true;
		}
	} while (back != true);
}