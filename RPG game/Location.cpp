#include "Location.h"
#include "Character.h"
#include "Merchant.h"
#include "Enemy.h"

Location::Location() {
	m_locName = "";
	m_locLevel = 1;
}
Location::~Location() {

}

void Location::locTown() {
	m_locName = "Town";
	m_locLevel = 1;
}
//does litteraly nothing
void Location::locWishingWell(Character& player, std::vector<Equipment>& inventory) {
	m_locName = "Wishing well";
	m_locLevel = 1;
	std::cout << "----------------------------------------\n";
	std::cout << "|              __________              |\n";
	std::cout << "|         ____//________\\\\             |\n";
	std::cout << "|         ||-//----||----\\\\            |\n";
	std::cout << "|         || ||   |TT|   ||            |\n";
	std::cout << "|      c==[] ||   \\__/   ||            |\n";
	std::cout << "|      ___   ||__________||   ___      |\n";
	std::cout << "|AAAAAA| |  |][][][][][][][|  | |AAAAAA|\n";
	std::cout << "|||||||| |  |[][][][][][][]|  | ||||||||\n";
	std::cout << "|||||||| |  |][][][][][][][|  | ||||||||\n";
	std::cout << "----------------------------------------\n\n";
	std::cout << "You visit the local wishing well filled with dreams and high hopes.\n";
	char yesno;
	int coinsThrown = 0;
	do {
		std::cout << "Your coins: " << player.getPCoins() << std::endl;
		std::cout << "Toss a coin? [y] or [n]\n";
		std::cin >> yesno;
		if (yesno == 'y') {
			std::cout << "You tossed a golden coin into a useless well. What a waste!\n";
			player.setPCoins(player.getPCoins() - 1);
			coinsThrown += 1;
			if (coinsThrown == 100) {
				std::cout << "\nAfter what previously seemed to be a very wasteful day the well glows and a sword shimmering\n";
				std::cout << "with gold gets spit out of the well and lands in your hand.\n";
				std::cout << "On the blade is an engraving reading \"For whom has no love for value shall deserve it the most\".\n";

				Equipment goldSword;
				goldSword.setEquipmentName("The Golden Sword of Why");
				goldSword.setType("Weapon");
				goldSword.setDescription("A Golden Sword Made For Those Who Are Dumb Enough To Throw Away Perfectly Good Coin.\n");
				goldSword.setEquipmentValue(99);
				goldSword.setEquipmentPhys(50);
				goldSword.setEquipable(true);
				goldSword.setEquiped(false);
				inventory.push_back(goldSword);

				std::cout << "\nThe Golden Sword of Why was added to your inventory!\n\n";
			}
		}
	} while (yesno != 'n');
}
//creates and loads the merchant
void Location::locMerchant(Character& player, std::vector<Equipment>& inventory, std::vector<Equipment>& weapon, std::vector<Equipment>& helm, std::vector<Equipment>& chest, std::vector<Equipment>& greaves) {
	m_locName = "Merchant";
	m_locLevel = 1;
	Merchant merchant;
	merchant.merchant(player, inventory, weapon, helm, chest, greaves);
}
//creates and loads the dungeon level
void Location::locDungeon(Character& player, Location& home, std::vector<Equipment>& inventory) {

	bool endDungeon = false;

	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "You enter the dungeon and get ambushed by a giant venomous spider.\n";
	Enemy spider;
	spider.setEnemyName("Spider");
	spider.setEnemyLevel(player.getPLevel());
	player.combat(spider, player, home);
	

	char leftright;
	std::cout << "You continue through the main hall of the dungeon and come to a fork in your path.\n";
	do {
		std::cout << "Left or Right? [l] or [r]\n";
		std::cin >> leftright;
		if (leftright == 'l') {
			std::cout << "You come across a horde of monster big and small, do you challenge? [y] or [n]\n";
			char yesno;
			std::cin >> yesno;
			if (yesno == 'y') {
				std::cout << "You challenge the first enemy of many bravely.\n";
				
				if (player.getPHp() > 0) {
					std::cout << "A ghostly being flies towards you.\n";
					Enemy reaper;
					reaper.setEnemyName("Reaper");
					reaper.setEnemyLevel(player.getPLevel());
					player.combat(reaper, player, home);
				}
				else { endDungeon = true; }

				if (player.getPHp() > 0) {
					std::cout << "An infested zombified creature approches.\n";
					Enemy infested;
					infested.setEnemyName("Infested Creature");
					infested.setEnemyLevel(player.getPLevel());
					player.combat(infested, player, home);
				}
				else { endDungeon = true; }

				if (player.getPHp() > 0) {
					std::cout << "A bat large enough to devour a man swoops down out of the darkness.\n";
					Enemy bat;
					bat.setEnemyName("Monstrous Bat");
					bat.setEnemyLevel(player.getPLevel());
					player.combat(bat, player, home);
				}
				else { endDungeon = true; }

				if (player.getPHp() > 0) {
					std::cout << "The final enemy walks towards you slowly dragging a rot filled club against the\n";
					std::cout << "cold concret floor, its apperence resembles that of an ogre who has not lived for many winters.\n";
					Enemy deadOgre;
					deadOgre.setEnemyName("Un-Dead Ogre");
					deadOgre.setEnemyLevel(player.getPLevel());
					deadOgre.setEnemylight(30);
					deadOgre.setEnemyHeavy(40);
					deadOgre.setEnemyCoins(30);
					player.combat(deadOgre, player, home);
				} {endDungeon = true; }

				if (endDungeon != true) {
					std::cout << "You have defeated all the horrible monsters whose years of being encapsuled have taken their toll.\n";
					std::cout << "You stand before a sarcophagus belonging to a powerful leader whom once rulled over these lands.\n";
					char openchest;
					std::cout << "Do you chose to open it? [y] or [n].\n";
					std::cin >> openchest;
					if (openchest == 'y') {
						std::cout << "You have been rewarded for your bravery and are showered in gold, however you cannot\n";
						std::cout << "help but feel that you have released some sort of evil upon the world and will soon\n";
						std::cout << "come to regret your decision.\n";
						std::cout << "\n+200coins!\n+50 Permanant Hit Points!\n";

						player.setPMaxHp(player.getPMaxHp() + 50);
						player.setPCoins(player.getPCoins() + 200);

						std::cout << "You head for home and rest for your adventure was exciting and your loot was plentyfull.\n";
						endDungeon = true;
					}
					else if (openchest == 'n') {
						std::cout << "You turn around and head out the way you came in woundering what could have been\n";
						std::cout << "waiting for you in the tomb. However maybe some things are best left untouched...\n";
						std::cout << "\nYou return to the previous room.\n";
					}
				}
			}
			else if (yesno == 'n') {
				std::cout << "You turn around to exit the room but just before you make your swiftly escape a\n";
				std::cout << "skeletal archer draws its rotten wood bow and strikes you from behind.\nYou take 20 hit points.\n";
				player.setPHp(player.getPHp() - 20);
				std::cout << "\nYou return to the previous room.\n";
			}
		}
		else if (leftright == 'r') {
			std::cout << "\nYou come across a large door towering about you.\n";
			std::cout << "You have the sense it is made to keep something in but havbe the urge to open it.\n";
			std::cout << "Do you open it? [y] or [n].\n";
			char openDoor;
			std::cin >> openDoor;
			if (openDoor == 'y') {
				player.setAbleToFlee(false);
				std::cout << "You lean forward and push the giant wooden door open with your whole body.\n";
				std::cout << "--------------------------------------------------\n";
				std::cout << "|  '  |             ___/-----\\             |'    |\n";
				std::cout << "| '   |            |____ (/) |             |   ' |\n";
				std::cout << "| ' ' |      A     V__V____/ |             |  '  |\n";
				std::cout << "|  '  |     |/|   _____| | | |__________   | ' ' |\n";
				std::cout << "| MMM |   __|/|__/____/ /  | |          \\  | MMM |\n";
				std::cout << "| |_| |  /  | \\      / /  / /________   |  | |_| |\n";
				std::cout << "|  V  |  |  | _\\_____| |  | |        \\  /  |  V  |\n";
				std::cout << "|     |  \\_ \\/       \\ \\  \\ \\________|_/   |     |\n";
				std::cout << "|     |      \\________\\_\\__\\_________/     |     |\n";
				std::cout << "|     |                                    |     |\n";
				std::cout << "--------------------------------------------------\n";
				std::cout << "Inside an enormous serpent with dark grey scales and blood red eyes slithers behind you faster then you can blink\n";
				std::cout << "slamming the door shut and pushes you towards the other end of the room with your back towards the wall.\n";
				std::cout << "There is only one thing you can do. Fight for your life.\n";
				Enemy bossSerpant;
				bossSerpant.setEnemyName("Black Cobra, Warden Of The Dead");
				bossSerpant.setEnemyLevel(player.getPLevel());
				bossSerpant.setEnemylight(30);
				bossSerpant.setEnemyHeavy(50);
				bossSerpant.setEnemyHp(200);
				bossSerpant.setEnemyMaxHp(200);
				bossSerpant.setEnemyCoins(2000);
				player.combat(bossSerpant, player, home);
				if (player.getPHp() <= 0) { endDungeon = true; }

				std::cout << "\nAgainst all odds you have defeated the warden of the dead and may live to see another day.\n";
				std::cout << "You are rewarded with The Abysal Serpant Sword.\n";

				Equipment snakeSword;
				snakeSword.setEquipmentName("The Abysal Serpant Sword");
				snakeSword.setType("Weapon");
				snakeSword.setDescription("A Black Sword Forged From The Scales Of The Black Cobra, Warden of the dead.\n");
				snakeSword.setEquipmentPhys(100);
				snakeSword.setItemsRequired(1);
				snakeSword.setEquipable(true);
				snakeSword.setEquiped(false);
				inventory.push_back(snakeSword);

				std::cout << "\nThe Abysal Serpant Sword was addad to your inventory.\n";

				std::cout << "\nYou enter a small trap door hidden under where the serpent layed leading to a cave.\n";
				std::cout << "Seeing the light of day from afar you leave the cave into the forest that you know well.\n";
				std::cout << "You head for home and rest for your adventure was exciting and your loot was plentyfull.\n";
				player.setAbleToFlee(true);
				endDungeon = true;
			}
			else if (openDoor == 'n') {
				std::cout << "You ignore the giant door and carry on past into a hall evenly distributed with slow burning torches.\n";
				std::cout << "You come to a dead end, when you turn around you hear a loud thud followed by a torch on the other end of the hall\n";
				std::cout << "burning out. Then again. And again. Slowly as the torches burn out, the thuds get louder\nand shorter between one another.\n";
				std::cout << "As the room gets darker and darker with each passing moment you\nknow that there is no wheres to run, and no wheres to hide.\n";
				std::cout << "Then. Darkness.\n";
				endDungeon = true;
			}
		}
	}while (endDungeon != true);

	home.locHome(player);
}
//does litteraly nothing
void Location::locLocalCave() {
	m_locName = "Local Cave";
	m_locLevel = 1;
	std::cout << "Sorry, This location is currently unavailable.\n";
}
//spawn location for player and allows player to rest to restore hp
void Location::locHome(Character& player) {
	m_locName = "Home";
	m_locLevel = 1;
	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << "\nYou awake in your home, nestled in a small town known for its excellence in trading and adventure.\n";
	int choice;
	std::cout << "1.Rest\n2.Leave\n";
	std::cin >> choice;
	if (choice == 1) {
		std::cout << "You ley on your bed made of straw for rest.\n";
		std::cout << "HP fully restored.\n";
		player.setPHp(player.getPMaxHp());
	}
}