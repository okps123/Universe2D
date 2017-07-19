#pragma once
#include "Object.h"

class Scene : public virtual Object
{
public:
	Scene();
    virtual ~Scene();

public:
	CREATE_FUNC(Scene);

public:
	virtual bool Initialize() override;

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
};