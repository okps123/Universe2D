#include "Precompiled.h"

#include "SampleScene1.h"
#include "SampleScene2.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
    Application* app = Application::GetInstance();
    app->Initialize(L"Universe2D.Sample1", 1280, 720, false);

    Director::GetInstance()->SetScene(new SampleScene2());

    app->Run();
    app->Release();
}