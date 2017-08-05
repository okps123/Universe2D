#include "Precompiled.h"
#include "Object.h"

Object* Object::Create() {
	auto obj = new (std::nothrow) Object();
	if (obj && obj->Initialize()) {
		return obj;
	}

	SAFE_DELETE(obj);
	return nullptr;
}

Object::Object()
	: m_Parent(nullptr)
	, m_Position(.0f, .0f)
	, m_AnchorPoint(.0f, .0f)
	, m_AnchorPointInPoints(.0f, .0f)
	, m_Scale(1.f, 1.f)
	, m_Size(0.0f, 0.0f)
	, m_Rotation(0.f)
	, m_ZOrder(0)
	, m_Visible(true)
	, m_TransformUpdate(true)
	, m_Name("") {
	D3DXMatrixIdentity(&m_Matrix);
}
Object::~Object() {
	for each (auto child in m_Children)
		SAFE_DELETE(child);

	m_Children.clear();
}

bool Object::Initialize() {
	return true;
}

void Object::Update(float deltaTime) {
	if (!m_Visible)
		return;

	for each (const auto& child in m_Children)
		child->Update(deltaTime);
}
void Object::Render() {
	if (!m_Visible) {
		return;
	}
	
	SortZOrder();
	CalculateMatrix();

	if (m_Parent) {
		m_Matrix *= m_Parent->GetMatrix();
	}

	for each(const auto& child in m_Children) {
		child->Render();
	}
}


void Object::CalculateAnchorPointInPoint() {
	m_AnchorPointInPoints.x = m_Size.x * m_AnchorPoint.x;
	m_AnchorPointInPoints.y = m_Size.y * m_AnchorPoint.y;
}

void Object::CalculateMatrix() {
	D3DXMatrixTransformation2D(&m_Matrix, NULL, .0f, &m_Scale, NULL, m_Rotation, &m_Position);
}

void Object::AddChild(Object* child) {
	if (!child)
		return;

	child->SetParent(this);

	m_Children.push_back(child);
}
void Object::RemoveChild(Object* child) {
	if (m_Children.empty())
		return;

	auto iterator = std::find(std::begin(m_Children), std::end(m_Children), child);
	if (iterator != m_Children.end()) {
		SAFE_DELETE(child);

		m_Children.erase(iterator);
	}
}
