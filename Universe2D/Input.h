#pragma once

enum KeyState
{
    KEY_DOWN,
    KEY_PRESSED,
    KEY_UP,
    KEY_NOTPRESSED = 0
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

	void Clear();

public:
    KeyState GetKeyState(int key);

	KeyState GetMouseLeftButtonState()
	{
		return GetKeyState(VK_LBUTTON);
	}
	KeyState GetMouseRightButtonState()
	{
		return GetKeyState(VK_RBUTTON);
	}

private:
    void UpdateKeyState();
    void UpdateMouseState();
};

