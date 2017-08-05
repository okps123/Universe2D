#include "Precompiled.h"
#include "Collider.h"

#include "CircleCollider.h"
#include "BoxCollider.h"

Collider::Collider()
	: m_Offset(0.f, 0.f) {}
Collider::~Collider() {}

Collider* Collider::CreateCircle(float radius) {
	return CircleCollider::Create(radius);
}
Collider* Collider::CreateCircle(float radius, const Vector2& offset) {
	return CircleCollider::Create(radius, offset);
}