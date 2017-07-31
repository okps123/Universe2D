#include "Precompiled.h"
#include "Camera.h"
#include "Scene.h"

Camera::Camera()
	: m_TargetPosition(0.f, 0.f)
	, m_TargetScale(1.f, 1.f)
	, m_TargetRotation(0.f) {
}
Camera::~Camera() {
}

Camera* Camera::Create(Scene* scene) {
	auto camera = new (std::nothrow) Camera();
	if (camera && camera->InitializeWithScene(scene)) {
		return camera;
	}

	SAFE_DELETE(camera);
	return nullptr;
}

bool Camera::InitializeWithScene(Scene* scene) {
	Object::Initialize();
	m_Scene = scene;

	return true;
}

void Camera::Update(float deltaTime)
{
	Object::Update(deltaTime);

	Vector2 position = m_Scene->GetPosition();
	D3DXVec2Lerp(&position, &position, &m_TargetPosition, 0.2f);
	m_Scene->SetPosition(position);

	Vector2 scale = m_Scene->GetScale();
	D3DXVec2Lerp(&scale, &scale, &m_TargetScale, 0.2f);
	m_Scene->SetScale(scale);

	Vector2 rotation = Vector2(m_Scene->GetRotation(), 0.f);
	D3DXVec2Lerp(&rotation, &rotation, &D3DXVECTOR2(m_TargetRotation, 0.f), 0.2f);
	m_Scene->SetRotation(rotation.x);

}
void Camera::Render()
{
	Object::Render();
}

void Camera::Translate(float x, float y) {
	m_TargetPosition += Vector2(-x, -y);
}
void Camera::Scale(float sx, float sy) {
	m_TargetScale += Vector2(-sx, -sy);
}
void Camera::Rotate(float r) {
	m_TargetRotation += -r;
}

Vector2 Camera::ScreenToWorldPoint(Vector2 position) {
	position -= m_Scene->GetPosition();

	position.x *= 1 / m_Scene->GetScale().x;
	position.y *= 1 / m_Scene->GetScale().y;

	return position;
}

Vector2 Camera::WorldToScreenPoint(Vector2 position) {
	position += m_Scene->GetPosition();

	position.x *= m_Scene->GetScale().x;
	position.y *= m_Scene->GetScale().y;

	return position;
}
