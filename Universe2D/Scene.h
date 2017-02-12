#pragma once
#include "Object.h"

class Scene : public virtual Object
{
public:
    Scene() {};
    virtual ~Scene() {};

public:
    virtual void Render() override;
    virtual void Update(float deltaTime) override;
};

