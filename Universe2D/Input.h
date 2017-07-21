#pragma once

enum class KeyState
{
	None = 0,
    Down,
    Pressed,
    Up
};

enum MouseButton
{
	Left = VK_LBUTTON,
	Middle = VK_MBUTTON,
	Right = VK_RBUTTON
};

class Input : public Singleton<Input>
{
private:
    bool m_PrevKeyState[256];
    bool m_NowKeyState[256];

    Vector2 m_MousePosition;

public:
    Input();
    ~Input();

    void Update();

	void Clear();

public:
    KeyState GetKeyState(int key);
	KeyState GetMouseButtonState(MouseButton button);

	Vector2 GetMousePosition()
	{
		return m_MousePosition;
	}

private:
    void UpdateKeyState();
    void UpdateMouseState();
};

