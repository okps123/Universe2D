#pragma once
class ItemBox : public Object {
private:
	Sprite* m_Sprite;

public:
	ItemBox() {};
	~ItemBox() {};

public:
	bool Initialize(Sprite* sprite) {
		m_Sprite = sprite;
		AddChild(m_Sprite);

		return true;
	}

public:
	void Update(float deltaTime) {
		Object::Update(deltaTime);


	}
};

