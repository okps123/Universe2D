#pragma once
#include "Item.h"
#include "Inventory.h"

class ItemSlot : public Object {
public:
	ItemID::Enum ItemID;

private:
	Sprite* m_ItemImage;
	Sprite* m_SlotImage;

	Label* m_AmountLabel;

private:
	BoxCollider* m_Collider;

public:
	ItemSlot() {};
	~ItemSlot() {};

public:
	bool Initialize(ItemID::Enum id) {
		ItemID = id;

		m_SlotImage = Sprite::Create(L"Resources\\ui_item_box.png");
		m_SlotImage->SetAnchorPoint(0.0f, 0.0f);
		AddChild(m_SlotImage);

		m_ItemImage = Sprite::Create(L"Resources\\item_" + std::to_wstring(static_cast<int>(id)) + L".png");
		m_ItemImage->SetAnchorPoint(0.0f, 0.0f);
		m_ItemImage->SetVisible(false);
		m_ItemImage->SetZOrder(1);
		AddChild(m_ItemImage);

		m_AmountLabel = Label::Create(L"함초롬돋움", 20, D3DCOLOR_XRGB(255, 255, 255));
		m_AmountLabel->SetPosition(5, 0);
		m_AmountLabel->SetText(std::to_wstring(0));
		AddChild(m_AmountLabel);

		m_Collider = BoxCollider::Create(60, 60);
		AddChild(m_Collider);

		return true;
	}

	void Update(float deltaTime) {
		Object::Update(deltaTime);

		if (Input::GetInstance()->GetMouseHandled())
			return;

		//// 아이템을 가지고있다면 아이콘 활성화
		if (Inventory::GetInstance()->ContainsItem(ItemID, 1)) {
			m_ItemImage->SetVisible(true);
		}

		m_AmountLabel->SetText(std::to_wstring(Inventory::GetInstance()->GetAmount(ItemID)));

		if (Input::GetInstance()->GetKeyState(VK_LBUTTON) != KeyState::Down)
			return;

		auto p = Input::GetInstance()->GetMousePosition();
		if (m_Collider->IsCollideWith(p)) {
			// 아이템 가져오기
			printf("핸들 true\n");
			Input::GetInstance()->SetMouseHandled(true);
		}
	}
};

