#pragma once
#include "Collider.h"

class CircleCollider;
class BoxCollider : public Collider
{
public:
	BoxCollider();
	~BoxCollider();

public:
	static BoxCollider* Create(float width, float height) {
		auto p = new (std::nothrow) BoxCollider();
		if (p) {
			p->SetSize(width, height);
			return p;
		}

		SAFE_DELETE(p);
		return nullptr;
	}

public:
	bool IsCollideWith(Collider* other) override;
	bool IsCollideWith(const Vector2& point) override;

private:
	virtual bool IsCollideWith(CircleCollider* other) override;
	virtual bool IsCollideWith(BoxCollider* other) override;

public:
	static bool IsCollide(float x, float y, float width, float height, const Vector2& p) {
		if (p.x < x || p.y < y)
			return false;

		if (p.x > x + width || p.y > y + height)
			return false;

		return true;
	}
};

