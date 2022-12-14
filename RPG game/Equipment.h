#pragma once
#include<string>

class Character;

class Equipment{
private:

	std::string m_name;
	
	int m_Edefence;
	int m_Ephysdmg;
	int m_Emagdmg;
	int m_value;
	int m_itemsrequired;
	bool m_equiped;
	bool m_equipable;
	bool m_usable;
	bool m_magic;
	bool m_physical;
	std::string m_type;
	std::string m_description;

public:

	Equipment();
	virtual ~Equipment();

	void equipFunc(Character& player);

	std::string getEquipmentName() { return m_name; }
	int getEquipmentValue() { return m_value; }
	bool getEquiped() { return m_equiped; }
	bool getEquipable() { return m_equipable; }
	bool getUsable() { return m_usable; }
	int getEquipmentPhys() { return m_Ephysdmg; }
	int getEquipmentMag() { return m_Emagdmg; }
	int getEquipmentDef() { return m_Edefence; }
	std::string getType() { return m_type; }
	std::string getDescription() { return m_description; }
	bool getIsPhysical() { return m_physical; }
	bool getIsMagic() { return m_magic; }

	void setEquipmentName(std::string name) { m_name = name; }
	void setEquipmentPhys(int phys) { m_Ephysdmg = phys; }
	void setEquipmentMag(int mag) { m_Emagdmg = mag; }
	void setEquipmentDef(int def) { m_Edefence = def; }
	void setEquipmentValue(int value) { m_value = value; }
	void setEquiped(bool equipe) { m_equiped = equipe; }
	void setEquipable(bool equipable) { m_equipable = equipable; }
	void setUsable(bool usable) { m_usable = usable; }
	void setItemsRequired(int items) { m_itemsrequired = items; }
	void setType(std::string type) { m_type = type; }
	void setDescription(std::string description) { m_description = description; }
	void setIsPhysical(bool isphys) { m_physical = isphys; }
	void setIsMagic(bool ismag) { m_magic = ismag; }
};

