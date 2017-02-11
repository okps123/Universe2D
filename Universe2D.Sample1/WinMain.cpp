#include "Precompiled.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
    Application* app = Application::GetInstance();
    app->Initialize(L"Universe2D.Sample1", 800, 600, false);

    Director::GetInstance();

    app->Run();
    app->Release();
}