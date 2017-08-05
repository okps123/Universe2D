#pragma once

enum class ButtonState {
	Normal,
	Hover,
	Pressed
};

class Button : public Object
{
private:
	ButtonState m_State;

private:
	Sprite* m_NormalSprite;
	Sprite* m_HoverSprite;
	Sprite* m_PressedSprite;

public:
	Button() {};
	virtual ~Button() {};

public:
	bool InitializeWithButton(Sprite* normalSprite, Sprite* hoverSprite, Sprite* pressedSprite);
	bool Initialize() override {
		return false;
	}

public:
	void Update(float deltaTime) override;
};

