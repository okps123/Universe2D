#pragma once
#include "Item.h"

class Inventory : public Singleton<Inventory> {
private:
	std::unordered_map<ItemID::Enum, int> m_Items;

public:
	Inventory() {};
	~Inventory() {};

public:
	void AddItem(ItemID::Enum id, int amount);
	void RemoveItem(ItemID::Enum id, int amount);

	bool ContainsItem(ItemID::Enum id, int amount);
};