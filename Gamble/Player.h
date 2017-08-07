#pragma once

enum class Direction {
	LeftTop,	Top,	RightTop,
	Left,				Right,
	LeftBottom,	Bottom,	RightBottom
};

class Player : public Object {
private:
	float m_CurrentSpeed;
	float m_AccelerationSpeed;
	float m_MaximizeSpeed;

	float m_Angle;

	Direction m_Direction;

private:
	AnimationSprite** m_Sprites;

public:
	Player();
	~Player();

public:
	CREATE_FUNC(Player);

public:
	bool Initialize() override;

public:
	void Update(float deltaTime) override;
	void Render() override;
};

