#include "Precompiled.h"
#include "CollisionManager.h"

#include "Collider.h"

CollisionManager::CollisionManager()
{
}
CollisionManager::~CollisionManager()
{
	Initialize();
}

bool CollisionManager::Initialize()
{
	for (auto collider : m_ColliderList)
	{
		SAFE_DELETE(collider);
	}
	m_ColliderList.clear();

	return true;
}

void CollisionManager::AddCollider(Collider* collider)
{
	m_ColliderList.push_back(collider);
}
void CollisionManager::RemoveCollider(Collider* collider)
{
	auto iterator = std::find(m_ColliderList.begin(), m_ColliderList.end(), collider);
	if (iterator != m_ColliderList.end())
	{
		SAFE_DELETE(*iterator);
		m_ColliderList.erase(iterator);
	}
}

void CollisionManager::Update(float deltaTime)
{
	for (auto colliderA : m_ColliderList)
	{
		if (!colliderA->GetParent()->GetVisible())
			continue;

		for (auto colliderB : m_ColliderList)
		{
			if (colliderA == colliderB)
				continue;

			if (!colliderB->GetParent()->GetVisible())
				continue;

			if (colliderA->IsCollideWith(colliderB) == true)
			{
				colliderB->OnCollision(colliderA);
				colliderA->OnCollision(colliderB);
			}
		}
	}
}