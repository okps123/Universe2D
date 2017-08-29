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

private:
    Vector2 m_MousePosition;
	bool m_MouseHandled;

public:
    Input();
    ~Input();

    void Update();

	void Clear();

public:
    KeyState GetKeyState(int key);

public:
	KeyState GetMouseButtonState(MouseButton button);
	Vector2 GetMousePosition()
	{
		return m_MousePosition;
	}

	bool GetMouseHandled() {
		return m_MouseHandled;
	}
	void SetMouseHandled(bool handled) {
		m_MouseHandled = handled;
	}

private:
    void UpdateKeyState();
    void UpdateMouseState();
};

