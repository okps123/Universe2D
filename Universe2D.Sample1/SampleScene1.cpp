#include "Precompiled.h"
#include "SampleScene1.h"

#include "SampleScene2.h"
#include "CircleCollider.h"

SampleScene1::SampleScene1() {
}
SampleScene1::~SampleScene1() {
}

bool SampleScene1::Initialize() {
	Scene::Initialize();

	return true;
}

void SampleScene1::Update(float deltaTime) {
	Scene::Update(deltaTime);

	if (Input::GetInstance()->GetKeyState('2') == KeyState::KEY_PRESSED) {
		Director::GetInstance()->SetScene(SampleScene2::Create());
	}

	if (Input::GetInstance()->GetMouseButtonState(MouseButton::Left) == KEY_PRESSED) {
		auto sprite = Sprite::Create(L"Resources\\test.png");
		sprite->SetPosition(Input::GetInstance()->GetMousePosition());

		AddChild(sprite);
	}

	// 이동
	if (Input::GetInstance()->GetKeyState('A') == KeyState::KEY_PRESSED) {
		GetCamera()->Translate(-5, 0);
		//Translate(5, 0);
	} else if (Input::GetInstance()->GetKeyState('D') == KeyState::KEY_PRESSED) {
		GetCamera()->Translate(5, 0);
		//Translate(-5, 0);
	}
	if (Input::GetInstance()->GetKeyState('W') == KeyState::KEY_PRESSED) {
		GetCamera()->Translate(0, -5);
	} else if (Input::GetInstance()->GetKeyState('S') == KeyState::KEY_PRESSED) {
		GetCamera()->Translate(0, 5);
	}

	// 확대 축소
	if (Input::GetInstance()->GetKeyState('R') == KeyState::KEY_PRESSED) {
		GetCamera()->Scale(0.01f, 0.01f);
	} else if (Input::GetInstance()->GetKeyState('T') == KeyState::KEY_PRESSED) {
		GetCamera()->Scale(-0.01f, -0.01f);
	}

	// 회전
	if (Input::GetInstance()->GetKeyState('Q') == KeyState::KEY_PRESSED) {
		GetCamera()->Rotate(0.05f);
	} else if (Input::GetInstance()->GetKeyState('E') == KeyState::KEY_PRESSED) {
		GetCamera()->Rotate(-0.05f);
	}
}
void SampleScene1::Render() {
	Scene::Render();
}
