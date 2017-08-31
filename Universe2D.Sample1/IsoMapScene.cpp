#include "Precompiled.h"
#include "IsoMapScene.h"

#include "Tile.h"
#include "Map.h"

#include "Player.h"

IsoMapScene::IsoMapScene() {
}
IsoMapScene::~IsoMapScene() {
}

bool IsoMapScene::Initialize() {
	Scene::Initialize();

	// UI 설정
	m_UI = Object::Create();
	m_UI->SetZOrder(1000);
	AddChild(m_UI);
	m_UI->SetParent(nullptr);

	auto p = ProgressBar::Create(L"Resources\\ui_water_background.png", L"Resources\\ui_water_foreground.png");
	p->SetPosition(10, 10);
	p->SetValue(50);

	auto p_label = Sprite::Create(L"Resources\\ui_water_label.png");
	p_label->SetAnchorPoint(0.f, 0.f);
	p_label->SetPosition(10, 6);
	p->AddChild(p_label);

	m_UI->AddChild(p);

	m_Map = Map::Create(64, 64);
	AddChild(m_Map);

	// 카메라 이동
	GetCamera()->Translate(-640, 0);

	return true;
}

void IsoMapScene::Update(float deltaTime) {
	Scene::Update(deltaTime);

	UpdateCamera();
}

void IsoMapScene::Render() {
	Object::Render();
}

void IsoMapScene::UpdateCamera() {
	if (Input::GetInstance()->GetKeyState('A') == KeyState::Pressed) {
		GetCamera()->Translate(-15, 0);
	} else if (Input::GetInstance()->GetKeyState('D') == KeyState::Pressed) {
		GetCamera()->Translate(15, 0);
	}
	if (Input::GetInstance()->GetKeyState('W') == KeyState::Pressed) {
		GetCamera()->Translate(0, -15);
	} else if (Input::GetInstance()->GetKeyState('S') == KeyState::Pressed) {
		GetCamera()->Translate(0, 15);
	}

	if (Input::GetInstance()->GetKeyState('R') == KeyState::Pressed) {
		GetCamera()->Scale(0.01f, 0.01f);
	} else if (Input::GetInstance()->GetKeyState('T') == KeyState::Pressed) {
		GetCamera()->Scale(-0.01f, -0.01f);
	}

	if (Input::GetInstance()->GetKeyState('Q') == KeyState::Pressed) {
		GetCamera()->Rotate(0.05f);
	} else if (Input::GetInstance()->GetKeyState('E') == KeyState::Pressed) {
		GetCamera()->Rotate(-0.05f);
	}
}