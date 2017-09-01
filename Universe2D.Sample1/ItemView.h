#pragma once
#include "Tile.h"

#include "Item.h"
#include "Inventory.h"

#include "GameManager.h"
#include "Player.h"

class ItemView : public Item {
public:
	Sprite* ItemImage;
	Tile* ItemTile;

private:
	CircleCollider* m_Collider;

public:
	ItemView() {};
	~ItemView() {};

public:
	bool Initialize(Tile* tile, ItemID::Enum id) {
		ItemImage = Sprite::Create(L"Resources\\item_" + std::to_wstring(static_cast<int>(id)) + L"_drop.png");
		AddChild(ItemImage);

		ItemTile = tile;
		ID = id;

		SetPosition(tile->GetPosition());

		m_Collider = CircleCollider::Create(60);
		AddChild(m_Collider);

		return true;
	}

public:
	void Update(float deltaTime) {
		Object::Update(deltaTime);

		if (Input::GetInstance()->GetKeyState(VK_LBUTTON) != KeyState::Down) {
			return;
		}

		auto camera = Director::GetInstance()->GetScene()->GetCamera();
		auto position = camera->ScreenToWorldPoint(Input::GetInstance()->GetMousePosition());

		auto player = GameManager::GetInstance()->Player;
		
		if (m_Collider->IsCollideWith(position) && m_Collider->IsCollideWith(player->GetPosition())) {
			Inventory::GetInstance()->AddItem(ID, 1);
			SetVisible(false);
		}
	}
};

