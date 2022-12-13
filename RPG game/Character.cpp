#include "Character.h"
#include "Enemy.h"
#include "Location.h"

Character::Character() {
	m_pname = "";
	m_pclass = "";
	m_porigin = "";

	m_php = 10;
	m_pmaxhp = 10;
	m_plevel = 1;
	m_pmaxLevel = 20;
	m_pexp = 0;
	m_pmaxexp = 100;

	m_pbasephysdmg = 0; 
	m_pbasemagdmg = 0; 

	m_pphysdmg = 0;
	m_pmagdmg = 0;

	m_pdefence = 0;

	m_pdexterity = 0;
	m_pstrength = 0;
	m_pconstitution = 0;
	m_pwisdom = 0;
	m_pintelligence = 0;
	m_pcharisma = 0;

	m_pcoins = 10000;
	m_pskillpoints = 5;
	m_inCombat = false;
	m_ableToFlee = true;
}
Character::~Character() {
	
}

void Character::newCharacter(Character& player) {
	setClass();
	setOrigin();
	setName();

	//creates items the player starts with
	Equipment brokenSword;
	brokenSword.setEquipmentName("Broken Sword");
	brokenSword.setType("Weapon");
	brokenSword.setDescription("An Iron Sword Whose Years Of Use Have Broken The Weapon.\n");
	brokenSword.setEquipmentPhys(10);
	brokenSword.setEquipmentValue(5);
	brokenSword.setEquipable(true);
	brokenSword.setEquiped(true);
	brokenSword.equipFunc(player);
	equipedWeapon.push_back(brokenSword);

	Equipment healthPotion;
	healthPotion.setEquipmentName("Health Potion");
	healthPotion.setEquipmentValue(10);
	healthPotion.setDescription("A Potion That Restores 50 HP.\n");
	healthPotion.setEquipable(false);
	healthPotion.setUsable(true);
	playerInventory.push_back(healthPotion);

	Equipment leatherHelmet;
	leatherHelmet.setEquipmentName("Leather Helmet");
	leatherHelmet.setType("Helmet");
	leatherHelmet.setDescription("A Thin Helmet Made Of Loose Leather.\n");
	leatherHelmet.setEquipmentValue(5);
	leatherHelmet.setEquipmentDef(5);
	leatherHelmet.setEquipable(true);
	leatherHelmet.setEquiped(true);
	leatherHelmet.equipFunc(player);
	equipedHelmet.push_back(leatherHelmet);

	Equipment leatherChest;
	leatherChest.setEquipmentName("Leather ChestPlate");
	leatherChest.setType("Chest");
	leatherChest.setDescription("A This ChestPlate Made Of Loose Leather.\n");
	leatherChest.setEquipmentValue(30);
	leatherChest.setEquipmentDef(30);
	leatherChest.setEquipable(true);
	leatherChest.setEquiped(true);
	leatherChest.equipFunc(player);
	equipedChest.push_back(leatherChest);

	Equipment leatherGreaves;
	leatherGreaves.setEquipmentName("Leather Greaves");
	leatherGreaves.setType("Greaves");
	leatherGreaves.setDescription("Thin Greaves Made Of Loose Leather.\n");
	leatherGreaves.setEquipmentValue(15);
	leatherGreaves.setEquipmentDef(15);
	leatherGreaves.setEquipable(true);
	leatherGreaves.setEquiped(true);
	leatherGreaves.equipFunc(player);
	equipedGreaves.push_back(leatherGreaves);

	m_pmaxhp = (m_pmaxhp + m_pdefence);
	m_php = m_pmaxhp;

	//defines what value your hp and damage is based off of
	m_pbasephysdmg = (m_pstrength + (m_pdexterity * 0.5));
	m_pbasemagdmg = (m_pintelligence + (m_pwisdom * 0.5));

	m_pphysdmg = m_pbasephysdmg + (m_plevel * 10) + equipedWeapon[0].getEquipmentPhys();
	m_pmagdmg = m_pbasemagdmg + (m_plevel * 10) + equipedWeapon[0].getEquipmentMag();
}

