#include "Precompiled.h"
#include "SampleScene2.h"

#include "SampleScene1.h"


SampleScene2::SampleScene2()
{
}

SampleScene2::~SampleScene2()
{
}

Scene* SampleScene2::Create()
{
	auto scene = new (std::nothrow) SampleScene2();
	if (scene && scene->Initialize())
	{
		return scene;
	}

	return nullptr;
}

bool SampleScene2::Initialize()
{
	return true;
}

void SampleScene2::Update(float deltaTime)
{
	Scene::Update(deltaTime);
	
	if (Input::GetInstance()->GetKeyState('1') == KeyState::KEY_PRESSED)
	{
		Director::GetInstance()->SetScene(SampleScene1::Create());
	}
}

void SampleScene2::Render()
{
	Scene::Render();
}
