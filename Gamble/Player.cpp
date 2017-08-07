#include "Precompiled.h"
#include "Player.h"

Player::Player()
	: m_CurrentSpeed(0.f)
	, m_AccelerationSpeed(0.f)
	, m_MaximizeSpeed(0.f)
	, m_Angle(0.f)
	, m_Direction(Direction::Right) {}
Player::~Player() {}

bool Player::Initialize() {
	m_Sprites = new AnimationSprite*[8];

	int direction = 0;
	for (int i = 0; i < 8; i++) {
		m_Sprites[i] = AnimationSprite::Create(10);
		AddChild(m_Sprites[i]);

		for (int j = 0; j < 4; j++) {
			m_Sprites[i]->AddFrame(L"Resources\\Player\\player_" + std::to_wstring(direction + j) + L".png");
		}

		direction += 4;
	}

	m_AccelerationSpeed = 1.f;
	m_MaximizeSpeed = 5.f;

	return true;
}

void Player::Update(float deltaTime) {
	//Object::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState('W') == KeyState::Pressed) {
		if (m_CurrentSpeed < m_MaximizeSpeed) {
			m_CurrentSpeed += m_AccelerationSpeed;
		}
	} else if (Input::GetInstance()->GetKeyState('S') == KeyState::Pressed) {
		if (m_CurrentSpeed > -1 * m_MaximizeSpeed)
			m_CurrentSpeed -= m_AccelerationSpeed;
	}

	if (Input::GetInstance()->GetKeyState('A') == KeyState::Pressed) {
		m_Angle += -D3DXToRadian(1);
	} else if (Input::GetInstance()->GetKeyState('D') == KeyState::Pressed) {
		m_Angle += D3DXToRadian(1);
	}

	float degree = D3DXToDegree(m_Angle);
	degree = (degree < 0) ? degree + 360 : (degree > 360) ? degree - 360 : degree;

	// 우
	if (degree > (0 - 20) && degree < (0 + 20)) {
		m_Direction = Direction::Right;
	}
	// 우하단
	if (degree > (45 - 20) && degree < (45 + 20)) {
		m_Direction = Direction::RightBottom;
	}
	// 하단
	if (degree > (90 - 20) && degree < (90 + 20)) {
		m_Direction = Direction::Bottom;
	}
	// 좌하단
	if (degree > (135 - 20) && degree < (135 + 20)) {
		m_Direction = Direction::LeftBottom;
	}
	// 좌
	if (degree >(180 - 20) && degree < (180 + 20)) {
		m_Direction = Direction::Left;
	}
	// 좌상단
	if (degree >(225 - 20) && degree < (225 + 20)) {
		m_Direction = Direction::LeftTop;
	}
	// 상
	if (degree >(270 - 20) && degree < (270 + 20)) {
		m_Direction = Direction::Top;
	}
	// 우상단
	if (degree >(315 - 20) && degree < (315 + 20)) {
		m_Direction = Direction::RightTop;
	}

	if (m_CurrentSpeed > 0) {
		m_CurrentSpeed -= 0.7f;
	} else if (m_CurrentSpeed < 0) {
		m_CurrentSpeed += 1.0f;
	}

	auto movement = Vector2(cos(m_Angle) * m_CurrentSpeed, sin(m_Angle) * m_CurrentSpeed);
	Translate(movement);

	// Update Animation
	int direction = static_cast<int>(m_Direction);
	m_Sprites[direction]->Update(deltaTime);
}

void Player::Render() {
	Object::SortZOrder();
	Object::CalculateMatrix();

	if (m_Parent) {
		m_Matrix *= m_Parent->GetMatrix();
	}

	// Render Animation
	int direction = static_cast<int>(m_Direction);
	m_Sprites[direction]->Render();
}
