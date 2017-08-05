#pragma once
#include "Object.h"

class BoxCollider;
class CircleCollider;

class Collider : public Object
{
protected:
	Vector2 m_Offset;

public:
	Collider();
	~Collider();

	static Collider* CreateCircle(float radius);
	static Collider* CreateCircle(float radius, const Vector2& offset);

public:
	virtual bool IsCollideWith(Collider* other) = 0;

	virtual bool IsCollideWith(BoxCollider* other) = 0;
	virtual bool IsCollideWith(CircleCollider* other) = 0;

	virtual bool IsCollideWith(const Vector2& point) = 0;

public:
	const Vector2& GetOffset() const {
		return m_Offset;
	}
	void SetOffset(const Vector2& offset) {
		m_Offset = offset;
	}

public:
	virtual void OnCollision(Collider* collider) override {
		GetParent()->OnCollision(collider);
	};
};

