#include "Precompiled.h"
#include "SampleScene1.h"

#include "CircleCollider.h"

SampleScene1::SampleScene1()
{
	auto sprite1 = new AnimationSprite(15);
	sprite1->AddFrame(L"Resources\\Player_0.png");
	sprite1->AddFrame(L"Resources\\Player_1.png");

	circle1 = Sprite::Create(L"Resources\\circle_100px.png");
	circle1->AddChild(new CircleCollider(50.f));

	circle2 = Sprite::Create(L"Resources\\circle_100px.png");
	collider2 = new CircleCollider(50.f);
	circle2->AddChild(collider2);
	circle2->Transform(500, 500);

	AddChild(circle1);
	AddChild(circle2);
}
SampleScene1::~SampleScene1()
{
}

void SampleScene1::Update(float deltaTime)
{
	Scene::Update(deltaTime);

    // 이동
    if (Input::GetInstance()->GetKeyState('A') == KeyState::KEY_PRESSED)
    {
		circle1->Transform(-5, 0);
    }
    else if (Input::GetInstance()->GetKeyState('D') == KeyState::KEY_PRESSED)
    {
		circle1->Transform(5, 0);
    }
    if (Input::GetInstance()->GetKeyState('W') == KeyState::KEY_PRESSED)
    {
		circle1->Transform(0, -5);
    }
    else if (Input::GetInstance()->GetKeyState('S') == KeyState::KEY_PRESSED)
    {
		circle1->Transform(0, 5);
    }

    // 확대 축소
    if (Input::GetInstance()->GetKeyState('R') == KeyState::KEY_PRESSED)
    {
        this->SetScale(GetScale() + D3DXVECTOR2(0.05f, 0.05f));
		circle2->RemoveChild(collider2, false);
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
