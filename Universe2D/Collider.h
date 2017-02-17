#pragma once
#include "Object.h"

class BoxCollider;
class CircleCollider;
class Collider : public Object
{
public:
	Collider();
	~Collider();

public:
	virtual bool IsCollideWith(Collider* other) = 0;

public:
	virtual bool IsCollideWith(BoxCollider* other) = 0;
	virtual bool IsCollideWith(CircleCollider* other) = 0;

public:
	void OnCollisionEnter(Collider* collider) override
	{
		// 부모에게 충돌체 전달
		GetParent()->OnCollisionEnter(collider);
	};

	void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
	}
	void Render() override
	{
		Object::Render();
	}
};

