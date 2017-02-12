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

public:
    Input();
    ~Input();

    void UpdateState();

public:
    KeyState GetKeyState(int key);

private:
    void UpdateKeyState();
    void UpdateMouseState();
};

