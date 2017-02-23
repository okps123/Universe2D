#include "Precompiled.h"
#include "Application.h"

#include "Input.h"
#include "Renderer.h"
#include "Director.h"
#include "Label.h"

#include "CollisionManager.h"
#include "Console.h"

#include "AutoReleasePool.h"

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

	CollisionManager::GetInstance()->Initialize();

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
            m_FrameCount++;
            m_NowTime = GetTickCount();

            m_DeltaTime = m_NowTime - m_PrevTime;
            m_ElapsedTime += m_DeltaTime;

            if (m_ElapsedTime > 1000)
            {
                m_Fps = m_FrameCount;
                m_ElapsedTime = 0;
                m_FrameCount = 0;
            }

			float deltaTime = static_cast<float>(m_DeltaTime) / 1000.0f;
			deltaTime = deltaTime > 1 ? 0 : deltaTime;

            // Update
            Input::GetInstance()->Update();

            Director::GetInstance()->Update(deltaTime);
			CollisionManager::GetInstance()->Update(deltaTime);

            // Render
            m_Renderer->Begin();
            m_Director->Render();
            m_Renderer->End();

			AutoReleasePool::GetInstance()->Clear();

            m_PrevTime = m_NowTime;
        }
    }
    return true;
}

LRESULT Application::WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    switch (Msg)
    {
    case WM_ACTIVATE:
        switch (LOWORD(wParam))
        {
        case WA_ACTIVE:
        case WA_CLICKACTIVE:
            Application::GetInstance()->m_Actived = true;
            break;
        case WA_INACTIVE:
            Application::GetInstance()->m_Actived = false;
            break;
        }

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
    int x = 0;
    int y = 0;

    if (fullScreen)
    {
        // 전체화면 모드일경우 스타일 수정
        style = WS_POPUP | WS_EX_TOPMOST;
    }
    else
    {
        // 윈도우 모드일경우 윈도우 보더를 계산한 크기로 수정함
        RECT rect;
        SetRect(&rect, 0, 0, width, height);

        AdjustWindowRect(&rect, style, false);

        x = y = CW_USEDEFAULT;

        width = (rect.right - rect.left);
        height = (rect.bottom - rect.top);
    }

    m_hWnd = CreateWindow(L"U2DWindow", title, style, x, y,
        width, height, NULL, NULL, wc.hInstance, NULL);

    ShowWindow(m_hWnd, SW_SHOWDEFAULT);

    return true;
}
