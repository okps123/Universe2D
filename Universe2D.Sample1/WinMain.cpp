#include "Precompiled.h"

#include "SampleScene3.h"
#include "ItemCreateScene.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
    Application* app = Application::GetInstance();
    app->Initialize(L"Universe2D.Sample1", 1280, 720, false);

    Director::GetInstance()->SetScene(ItemCreateScene::Create());

    app->Run();
    app->Release();
}