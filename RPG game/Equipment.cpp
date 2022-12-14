#include "Equipment.h"
#include"Character.h"

Equipment::Equipment() {

	m_name = "";
	m_Edefence = 0;
	m_Ephysdmg = 0;
	m_Emagdmg = 0;
	m_value = 0;
	m_itemsrequired = 0;
	m_equiped = false;
	m_equipable = false;
	m_usable = false;
	m_magic = false;
	m_physical = false;
	m_type = "";
}
Equipment::~Equipment() {

}

//checks to see if the item is equiped then adds bonuses
void Equipment::equipFunc(Character& player) {
	if (m_equiped == true) {
		player.setPPhysDmg(player.getPPhysDmg() + m_Ephysdmg);
		player.setPMagDmg(player.getPMagDmg() + m_Emagdmg);
		player.setPDefence(player.getPDefence() + m_Edefence);
	}
	
}