void Character::setClass() {
	int choice;
	std::string choiceClass = "[No Class]";
	
	std::cout << "\n------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Please select a class to view its stats.\nPress 0 to confirm Class selection.\n";
	std::cout << "1. The Crusher.\n";
	std::cout << "2. The Protector.\n";
	std::cout << "3. The Runner.\n";
	std::cout << "4. The See'er.\n";
	std::cout << "5. The Speaker.\n";
	std::cout << "6. The Mind.\n";
	std::cout << "0. Confirm Class.\n";

	do {
		std::cin >> choice;
		switch (choice) {
		case 1:
			initCrusher();		choiceClass = "Crusher";
			break;
		case 2:
			initProtector();	choiceClass = "Protector";
			break;
		case 3:
			initRunner();		choiceClass = "Runner";
			break;
		case 4:
			initSeeer();		choiceClass = "See'er";
			break;
		case 5:
			initSpeaker();		choiceClass = "Speaker";
			break;
		case 6:
			initMind();			choiceClass = "Mind";
			break;
		case 0:
			if (choiceClass == "[No Class]") std::cout << "Please select a Class.\n";
			else std::cout << "Confirmed Class: The " << choiceClass << ".\n";
			break;
		default:
			std::cout << "Invalid Input.\n";
			break;
		}
		if (choiceClass != "[No Class]" && choice != 0) {
			std::cout << "Current Selection: The " << choiceClass << ".\n";
			displayClassStats();
		}
	} while (choiceClass == "[No Class]" || choice != 0);
}

void Character::setOrigin() {
	int choice;
	std::string choiceOrigin = "[No Origin]";

	std::cout << "\n------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Please select a Origin to view its stats.\nPress 0 to confirm Origin selection.\n";
	std::cout << "1. Human.\n";
	std::cout << "2. Elf.\n";
	std::cout << "3. Dark Elf.\n";
	std::cout << "4. Dwarf.\n";
	std::cout << "5. Ogre.\n";
	std::cout << "6. Fairy.\n";
	std::cout << "0. Confirm Origin.\n";

	do {
		std::cin >> choice;
		switch (choice) {
		case 1:
			choiceOrigin = "Human";
			break;
		case 2:
			choiceOrigin = "Elf";
			break;
		case 3:
			choiceOrigin = "Dark Elf";
			break;
		case 4:
			choiceOrigin = "Dwarf";
			break;
		case 5:
			choiceOrigin = "Ogre";
			break;
		case 6:
			choiceOrigin = "Fairy";
			break;
		case 0:
			if (choiceOrigin == "[No Origin]") std::cout << "Please select an Origin.\n";
			else std::cout << "Confirmed Origin: " << choiceOrigin << ".\n";
			break;
		default:
			std::cout << "Invalid Input.\n";
			break;
		}
		if (choiceOrigin != "[No Origin]" && choice != 0) {
			std::cout << "Current Selection: " << choiceOrigin << ".\n";
			m_porigin = choiceOrigin;
			displayOriginStats();
		}
	} while (choiceOrigin == "[No Origin]" || choice != 0);
	initOrigin();
	
}

//sets players name
void Character::setName() {
	std::string name;

	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "\nWhat is your name?\n";
	do {
		std::cin >> name;
		if (name.size() < 1 || name.size() > 10) {
			std::cout << "\nName must be between 1 and 10 characters.\n";
		}
		else m_pname = name;
	} while (name.size() == 0 || name.size() > 10);
	std::cout << "\nGreetings " << m_pname << "! You are a " << m_porigin << " " << m_pclass << ".\n";
}

//sets the stats for the player based on the class thats chosen
void Character::initCrusher() {
	m_pclass = "Crusher";
	m_pdexterity = 12;
	m_pstrength = 18;
	m_pconstitution = 15;
	m_pwisdom = 8;
	m_pintelligence = 8;
	m_pcharisma = 8;
}
void Character::initProtector() {
	m_pclass = "Protector";
	m_pdexterity = 8;
	m_pstrength = 15;
	m_pconstitution = 18;
	m_pwisdom = 8;
	m_pintelligence = 10;
	m_pcharisma = 15;
}
void Character::initRunner() {
	m_pclass = "Runner";
	m_pdexterity = 18;
	m_pstrength  = 8;
	m_pconstitution = 12;
	m_pwisdom = 12;
	m_pintelligence = 12;
	m_pcharisma = 12;
}
void Character::initSeeer() {
	m_pclass = "See'er";
	m_pdexterity = 15;
	m_pstrength = 8;
	m_pconstitution = 10;
	m_pwisdom = 18;
	m_pintelligence = 18;
	m_pcharisma = 8;
}
void Character::initSpeaker() {
	m_pclass = "Speaker";
	m_pdexterity = 15;
	m_pstrength = 8;
	m_pconstitution = 10;
	m_pwisdom = 8;
	m_pintelligence = 12;
	m_pcharisma = 18;
}
void Character::initMind() {
	m_pclass = "Mind";
	m_pdexterity = 8;
	m_pstrength = 12;
	m_pconstitution = 8;
	m_pwisdom = 15;
	m_pintelligence = 18;
	m_pcharisma = 12;
}
void Character::displayClassStats() {
	std::cout << "| Strength: " << m_pstrength << "\t\t | Wisdom: " << m_pwisdom << "\t\t|\n";
	std::cout << "| Dexterity: " << m_pdexterity << "\t\t | Intelligence: " << m_pintelligence << "\t|\n";
	std::cout << "| Constitution: " << m_pconstitution << "\t | Charisma: " << m_pcharisma << "\t\t|\n";
}

