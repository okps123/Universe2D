#include "Precompiled.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT) {
	Application* app = Application::GetInstance();
	app->Initialize(L"Gamble", 1280, 720, false);

	//Director::GetInstance()->SetScene(IsoMapScene::Create());

	app->Run();
	app->Release();
}