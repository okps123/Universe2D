#include "Precompiled.h"
#include "Console.h"

#include "StageScene1.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
	Console::Initialize();

	Application* app = Application::GetInstance();
	app->Initialize(L"Gamble", 1280, 720, false);

	Director::GetInstance()->SetScene(StageScene1::Create());

	app->Run();
	app->Release();

	Console::Release();
}