//sets the stats bonuses for the origin the player selects
void Character::initOrigin() {
	if (m_porigin == "Human") m_pwisdom = (m_pwisdom * 1.3);
	if (m_porigin == "Elf") m_pcharisma = (m_pcharisma * 1.3);
	if (m_porigin == "Dark Elf") m_pdexterity = (m_pdexterity * 1.3);
	if (m_porigin == "Dwarf") m_pconstitution = (m_pconstitution * 1.3);
	if (m_porigin == "Ogre") m_pstrength = (m_pstrength * 1.3);
	if (m_porigin == "Fairy") m_pintelligence = (m_pintelligence * 1.3);
}
void Character::displayOriginStats() {
	if (m_porigin == "Human") std::cout << "+30% Wisdom to current stats.\n";
	if (m_porigin == "Elf") std::cout << "+30% Charisma to current stats.\n";
	if (m_porigin == "Dark Elf") std::cout << "+30% Dexterity to current stats.\n";
	if (m_porigin == "Dwarf") std::cout << "+30% Constitution to current stats.\n";
	if (m_porigin == "Ogre") std::cout << "+30% Strength to current stats.\n";
	if (m_porigin == "Fairy") std::cout << "+30% Intelligence to current stats.\n";
}

void Character::displayAllStats() {
	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Name: " << m_pname << "\t\t\n";
	std::cout << "Origin: " << m_porigin << "\t\t|\n";
	std::cout << "Class: " << m_pclass << "\t\t|\n\n";

	std::cout << "Hp: " << m_php << " / " << m_pmaxhp << "\t\t|\n";
	std::cout << "Exp: " << m_pexp << " / " << m_pmaxexp << "\t\t|\n";
	std::cout << "Level: " << m_plevel << " / " << m_pmaxLevel << "\t\t|\n";
	std::cout << "Physical Damage: " << m_pbasephysdmg << "\t| (Strength + 0.5 Dexterity)\n";
	std::cout << "Magic Damage: " << m_pbasemagdmg << "\t| (Intelligence + 0.5 Wisdom)\n";
	std::cout << "Defence: " << m_pdefence << "\t\t|\n\n";

	std::cout << "Equiped Weapon: " << equipedWeapon[0].getEquipmentName() << "\t\t| Phys Damage: " << equipedWeapon[0].getEquipmentPhys() << " Mag Damage: " << equipedWeapon[0].getEquipmentMag() << "\n";
	std::cout << "Equiped Helmet: " << equipedHelmet[0].getEquipmentName() << "\t\t| Defence: " << equipedHelmet[0].getEquipmentDef() << "\n";
	std::cout << "Equiped ChestPlate: " << equipedChest[0].getEquipmentName() << "\t| Defence: " << equipedChest[0].getEquipmentDef() << "\n";
	std::cout << "Equiped Greaves: " << equipedGreaves[0].getEquipmentName() << "\t| Defence: " << equipedGreaves[0].getEquipmentDef() << "\n\n";

	std::cout << "Total Damage Output: " << m_pphysdmg << "\t | (Physical Damage + Weapon Damage + 10x Player Level)\n\n";

	displayClassStats();
}

