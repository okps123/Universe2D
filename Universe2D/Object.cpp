#include "Precompiled.h"
#include "Object.h"

Object::Object()
    : m_Parent(nullptr),
    m_Position(.0f, .0f), m_Center(.0f, .0f),
    m_Scale(1.f, 1.f), m_Rotation(0.f), m_Visible(true)
{
}
Object::~Object()
{
    for (auto childObject : m_ChildList)
    {
        SAFE_DELETE(childObject);
    }
    m_ChildList.clear();
}

void Object::Update(float deltaTime)
{
    if (!m_Visible) return;

    for (const auto& childObject : m_ChildList)
    {
        childObject->Update(deltaTime);
    }
}
void Object::Render()
{
    if (!m_Visible) return;

    D3DXMatrixTransformation2D(&m_Matrix, &m_Center, .0f, &m_Scale, &m_Center, m_Rotation, &m_Position);

    if (m_Parent)
    {
        m_Matrix *= m_Parent->GetMatrix();
    }

    for (const auto& childObject : m_ChildList)
    {
        childObject->Render();
    }
}

void Object::AddChild(Object* obj)
{
    obj->SetParent(this);
    m_ChildList.push_back(obj);
}
void Object::RemoveChild(Object* obj, bool deleteMemory)
{
    auto iterator = std::find(m_ChildList.begin(), m_ChildList.end(), obj);
    if (iterator != m_ChildList.end())
    {
        if (deleteMemory)
            SAFE_DELETE(*iterator);

        m_ChildList.erase(iterator);
    }
}
