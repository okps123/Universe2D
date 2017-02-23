#include "Precompiled.h"
#include "Scene.h"

#include "Director.h"

Scene::Scene()
{
}
Scene::~Scene()
{
}

Scene* Scene::Create()
{
	auto scene = new (std::nothrow) Scene();
	if (scene && scene->Initialize())
	{
		scene->AutoRelease();
		return scene;
	}

	SAFE_DELETE(scene);
	return nullptr;
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
