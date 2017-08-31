#pragma once
class SideMenu : public Object {
private:
	Sprite* m_SideMenu;

	Sprite* m_Side1;
	Sprite* m_Side2;
	Sprite* m_Side3;
	Sprite* m_Side4;

public:
	SideMenu() {};
	~SideMenu() {};

public:
	CREATE_FUNC(SideMenu);

public:
	bool Initialize() {
		m_SideMenu = Sprite::Create(L"Resources\\ui_side_menu.png");
		m_SideMenu->SetAnchorPoint(0.0f, 0.0f);

		AddChild(m_SideMenu);

		m_Side1 = Sprite::Create(L"Resources\\ui_side_menu_detail.png");
		m_Side1->SetAnchorPoint(1.f, 0.f);
		m_Side1->SetPosition(0, 6);
		AddChild(m_Side1);

		return true;
	}

public:
	void Update(float deltaTime) {
		Object::Update(deltaTime);

		if (Input::GetInstance()->GetMouseHandled())
			return;

		if (Input::GetInstance()->GetKeyState(VK_LBUTTON) != KeyState::Down)
			return;

		auto p = Input::GetInstance()->GetMousePosition();

		if (BoxCollider::IsCollide(m_Position.x + 6, m_Position.y + 7, 50, 50, p)) {
			printf("1\n");
		} else if (BoxCollider::IsCollide(m_Position.x + 6, m_Position.y + 61, 50, 50, p)) {
			printf("2\n");
		} else if (BoxCollider::IsCollide(m_Position.x + 6, m_Position.y + 115, 50, 50, p)) {
			printf("3\n");
		} else if (BoxCollider::IsCollide(m_Position.x + 6, m_Position.y + 169, 50, 50, p)) {
			printf("4\n");
		}
	}
};

