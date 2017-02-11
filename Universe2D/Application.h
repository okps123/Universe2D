#pragma once

class Renderer;
class Director;

class Application : public Singleton<Application>
{
private:
    HWND m_hWnd;
    HINSTANCE m_hInstance;

private:
    Renderer* m_Renderer;
    Director* m_Director;

private:
    wchar_t* m_Title;

    int m_Width;
    int m_Height;

private:
    int m_Fps = 0;
    int m_ElapsedTime = 0;
    int m_PrevTime;
    int m_NowTime;
    int m_FrameCount;

    float m_DeltaTime = 0;

public:
    Application();
    ~Application();

public:
    bool Initialize(wchar_t* title, int width, int height, bool fullScreen);
    bool Release();

    bool Run();

public:
    inline int GetWidth() { return m_Width; }
    inline int GetHeight() { return m_Height; }

    inline HWND GetHWND() { return m_hWnd; }

    inline Renderer* GetRenderer() { return m_Renderer; }

private:
    bool _CreateWindow(wchar_t* title, int width, int height, bool fullScreen);

private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};