#include "Precompiled.h"
#include "Player.h"

#include "Tile.h"

bool Player::Initialize() {
	MoveSpeed = 2.f;

	m_Sprite = Sprite::Create(L"Resources\\player.png");
	m_Sprite->SetAnchorPoint(0.5f, 0.5f);
	AddChild(m_Sprite);

	return true;
}

void Player::Update(float deltaTime) {
	Object::Update(deltaTime);

	UpdateMovement(deltaTime);
}

void Player::UpdateMovement(float deltaTime) {
	if (m_PathList.size() > 0) {
		if (m_TargetPathTile == nullptr) {
			m_TargetPathTile = m_PathList.at(m_PathIndex);
		}

		auto targetPosition = m_TargetPathTile->GetPosition();
		MoveTo(targetPosition);

		if (GetDistance(GetPosition(), m_TargetPathTile->GetPosition()) < 2) {
			++m_PathIndex;

			if (m_PathIndex < m_PathList.size()) {
				m_TargetPathTile = m_PathList.at(m_PathIndex);
			} else {
				m_PathList.clear();
				m_PathIndex = 0;

				m_TargetPathTile = nullptr;
			}
		}
	}
}

void Player::MoveTo(std::vector<Tile*>& pathList) {
	m_PathList = pathList;
	m_PathIndex = 0;
	
	m_TargetPathTile = nullptr;
}
void Player::MoveTo(const Vector2& position) {
	float dx = m_Position.x - position.x;
	float dy = m_Position.y - position.y;

	auto degree = D3DXToDegree(atan2f(dy, dx));

	m_Position.x -= cos(D3DXToRadian(degree)) * MoveSpeed;
	m_Position.y -= sin(D3DXToRadian(degree)) * MoveSpeed;
}
