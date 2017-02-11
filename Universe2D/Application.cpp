#include "Precompiled.h"
#include "Application.h"

#include "Renderer.h"
#include "Director.h"

Application::Application()
{
}
Application::~Application()
{
}

bool Application::Initialize(wchar_t* title, int width, int height, bool fullScreen)
{
    m_Title = title;
    m_Width = width;
    m_Height = height;

    _CreateWindow(title, width, height, fullScreen);

    m_Renderer = new Renderer();
    m_Renderer->Initialize(width, height, fullScreen);

    m_Director = Director::GetInstance();
    m_Director->Initialize();

    return true;
}

bool Application::Release()
{
    // 소멸자에서 자동으로 릴리즈
    SAFE_DELETE(m_Renderer);

    m_Director->Release();

    return true;
}

bool Application::Run()
{
    MSG msg = {};
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            // 업데이트
            // 렌더
        }
    }
    return true;
}

LRESULT Application::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_DESTROY:
    {
        Application::GetInstance()->Release();
        PostQuitMessage(0);
        break;
    }
    }

    return DefWindowProc(hWnd, Msg, wParam, lParam);
}

bool Application::_CreateWindow(wchar_t* title, int width, int height, bool fullScreen)
{
    WNDCLASS wc = {};
    wc.lpszClassName = L"U2DWindow";
    wc.lpfnWndProc = WndProc;

    if (RegisterClass(&wc) == NULL)
        return false;

    DWORD style = WS_OVERLAPPEDWINDOW;

    m_hWnd = CreateWindow(L"U2DWindow", title, style, CW_USEDEFAULT, CW_USEDEFAULT,
        width, height, NULL, NULL, wc.hInstance, NULL);

    if (fullScreen)
    {
        SetWindowLong(m_hWnd, GWL_STYLE, 0);
        ShowWindow(m_hWnd, SW_SHOWMAXIMIZED);
    }
    else
    {
        ShowWindow(m_hWnd, SW_SHOWDEFAULT);
    }

    return true;
}
