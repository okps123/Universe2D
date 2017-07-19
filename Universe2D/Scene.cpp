#include "Precompiled.h"
#include "Scene.h"

Scene::Scene()
{
}
Scene::~Scene()
{
}

bool Scene::Initialize()
{
	SetSize(Director::GetInstance()->GetWindowSize());

	return true;
}

void Scene::Update(float deltaTime)
{
	Object::Update(deltaTime);
}
void Scene::Render()
{
	Object::Render();
}
