#pragma once
#include "Collider.h"

class CircleCollider;
class BoxCollider : public Collider
{
public:
	BoxCollider();
	~BoxCollider();

public:
	bool IsCollideWith(Collider* other);

private:
	bool IsCollideWith(CircleCollider* other);
	bool IsCollideWith(BoxCollider* other);
};

