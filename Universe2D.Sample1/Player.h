#pragma once
class Player : public Object {
private:
	Sprite* m_Sprite;

public:
	Player() {};
	~Player() {};

public:
	CREATE_FUNC(Player);

public:
	bool Initialize() {
		m_Sprite = Sprite::Create(L"Resources\\player.png");
		AddChild(m_Sprite);

		return true;
	}
	
public:
	void Update(float deltaTime) {
		Object::Update(deltaTime);
	}
};

