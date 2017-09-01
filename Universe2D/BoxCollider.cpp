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
	Vector3 position = *(Vector3*)&m_Matrix._41;
	return BoxCollider::IsCollide(position.x, position.y, m_Size.x, m_Size.y, point);
}
