#pragma once
#include "Object.h"

class Scene : public virtual Object
{
public:
	Scene();
    virtual ~Scene() {};

public:
	virtual void Update(float deltaTime) override
	{
		Object::Update(deltaTime);
	};
	virtual void Render() override
	{
		Object::Render();
	};
};