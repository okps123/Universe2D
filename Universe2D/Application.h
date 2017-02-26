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

    bool m_Active;

private:
    int m_Fps;
    int m_ElapsedTime;
    int m_PrevTime;
    int m_NowTime;
    int m_FrameCount;

    int m_DeltaTime;

public:
    Application();
    ~Application();

public:
    bool Initialize(wchar_t* title, int width, int height, bool fullScreen);
    bool Release();

    bool Run();

public:
    bool GetActive() { return m_Active; }
	void SetActive(bool value) { m_Active = value; }

    int GetWidth() { return m_Width; }
    int GetHeight() { return m_Height; }

    HWND GetHWND() { return m_hWnd; }

    Renderer* GetRenderer() { return m_Renderer; }

private:
    bool _CreateWindow(wchar_t* title, int width, int height, bool fullScreen);

private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};