#include "Precompiled.h"
#include "SampleScene1.h"

#include "CircleCollider.h"

SampleScene1::SampleScene1()
{
	m_Circle1 = Sprite::Create(L"Resources\\test.jpg");

	AddChild(m_Circle1);
}
SampleScene1::~SampleScene1()
{
}

void SampleScene1::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState('F') == KeyState::KEY_PRESSED)
	{
		RemoveChild(m_Circle1);
	}

    // 이동
	if (Input::GetInstance()->GetKeyState('A') == KeyState::KEY_PRESSED)
    {
		m_Circle1->Translate(-5, 0);
    }
    else if (Input::GetInstance()->GetKeyState('D') == KeyState::KEY_PRESSED)
    {
		m_Circle1->Translate(5, 0);
    }
    if (Input::GetInstance()->GetKeyState('W') == KeyState::KEY_PRESSED)
    {
		m_Circle1->Translate(0, -5);
    }
    else if (Input::GetInstance()->GetKeyState('S') == KeyState::KEY_PRESSED)
    {
		m_Circle1->Translate(0, 5);
    }

    // 확대 축소
    if (Input::GetInstance()->GetKeyState('R') == KeyState::KEY_PRESSED)
    {
		m_Circle1->TranslateScale(0.01f, 0.01f);
    }
    else if (Input::GetInstance()->GetKeyState('T') == KeyState::KEY_PRESSED)
    {
		m_Circle1->TranslateScale(-0.01f, -0.01f);
    }

    // 회전
    if (Input::GetInstance()->GetKeyState('Q') == KeyState::KEY_PRESSED)
    {
		m_Circle1->TranslateRotate(0.05f);
    }
    else if (Input::GetInstance()->GetKeyState('E') == KeyState::KEY_PRESSED)
    {
		m_Circle1->TranslateRotate(-0.05f);
    }
}
void SampleScene1::Render()
{
    Scene::Render();
}
