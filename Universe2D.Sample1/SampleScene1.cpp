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
}
void SampleScene1::Render()
{
    Scene::Render();
}
