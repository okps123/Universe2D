#pragma once
#include "Object.h"

class Frame : public Object
{
protected:
    float m_Width;
    float m_Height;

public:
    Frame();
    ~Frame();

public:
    float GetWidth() const { return m_Width; }
    void SetWidth(float width) { m_Width = width; }

    float GetHeight() const { return m_Height; }
    void SetHeight(float height) { m_Height = height; }

    void SetSize(float width, float height) { m_Width = width; m_Height = height; }

    virtual void Update(float deltaTime) {};
    virtual void Render() { Object::Render(); }
};

