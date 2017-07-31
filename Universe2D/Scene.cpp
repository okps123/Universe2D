#include "Precompiled.h"
#include "Scene.h"

Scene::Scene() : m_Camera(nullptr) {
}
Scene::~Scene() {
}

bool Scene::Initialize() {
	SetSize(Director::GetInstance()->GetWindowSize());
	SetCamera(Camera::Create(this));
	return true;
}

void Scene::Update(float deltaTime) {
	Object::Update(deltaTime);
}
void Scene::Render() {
	Object::Render();
}