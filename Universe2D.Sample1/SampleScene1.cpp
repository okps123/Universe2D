#include "Precompiled.h"
#include "SampleScene1.h"
#include "Frame.h"

SampleScene1::SampleScene1()
{
    m_Sprite1 = Sprite::Create(L"C:\\Users\\Raye\\Pictures\\인체\\60791751_p0.jpg");

    m_Sprite2 = Sprite::Create(L"C:\\Users\\Raye\\Pictures\\인체\\앞으로 숙임.jpg");
    m_Sprite2->Resize(100, 100);

    AddChild(m_Sprite1);
    AddChild(m_Sprite2);
}
SampleScene1::~SampleScene1()
{
}

void SampleScene1::Update(float deltaTime)
{
    // 이동
    if (Input::GetInstance()->GetKeyState('A') == KeyState::KEY_PRESSED)
    {
        this->Transform(-5, 0);
    }
    else if (Input::GetInstance()->GetKeyState('D') == KeyState::KEY_PRESSED)
    {
        this->Transform(5, 0);
    }
    if (Input::GetInstance()->GetKeyState('W') == KeyState::KEY_PRESSED)
    {
        this->Transform(0, -5);
    }
    else if (Input::GetInstance()->GetKeyState('S') == KeyState::KEY_PRESSED)
    {
        this->Transform(0, 5);
    }

    // 확대 축소
    if (Input::GetInstance()->GetKeyState('R') == KeyState::KEY_PRESSED)
    {
        this->SetScale(GetScale() + D3DXVECTOR2(0.05f, 0.05f));
    }
    else if (Input::GetInstance()->GetKeyState('T') == KeyState::KEY_PRESSED)
    {
        this->SetScale(GetScale() - D3DXVECTOR2(0.05f, 0.05f));
    }

    // 회전
    if (Input::GetInstance()->GetKeyState('Q') == KeyState::KEY_PRESSED)
    {
        this->SetRotation(GetRotation() + 0.05f);
    }
    else if (Input::GetInstance()->GetKeyState('E') == KeyState::KEY_PRESSED)
    {
        this->SetRotation(GetRotation() - 0.05f);
    }
}
void SampleScene1::Render()
{
    Scene::Render();
}
