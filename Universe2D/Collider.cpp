#include "Precompiled.h"
#include "Collider.h"

#include "CollisionManager.h"

Collider::Collider()
{
	CollisionManager::GetInstance()->AddCollider(this);
}

Collider::~Collider()
{
	CollisionManager::GetInstance()->RemoveCollider(this);
}
