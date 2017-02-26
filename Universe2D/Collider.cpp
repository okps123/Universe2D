#include "Precompiled.h"
#include "Collider.h"

#include "CircleCollider.h"
#include "BoxCollider.h"

Collider::Collider()
{
}
Collider::~Collider()
{
}

bool Collider::Initialize()
{
	//CollisionManager::GetInstance()->AddChild(this);

	return true;
}

Collider* Collider::CreateCircle(float radius, const Vector2& offset)
{
	auto collider = CircleCollider::Create(radius, offset);
	if (collider)
	{
		return collider;
	}

	return nullptr;
}

