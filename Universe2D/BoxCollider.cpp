#include "Precompiled.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider() {}
BoxCollider::~BoxCollider() {}

bool BoxCollider::IsCollideWith(Collider* other) {
	return other->IsCollideWith(this);
}

bool BoxCollider::IsCollideWith(CircleCollider* other) {
	return false;
}
bool BoxCollider::IsCollideWith(BoxCollider* other) {
	return false;
}

bool BoxCollider::IsCollideWith(const Vector2& point) {
	if (point.x < m_Position.x || point.y < m_Position.y)
		return false;

	if (point.x > m_Position.x + m_Size.x || point.y > m_Position.y + m_Size.y)
		return false;

	return true;
}
