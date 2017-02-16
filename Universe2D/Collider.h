#pragma once
#include "Object.h"

class BoxCollider;
class CircleCollider;
class Collider : public Object
{
public:
	Collider() {};
	~Collider() {};

public:
	virtual bool IsCollideWith(Collider* other) = 0;

	virtual bool IsCollideWith(BoxCollider* other) = 0;
	virtual bool IsCollideWith(CircleCollider* other) = 0;

public:
	void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
	}
	void Render() override
	{
		Object::Render();
	}
};

