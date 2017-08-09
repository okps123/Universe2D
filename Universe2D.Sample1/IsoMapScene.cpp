#include "Precompiled.h"
#include "IsoMapScene.h"

#include "Tile.h"
#include "Map.h"

IsoMapScene::IsoMapScene() {
}
IsoMapScene::~IsoMapScene() {
}

bool IsoMapScene::Initialize() {
	Scene::Initialize();

	m_Map = Map::Create();
	m_Map->CreateMap(10, 10);
	AddChild(m_Map);

	GetCamera()->Translate(-640, 0);

	return true;
}

void IsoMapScene::Update(float deltaTime) {
	Scene::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState(VK_LBUTTON) == KeyState::Down) {
		auto objectPosition = GetCamera()->ScreenToWorldPoint(Input::GetInstance()->GetMousePosition());
		auto object = Sprite::Create(L"Resources\\oak.png");
		object->SetAnchorPoint(0.5f, 1.0f);
		object->SetPosition(objectPosition);

		m_Map->AddMapObject(object);
	}

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