//Character Actions
void Character::combat(Enemy& enemy, Character& player, Location& home) {
	m_inCombat = true;
	int choice;
	bool endTurn;
	bool endCombat = false;

		do {
			endTurn = false;
			std::cout << "------------------------------------------------------------------------------------------------------------\n";
			std::cout << "[You]\t\t\t\t[" << enemy.getEnemyName() << "]\n";
			std::cout << "Hp: " << m_php << " / " << m_pmaxhp << "\t\t\t" << "Hp: " << enemy.getEnemyHp() << " / " << enemy.getEnemyMaxHp() << "\n\n\n";

			std::cout << "1. Attack \t| 2. Inventory \t| 0. Display Stats \t|\n";
			std::cout << "3. Taunt \t| 4. Flee \t|\n";

			std::cin >> choice;
			switch (choice) {
			case 1:
				char atkchoice;
				do { //attacks the enemy for the players physical damage times a light or heavy attack
					int atkEnemy;
					std::cout << "[l] light attack (" << m_pphysdmg << " Damage)\n[h] heavy attack (" << m_pphysdmg * 1.5 << " Damage)\n\n";
					std::cin >> atkchoice;
					if (atkchoice == 'l') {
						atkEnemy = (enemy.getEnemyHp() - m_pphysdmg);
						enemy.setEnemyHp(atkEnemy);
						std::cout << "You attacked " << enemy.getEnemyName() << " for " << player.getPPhysDmg() << "Hp!\n";
					}
					else if (atkchoice == 'h') {//TO DO. add to check if its been 2 turns before using another heavy atk.
						atkEnemy = enemy.getEnemyHp() - (m_pphysdmg * 1.50);
						enemy.setEnemyHp(atkEnemy);
						std::cout << "You attacked " << enemy.getEnemyName() << " for " << (player.getPPhysDmg() * 1.50) << "Hp!\n";
					}
				} while (atkchoice != 'l' && atkchoice != 'h');
				endTurn = true;
				break;

			case 2: Inventory(player, playerInventory, equipedWeapon, equipedHelmet, equipedChest, equipedGreaves);
				break;

			case 3:
				if (m_pcharisma >= 18) {
					std::cout << "You insult the enemies mother.\n";
					endTurn = true;
				}
				else std::cout << "You must have atleast 18 Charisma to taunt!\n";
				break;

			case 4:
				if (m_ableToFlee == true) {
					if (m_pdexterity >= 18) {
						int randomNumber = rand();
						int fleeChance = (randomNumber % 3) + 1;

						if (fleeChance == 3) { endCombat = true; std::cout << "You fled\n"; }
						else { std::cout << "You failed to escape!"; endTurn = true; }
					}
					else std::cout << "You must have atleast 18 Dexterity to flee!\n";
				}
				else { std::cout << "You cannot flee here.\n"; }
				break;

			case 0:
				player.displayAllStats();
				break;

			default:
				std::cout << "Invalid Input";
				break;
			}

			
			if (enemy.getEnemyHp() <= 0) {
				std::cout << "The enemy" << enemy.getEnemyName() << " has fallen!\n";
				endCombat = true;
				enemy.eDeath(player, equipedWeapon);
			}
			else if (endTurn == true)
				enemy.eAttack(player);
			
			if (player.getPHp() <= 0) {
				int deathChoice;
				do {
					std::cout << "\n\tYou have died a horrible death!\n";
					std::cout << "[1]Respawn?\n";
					endCombat = true;
					std::cin >> deathChoice;
					if (deathChoice == 1) {

					}
					else std::cout << "Invalid Input\n";

				} while (deathChoice != 0 && deathChoice != 1);
			}

		} while (endCombat != true);
		m_inCombat = false;
}

