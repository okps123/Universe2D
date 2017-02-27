#include "Precompiled.h"
#include "Collider.h"

#include "CircleCollider.h"
#include "BoxCollider.h"

Collider* Collider::CreateCircle(float radius, const Vector2& offset)
{
	return CircleCollider::Create(radius, offset);
}