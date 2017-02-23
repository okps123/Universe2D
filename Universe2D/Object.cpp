#include "Precompiled.h"
#include "Object.h"

#include "AutoReleasePool.h"

Object* Object::Create()
{
	auto obj = new (std::nothrow) Object();
	if (obj && obj->Initialize())
	{
		obj->AutoRelease();
	}
	else
	{
		SAFE_DELETE(obj);
	}

	return obj;

}

Object::Object()
	: m_Parent(nullptr), m_Position(.0f, .0f), m_Center(.0f, .0f),
	m_Scale(1.f, 1.f), m_Rotation(0.f), m_Visible(true), m_Managed(false), m_ReferenceCount(1)
{
}
Object::~Object()
{
	for each (const auto& child in m_Children)
	{
		child->SetParent(nullptr);
		child->Release();
	}
	m_Children.clear();
}

bool Object::Initialize()
{
	return true;
}

void Object::Retain()
{
	printf("[Object] Called Retain() RefCount: %d\n", m_ReferenceCount);

	++m_ReferenceCount;
}
void Object::Release()
{
	printf("[Object] Called Release() RefCount: %d\n", m_ReferenceCount);

	--m_ReferenceCount;

	if (m_ReferenceCount == 0)
	{
		delete this;
	}
}

void Object::AutoRelease()
{
	AutoReleasePool::GetInstance()->AddObject(this);
	m_Managed = true;
}

void Object::Update(float deltaTime)
{
	if (!m_Visible)
		return;

	for each (const auto& child in m_Children)
		child->Update(deltaTime);
}
void Object::Render()
{
	if (!m_Visible)
		return;

	D3DXMatrixTransformation2D(&m_Matrix, &m_Center, .0f, &m_Scale, &m_Center, m_Rotation, &m_Position);

	if (m_Parent)
		m_Matrix *= m_Parent->GetMatrix();

	for each(const auto& child in m_Children)
		child->Render();
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

void Object::AddChild(Object* child)
{
	child->SetParent(this);
	child->Retain();

	m_Children.push_back(child);
}
void Object::RemoveChild(Object* child)
{
	if (m_Children.empty())
		return;

	auto iterator = std::find(std::begin(m_Children), std::end(m_Children), child);
	if (iterator != m_Children.end())
	{
		child->SetParent(nullptr);
		child->Release();

		m_Children.erase(iterator);
	}
}
