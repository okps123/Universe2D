#pragma once
#include "Collider.h"

class BoxCollider;
class CircleCollider : public Collider
{
private:
	float m_Radius;

public:
	CircleCollider();
	~CircleCollider();

	static CircleCollider* Create(float radius, const Vector2& offset);

public:
	bool InitializeWithCircle(float radius, const Vector2& offset);

public:
	float GetRadius() { return m_Radius; }

public:
	bool IsCollideWith(Collider* other);

private:
	bool IsCollideWith(CircleCollider* other);
	bool IsCollideWith(BoxCollider* other);

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