//increases the players level, max experience, and skill points once the max experience has been met
void Character::levelUp(std::vector<Equipment>& weapon) {
	if (m_pexp >= m_pmaxexp) {
		m_pmaxexp *= 1.10;
		m_pexp = 0;
		m_pskillpoints += 1;
		m_plevel += 1;
		std::cout << "Congradulations! You leveled up to: lvl" << m_plevel << std::endl;
		std::cout << "+1 skill point.\n";

		m_pphysdmg = m_pbasephysdmg + (m_plevel * 10) + weapon[0].getEquipmentPhys();
		m_pmagdmg = m_pbasemagdmg + (m_plevel * 10) + weapon[0].getEquipmentMag();
	}
}
void Character::useSkillPoints() {
	if (m_pskillpoints != 0) {
		int choice;
		
		do {
			std::cout << "\nYour Stats:\n";
			displayClassStats();
			std::cout << "Your Skill Points: " << m_pskillpoints << "\n\n";
			std::cout << "Please select your choice.\n";
	
			std::cout << "1.Strength\n2.Dexterity\n3.Constitution\n4.Wisdom\n5.Intelligance\n6.Charisma\n0.Back\n";
			std::cin >> choice;
			if (choice > 0 && choice < 6) {

				std::string statName;

				std::cout << "Please input how many times you would like to level up " << statName << ".\n";
				int lvlAmount;
				std::cin >> lvlAmount;
				if (lvlAmount <= m_pskillpoints) {

					//increases the players stats based on how many skill points they used
					if (choice == 1) { m_pstrength += lvlAmount; statName = "Strength"; }
					else if (choice == 2) { m_pdexterity += lvlAmount; statName = "Dexterity"; }
					else if (choice == 3) { m_pconstitution += lvlAmount; statName = "Constitution"; }
					else if (choice == 4) { m_pwisdom += lvlAmount; statName = "Wisdom"; }
					else if (choice == 5) { m_pintelligence += lvlAmount; statName = "Intelligence"; }
					else if (choice == 6) { m_pcharisma += lvlAmount; statName = "Charisma"; }
					else { std::cout << "Invalid Input\n"; }

					m_pskillpoints -= lvlAmount;
					std::cout << statName << " has been level up by " << lvlAmount << ".\n";
				}
				else {
					std::cout << "You do not have enough skill points.\n";
				}
			}

		} while (choice != 0);
	}
	else {
		std::cout << "You do not have any skill points to use.\n";
	}

	m_pbasephysdmg = (m_pstrength + (m_pdexterity * 0.5));
	m_pbasemagdmg = (m_pintelligence + (m_pwisdom * 0.5));

	m_pphysdmg = m_pbasephysdmg + (m_plevel * 10) + equipedWeapon[0].getEquipmentPhys();
	m_pmagdmg = m_pbasemagdmg + (m_plevel * 10) + equipedWeapon[0].getEquipmentMag();
}
void Character::displayInventory(std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves) {
	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Your Inventory\n\n";
	std::cout << "Coins: " << m_pcoins << "\n\n";

	//displays the item that the player has equiped
	std::cout << "[E] " << weapon[0].getEquipmentName() << "\t\t\t" << weapon[0].getEquipmentValue() << "Coins\n\n";
	std::cout << "[E] " << helm[0].getEquipmentName() << "\t\t\t" << helm[0].getEquipmentValue() << "Coins" << std::endl;
	std::cout << "[E] " << chest[0].getEquipmentName() << "\t\t\t" << chest[0].getEquipmentValue() << "Coins" << std::endl;
	std::cout << "[E] " << greaves[0].getEquipmentName() << "\t\t\t" << greaves[0].getEquipmentValue() << "Coins" << std::endl << std::endl;

	//displays the items the player has in his inventory
	for (int i = 0; i < inventory.size(); i++) {
		std::cout << i + 1 << ". " << inventory[i].getEquipmentName() << "\t\t\t" << inventory[i].getEquipmentValue() << " Coins" << std::endl;
	}
}
void Character::Inventory(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves) {
	char equip;
	int choice;

	do {
		player.displayInventory(playerInventory, equipedWeapon, equipedHelmet, equipedChest, equipedGreaves);
		
		std::cout << "0. Back\n\n";
		std::cin >> choice;
		if (choice == 0) {

		}
		else if (choice <= inventory.size()) {
			std::cout << "\nYou selected " << inventory[choice - 1].getEquipmentName() << std::endl;
			int equipeUse;
			do {
				bool done = false;

				std::cout << "What would you like to do with this item?\n";
				std::cout << "1.Equipe\n2.Use\n3.Description\n0.Back\n";
					
				std::cin >> equipeUse;
				switch (equipeUse) {
				case 1:
					if (inventory[choice - 1].getEquipable() == true) {

						if (inventory[choice - 1].getType() == "Weapon") {
							std::cout << "You equiped this item.\n";
							inventory[choice - 1].setEquiped(true);

							weapon.push_back(inventory[choice - 1]); //equipes item

							weapon[0].setEquiped(false);
							player.setPPhysDmg(player.getPPhysDmg() - weapon[0].getEquipmentPhys());
							player.setPMagDmg(player.getPMagDmg() - weapon[0].getEquipmentMag());

							inventory.push_back(weapon[0]); //puts old equiped weapon in inventory
							weapon.erase(weapon.begin()); //unequips old equiped weapon

							inventory.erase(inventory.begin() + (choice - 1)); //gets rid of item in inventory

							weapon[0].setEquiped(true);
							player.setPPhysDmg(player.getPPhysDmg() + weapon[0].getEquipmentPhys());
							player.setPMagDmg(player.getPMagDmg() + weapon[0].getEquipmentMag());

							done = true;
						}
						else if (inventory[choice - 1].getType() == "Helmet") {
							std::cout << "You equiped this item.\n";
							inventory[choice - 1].setEquiped(true);

							helm.push_back(inventory[choice - 1]); //equipes item

							weapon[0].setEquiped(false);
							m_pmaxhp = (m_pmaxhp - m_pdefence);
							player.setPDefence(player.getPDefence() - helm[0].getEquipmentDef());

							inventory.push_back(helm[0]); //puts old equiped weapon in inventory
							helm.erase(helm.begin()); //unequips old equiped weapon

							inventory.erase(inventory.begin() + (choice - 1)); //gets rid of item in inventory

							weapon[0].setEquiped(true);
							player.setPDefence(player.getPDefence() + helm[0].getEquipmentDef());
							m_pmaxhp = (m_pmaxhp + m_pdefence);

							done = true;
						}
						else if (inventory[choice - 1].getType() == "Chest") {
							std::cout << "You equiped this item.\n";
							inventory[choice - 1].setEquiped(true);

							chest.push_back(inventory[choice - 1]); //equipes item

							chest[0].setEquiped(false);
							m_pmaxhp = (m_pmaxhp - m_pdefence);
							player.setPDefence(player.getPDefence() - chest[0].getEquipmentDef());

							inventory.push_back(chest[0]); //puts old equiped weapon in inventory
							chest.erase(chest.begin()); //unequips old equiped weapon

							inventory.erase(inventory.begin() + (choice - 1)); //gets rid of item in inventory

							chest[0].setEquiped(true);
							player.setPDefence(player.getPDefence() + chest[0].getEquipmentDef());
							m_pmaxhp = (m_pmaxhp + m_pdefence);

							done = true;
						}
						else if (inventory[choice - 1].getType() == "Greaves") {
							std::cout << "You equiped this item.\n";
							inventory[choice - 1].setEquiped(true);

							greaves.push_back(inventory[choice - 1]); //equipes item

							greaves[0].setEquiped(false);
							m_pmaxhp = (m_pmaxhp - m_pdefence);
							player.setPDefence(player.getPDefence() - greaves[0].getEquipmentDef());

							inventory.push_back(greaves[0]); //puts old equiped greaves in inventory
							greaves.erase(greaves.begin()); //unequips old equiped greaves

							inventory.erase(inventory.begin() + (choice - 1)); //gets rid of item in inventory

							greaves[0].setEquiped(true);
							player.setPDefence(player.getPDefence() + greaves[0].getEquipmentDef());
							m_pmaxhp = (m_pmaxhp + m_pdefence);

							done = true;
						}
						if (m_inCombat == false) { m_php = m_pmaxhp; }

						m_pphysdmg = m_pbasephysdmg + (m_plevel * 10) + equipedWeapon[0].getEquipmentPhys();
						m_pmagdmg = m_pbasemagdmg + (m_plevel * 10) + equipedWeapon[0].getEquipmentMag();
					}
					else std::cout << "This item is not equipable.\n";
					break;
				case 2:
					if (inventory[choice - 1].getUsable() == false) {
						std::cout << "This item is not usable.\n";
					}
					else {
						std::cout << "You used this item.\n";
						std::cout << inventory[choice - 1].getEquipmentName() << " has been removed from inventory.\n";
						inventory.erase(inventory.begin() + (choice - 1));
						std::cout << "\nYou healed 50 Hp!\n";
						player.setPHp(player.getPHp() + 50);
						done = true;
					}
					break;
				case 3:
					std::cout << inventory[choice - 1].getDescription();
					done = true;
					break;
				case 0:

					break;
				default:
					std::cout << "Invalid Input\n";
					break;
				}

				if (done == true) {
				break;
				}
			}
			while (equipeUse != 0);	
		}
		else {
		std::cout << "Invalid Input\n";
		}
	} 
	while (choice != 0);
}