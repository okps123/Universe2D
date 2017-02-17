#pragma once
#include "Object.h"

class Collision;
class CollisionObject : public Object
{
public:
	CollisionObject();
	~CollisionObject();

	virtual void OnCollisionEnter(Collision* collision) = 0;

public:
	virtual void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
	}
	virtual void Render() override
	{
		Object::Render();
	}
};

