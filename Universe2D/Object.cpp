#include "Precompiled.h"
#include "Object.h"

Object::Object()
	: m_Parent(nullptr), m_Position(.0f, .0f), m_Center(.0f, .0f),
	m_Scale(1.f, 1.f), m_Rotation(0.f), m_Visible(true)
{
}
Object::~Object()
{
	for (auto childObject : m_ChildList)
		SAFE_DELETE(childObject);

	m_ChildList.clear();
}

void Object::Update(float deltaTime)
{
	if (!m_Visible)
		return;

	for (const auto& childObject : m_ChildList)
		childObject->Update(deltaTime);
}
void Object::Render()
{
	if (!m_Visible)
		return;

	D3DXMatrixTransformation2D(&m_Matrix, &m_Center, .0f, &m_Scale, &m_Center, m_Rotation, &m_Position);

	if (m_Parent)
		m_Matrix *= m_Parent->GetMatrix();

	for (const auto& childObject : m_ChildList)
		childObject->Render();
}

void Object::Translate(float x, float y)
{
	m_Position.x += x;
	m_Position.y += y;
}
void Object::Translate(Vector2 vector)
{
	m_Position += vector;
}

void Object::AddChild(Object* obj)
{
	if (obj)
	{
		obj->SetParent(this);
		m_ChildList.push_back(obj);
	}
}
void Object::RemoveChild(Object* obj, bool deleteMemory)
{
	auto iterator = std::find(std::begin(m_ChildList), std::end(m_ChildList), obj);
	if (iterator != m_ChildList.end())
	{
		if (deleteMemory)
		{
			SAFE_DELETE(obj);
		}

		m_ChildList.erase(iterator);
	}
}
