#include "Precompiled.h"
#include "Camera.h"
#include "Scene.h"

Camera::Camera() {
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

void Camera::Translate(float x, float y) {
	m_Scene->Translate(-x, -y);
}
void Camera::Scale(float sx, float sy) {
	m_Scene->Scale(-sx, -sy);
}
void Camera::Rotate(float r) {
	m_Scene->Rotate(-r);
}

Vector2 Camera::ScreenToWorldPoint(Vector2 position) {
	position -= m_Scene->GetPosition();
	return position;
}

Vector2 Camera::WorldToScreenPoint(Vector2 position) {
	return Vector2();
}
