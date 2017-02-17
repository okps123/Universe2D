#pragma once

enum KeyState
{
    KEY_DOWN,
    KEY_PRESSED,
    KEY_UP,
    KEY_NOTPRESSED,
};

class Input : public Singleton<Input>
{
private:
    bool m_PrevKeyState[256];
    bool m_NowKeyState[256];

    D3DXVECTOR2 m_MousePosition;

public:
    Input();
    ~Input();

    void Update();

public:
    KeyState GetKeyState(int key);

private:
    void UpdateKeyState();
    void UpdateMouseState();
};

