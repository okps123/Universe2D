#include "Precompiled.h"
#include "Director.h"

#include "Application.h"
#include "Renderer.h"
#include "Scene.h"

Director::Director() : m_CurrentScene(nullptr)
{
}
Director::~Director()
{
    Release();
}

bool Director::Initialize()
{
    return true;
}
bool Director::Release()
{
    return true;
}

bool Director::Update(float deltaTime)
{
    if (m_CurrentScene == nullptr)
        return false;

    m_CurrentScene->Update(deltaTime);

    return true;
}
bool Director::Render()
{
    if (m_CurrentScene == nullptr)
        return false;

    m_CurrentScene->Render();

    return true;
}

bool Director::SetScene(Scene* scene)
{
    if (m_CurrentScene)
    {
		m_CurrentScene->Retain();
    }
    m_CurrentScene = scene;
	m_CurrentScene->Retain();

    return true;
}

Vector2 Director::GetWindowSize()
{
	return Vector2(
		static_cast<float>(Application::GetInstance()->GetWidth()),
		static_cast<float>(Application::GetInstance()->GetHeight()));
}
