#pragma once
#include "Collider.h"

class CircleCollider;
class BoxCollider : public Collider
{
public:
	BoxCollider();
	~BoxCollider();

public:
	bool IsCollideWith(Collider* other) override;
	bool IsCollideWith(const Vector2& point) override;

private:
	virtual bool IsCollideWith(CircleCollider* other) override;
	virtual bool IsCollideWith(BoxCollider* other) override;

};

