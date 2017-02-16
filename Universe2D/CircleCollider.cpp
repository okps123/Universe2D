#include "Precompiled.h"
#include "CircleCollider.h"
#include "Object.h"

CircleCollider::CircleCollider(float radius) : m_Radius(0.f)
{
	m_Radius = radius;
}
CircleCollider::~CircleCollider()
{
}

bool CircleCollider::IsCollideWith(Collider* other)
{
	return other->IsCollideWith(this);
}

bool CircleCollider::IsCollideWith(CircleCollider* other)
{
	auto delta = GetParent()->GetPosition() - other->GetParent()->GetPosition();
	auto distance = sqrt(pow(delta.x, 2) + pow(delta.y, 2));

	printf("°Å¸® %f\n", distance);

	if (distance > (GetRadius() + other->GetRadius()))
		return false;

	return true;
}
bool CircleCollider::IsCollideWith(BoxCollider* other)
{
	return false;
}