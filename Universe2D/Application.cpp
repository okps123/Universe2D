#include "Precompiled.h"
#include "Application.h"

#include "Input.h"
#include "Renderer.h"
#include "Director.h"

#include "Console.h"

Application::Application()
{
}
Application::~Application()
{
}

bool Application::Initialize(wchar_t* title, int width, int height, bool fullScreen)
{
#if _DEBUG
    Console::Initialize();
#endif

    m_Title = title;
    m_Width = width;
    m_Height = height;

    _CreateWindow(title, width, height, fullScreen);

    m_Renderer = new Renderer();
    m_Renderer->Initialize(m_hWnd, width, height, fullScreen);

    m_Director = Director::GetInstance();
    m_Director->Initialize();

    return true;
}

bool Application::Release()
{
    // 소멸자에서 자동으로 릴리즈
    SAFE_DELETE(m_Renderer);

    m_Director->Release();

#if _DEBUG
    Console::Release();
#endif

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
            Input::GetInstance()->Update();
            m_Director->UpdateScene(16.f);
            // 렌더
            m_Renderer->Begin();
            m_Director->RenderScene();
            m_Renderer->End();
        }
    }
    return true;
}

LRESULT Application::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_CREATE:
        break;
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
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    if (RegisterClass(&wc) == NULL)
        return false;

    DWORD style = WS_OVERLAPPEDWINDOW;
    int x = CW_USEDEFAULT;
    int y = CW_USEDEFAULT;

    // 윈도우 모드일경우 윈도우 보더를 계산한 크기로 수정함
    if (fullScreen)
    {
        style = WS_POPUP | WS_EX_TOPMOST;
        x = 0;
        y = 0;
    }
    else
    {
        RECT rect;
        SetRect(&rect, 0, 0, width, height);

        AdjustWindowRect(&rect, style, false);

        width = (rect.right - rect.left);
        height = (rect.bottom - rect.top);
    }

    m_hWnd = CreateWindow(L"U2DWindow", title, style, x, y,
        width, height, NULL, NULL, wc.hInstance, NULL);
    
    ShowWindow(m_hWnd, SW_SHOWDEFAULT);

    return true;
}
