#pragma once
class Application : public Singleton<Application>
{
private:
    HWND m_hWnd;
    HINSTANCE m_hInstance;

    wchar_t* m_Title;

    int m_Width;
    int m_Height;

public:
    Application();
    ~Application();

public:
    bool Initialize(wchar_t* title, int width, int height, bool fullScreen);
    bool Release();

    bool Run();

private:
    bool _CreateWindow(wchar_t* title, int width, int height, bool fullScreen);

private:
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
};