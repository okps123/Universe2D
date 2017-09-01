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
	auto position = *(Vector3*)&m_Matrix._41; //GetParent()->GetPosition();
	return BoxCollider::IsCollide(position.x + m_Offset.x, position.y + m_Offset.y, m_Size.x, m_Size.y, point);
}




