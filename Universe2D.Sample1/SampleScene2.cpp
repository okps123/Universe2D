#include "Precompiled.h"
#include "SampleScene2.h"

SampleScene2::SampleScene2()
{
	Background = Sprite::Create(L"C:\\Users\\ASIS\\Desktop\\165309-w.jpg");
	Background->Resize(1280, 720);
	Background->SetPosition(D3DXVECTOR2(640, 360));

	AnimationSprite* Player = new AnimationSprite(5, 4);
	Player->AddFrame(0, L"C:\\Users\\ASIS\\Downloads\\Pixel-master\\Pixel\\Resources\\Sprite\\Player\\Run\\5.png");
	Player->AddFrame(1, L"C:\\Users\\ASIS\\Downloads\\Pixel-master\\Pixel\\Resources\\Sprite\\Player\\Run\\6.png");
	Player->AddFrame(2, L"C:\\Users\\ASIS\\Downloads\\Pixel-master\\Pixel\\Resources\\Sprite\\Player\\Run\\7.png");
	Player->AddFrame(3, L"C:\\Users\\ASIS\\Downloads\\Pixel-master\\Pixel\\Resources\\Sprite\\Player\\Run\\8.png");
	Player->AddFrame(4, L"C:\\Users\\ASIS\\Downloads\\Pixel-master\\Pixel\\Resources\\Sprite\\Player\\Run\\9.png");
	Player->SetUpdate(true);

	AddChild(Background);
	AddChild(Player);
}
SampleScene2::~SampleScene2()
{
}

void SampleScene2::Update(float deltaTime)
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
void SampleScene2::Render()
{
	Scene::Render();
}
