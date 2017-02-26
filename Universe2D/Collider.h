#pragma once
#include "Object.h"

class BoxCollider;
class CircleCollider;

class Collider : public Object
{
public:
	Collider();
	~Collider();

	static Collider* CreateCircle(float radius, const Vector2& offset);
	// Box Create 구현해야함

public:
	bool Initialize() override;

public:
	virtual bool IsCollideWith(Collider* other) = 0;

	virtual bool IsCollideWith(BoxCollider* other) = 0;
	virtual bool IsCollideWith(CircleCollider* other) = 0;

public:
	void OnCollision(Collider* collider) override
	{
		this->GetParent()->OnCollision(collider);
	};
};

