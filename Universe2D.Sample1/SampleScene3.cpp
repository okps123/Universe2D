#include "Precompiled.h"
#include "SampleScene3.h"

SampleScene3::SampleScene3() {
}
SampleScene3::~SampleScene3() {
}

bool SampleScene3::Initialize() {
	Scene::Initialize();

	int TileWidth = 100;
	int TileHalfWidth = TileWidth / 2;

	int TileHeight = 50;
	int TileHalfHeight = TileHeight / 2;

	int MapWidth = 15;
	int MapHeight = 15;

	int MapActualWidth = MapWidth * TileHalfWidth + MapHeight * TileHalfWidth;
	int MapActualHeight = MapHeight * TileHalfHeight + MapWidth * TileHalfHeight;

	for (int i = 0; i < MapHeight; i++) {
		for (int j = 0; j < MapWidth; j++) {
			auto tile = Sprite::Create(L"Resources\\isometric\\tile.png");
			tile->SetPosition((1280 / 2), (720/2)-(MapActualHeight/2));
			tile->Translate(
				j * TileHalfWidth - i * TileHalfWidth,
				i * TileHalfHeight + j * TileHalfHeight);

			AddChild(tile);
		}
	}

	return true;
}

void SampleScene3::Update(float deltaTime) {
	Scene::Update(deltaTime);

	if (Input::GetInstance()->GetMouseButtonState(MouseButton::Left) == KeyState::KEY_DOWN) {
		auto screenPoint = GetCamera()->ScreenToWorldPoint(Input::GetInstance()->GetMousePosition());
		printf("%f %f\n", screenPoint.x, screenPoint.y);
	}

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
