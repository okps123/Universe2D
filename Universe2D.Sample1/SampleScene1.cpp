#include "Precompiled.h"
#include "SampleScene1.h"

#include "CircleCollider.h"

SampleScene1::SampleScene1()
{
	circle1 = Sprite::Create(L"Resources\\test.jpg");
	//circle1->SetCenter({ 0,0 });

	// 중심점으로 사용(회전, 확대)되는 중심점과 이미지의 중심을 구분해야할듯함
	// 구분이 되있지않아 회전에 중간점에서 이미지 중심크기만큼 더한 위치(오른쪽 하단)에서 처리가 이루어짐

	AddChild(circle1);
}
SampleScene1::~SampleScene1()
{
}

void SampleScene1::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState('F') == KeyState::KEY_PRESSED)
	{
		RemoveChild(circle1);
	}

    // 이동
	if (Input::GetInstance()->GetKeyState('A') == KeyState::KEY_PRESSED)
    {
		circle1->Translate(-5, 0);
    }
    else if (Input::GetInstance()->GetKeyState('D') == KeyState::KEY_PRESSED)
    {
		circle1->Translate(5, 0);
    }
    if (Input::GetInstance()->GetKeyState('W') == KeyState::KEY_PRESSED)
    {
		circle1->Translate(0, -5);
    }
    else if (Input::GetInstance()->GetKeyState('S') == KeyState::KEY_PRESSED)
    {
		circle1->Translate(0, 5);
    }

    // 확대 축소
    if (Input::GetInstance()->GetKeyState('R') == KeyState::KEY_PRESSED)
    {
		circle1->SetScale(circle1->GetScale() + D3DXVECTOR2(0.01f, 0.01f));
    }
    else if (Input::GetInstance()->GetKeyState('T') == KeyState::KEY_PRESSED)
    {
		circle1->SetScale(circle1->GetScale() - D3DXVECTOR2(0.01f, 0.01f));
    }

    // 회전
    if (Input::GetInstance()->GetKeyState('Q') == KeyState::KEY_PRESSED)
    {
		circle1->SetRotation(circle1->GetRotation() + 0.05f);
    }
    else if (Input::GetInstance()->GetKeyState('E') == KeyState::KEY_PRESSED)
    {
		circle1->SetRotation(circle1->GetRotation() - 0.05f);
    }
}
void SampleScene1::Render()
{
    Scene::Render();
}
