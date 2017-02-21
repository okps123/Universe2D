#include "Precompiled.h"
#include "Input.h"

#include "Application.h"

Input::Input()
{
    ZeroMemory(m_PrevKeyState, sizeof(m_PrevKeyState));
    ZeroMemory(m_NowKeyState, sizeof(m_NowKeyState));
}
Input::~Input()
{
}

void Input::Update()
{
    // 윈도우가 활성화되있을때만 업데이트
    if (Application::GetInstance()->GetActived())
    {
        UpdateKeyState();
        UpdateMouseState();
    }
}

KeyState Input::GetKeyState(int key)
{
    bool prevState = m_PrevKeyState[key];
    bool nowState = m_NowKeyState[key];

    if (prevState == false && nowState == true)
    {
        return KEY_DOWN;
    }
    else if (prevState == true && nowState == true)
    {
        return KEY_PRESSED;
    }
    else if (prevState == true && nowState == false)
    {
        return KEY_UP;
    }

    return KEY_NOTPRESSED;
}

void Input::UpdateKeyState()
{
    for (int i = 0; i < 256; i++)
    {
        m_PrevKeyState[i] = m_NowKeyState[i];
        m_NowKeyState[i] = static_cast<bool>(::GetKeyState(i) & 0x8000);
    }
}
void Input::UpdateMouseState()
{
    // 마우스의 위치를 가져옴
    POINT position;
    GetCursorPos(&position);

    // 윈도우 위치로 변환
    ScreenToClient(Application::GetInstance()->GetHWND(), &position);

	m_MousePosition.x = static_cast<float>(position.x);
	m_MousePosition.y = static_cast<float>(position.y);
}
