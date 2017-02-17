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
    SAFE_DELETE(m_CurrentScene);

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
        SAFE_DELETE(scene);
    }
    m_CurrentScene = scene;

    return true;
}
