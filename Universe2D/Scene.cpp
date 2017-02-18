#include "Precompiled.h"
#include "Scene.h"
#include "Application.h"

Scene::Scene()
{
	// 화면 크기 설정
	SetSize({
		static_cast<float>(Application::GetInstance()->GetWidth()),
		static_cast<float>(Application::GetInstance()->GetHeight())
	});
}