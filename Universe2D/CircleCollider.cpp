#include "Precompiled.h"
#include "CircleCollider.h"

#include "Object.h"

CircleCollider::CircleCollider() : m_Radius(0.f) {}
CircleCollider::~CircleCollider() {}

CircleCollider* CircleCollider::Create(float radius) {
	return CircleCollider::Create(radius, Vector2(0.f, 0.f));
}

CircleCollider* CircleCollider::Create(float radius, const Vector2& offset) {
	auto collider = new (std::nothrow) CircleCollider();
	if (collider && collider->InitializeWithCircle(radius, offset)) {
		return collider;
	}

	SAFE_DELETE(collider);
	return nullptr;
}

bool CircleCollider::InitializeWithCircle(float radius, const Vector2& offset) {
	SetRadius(radius);
	SetOffset(offset);

	return true;
}

bool CircleCollider::IsCollideWith(Collider* other) {
	return other->IsCollideWith(this);
}
bool CircleCollider::IsCollideWith(const Vector2& point) {
	auto position = GetParent()->GetPosition();

	auto distance = sqrt(pow(position.x - point.x, 2) + pow(position.y - point.y, 2));
	if (distance > GetRadius())
		return false;

	return true;
}

bool CircleCollider::IsCollideWith(CircleCollider* other) {
	auto deltaPos = (GetParent()->GetPosition() + GetOffset()) - other->GetParent()->GetPosition();
	auto distance = sqrt(pow(deltaPos.x, 2) + pow(deltaPos.y, 2));

	if (distance > (GetRadius() + other->GetRadius()))
		return false;

	return true;
}
bool CircleCollider::IsCollideWith(BoxCollider* other) {
	return false;
}