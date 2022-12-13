#include "Enemy.h"
#include "Game.h"
#include "Character.h"

Enemy::Enemy() {
	m_name = "";
	m_origin = "";
	m_level = 1;

	m_enemylightdmg = 20;
	m_enemyheavydmg = 30;
	m_enemyhp = 100;
	m_enemymaxhp = 100;

	m_enemyexp = 75;
	m_ecoins = 5;
}
Enemy::~Enemy() {

}

//randomly generates weather the enemy does a light or heavy attack
void Enemy::eAttack(Character& player) {
	int attackPlayer;
	int randomNumber = rand();
	std::cout << "The enemy attacks!\n";
	int attack = (randomNumber % 2) + 1;

	if (attack == 1) {
		attackPlayer = player.getPHp() - m_enemylightdmg;
		player.setPHp(attackPlayer);
		std::cout << "The enemy does a light attack!\n";
		std::cout << "You take " << m_enemylightdmg << "dmg!\n\n";
	}
	else {
		attackPlayer = player.getPHp() - m_enemyheavydmg;
		player.setPHp(attackPlayer);
		std::cout << "The enemy does a heavy attack!\n";
		std::cout << "You take " << m_enemyheavydmg << "dmg!\n\n";
	}
}

//checks if the enemy is still alive then gives player his rewards
void Enemy::eDeath(Character& player, std::vector<Equipment>& weapon) {
	int randomNumber = rand();

	player.setPExp(player.getPExp() + m_enemyexp);
	if (weapon[0].getEquipmentName() == "The Golden Sword of Why") {
		player.setPCoins(player.getPCoins() + (m_ecoins * getEnemyLevel()) * 3);
		std::cout << "You recieved " << (m_ecoins * getEnemyLevel()) * 3 << " coins!\n\n";
	}
	else {
		player.setPCoins(player.getPCoins() + (m_ecoins * getEnemyLevel()));
		std::cout << "You recieved " << m_ecoins * getEnemyLevel() << " coins!\n\n";
	}

	std::cout << "You recieved " << m_enemyexp << " experience!\n\n";

	player.levelUp(weapon);
	//rng for equipment drops here.
}
