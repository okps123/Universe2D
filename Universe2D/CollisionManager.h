#pragma once
#include "Object.h"

class CollisionManager : public Object, public Singleton<CollisionManager>
{
public:
	CollisionManager();
	~CollisionManager();
};
