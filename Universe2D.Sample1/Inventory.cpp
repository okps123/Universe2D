#include "Precompiled.h"
#include "Inventory.h"

#include "Item.h"

void Inventory::AddItem(ItemID::Enum id, int amount) {
	m_Items[id] += amount;
}
void Inventory::RemoveItem(ItemID::Enum id, int amount) {
	m_Items[id] -= amount;
}

bool Inventory::ContainsItem(ItemID::Enum id, int amount) {
	if (amount > m_Items[id]) {
		return false;
	}

	return true;
}
