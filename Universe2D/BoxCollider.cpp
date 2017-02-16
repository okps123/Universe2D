#include "Precompiled.h"
#include "BoxCollider.h"


BoxCollider::BoxCollider()
{
}
BoxCollider::~BoxCollider()
{
}

bool BoxCollider::IsCollideWith(Collider* other)
{
	return false;
}

bool BoxCollider::IsCollideWith(CircleCollider* other)
{
	return false;
}
bool BoxCollider::IsCollideWith(BoxCollider* other) 
{
	return false;
}