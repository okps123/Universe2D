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

	static CircleCollider* Create(float radius);
	static CircleCollider* Create(float radius, const Vector2& offset);

public:
	bool InitializeWithCircle(float radius, const Vector2& offset);

public:
	float GetRadius() const { return m_Radius; }
	void SetRadius(float radius) { m_Radius = radius; }

public:
	bool IsCollideWith(Collider* other) override;
	bool IsCollideWith(const Vector2& point) override;

private:
	bool IsCollideWith(CircleCollider* other) override;
	bool IsCollideWith(BoxCollider* other) override;

};