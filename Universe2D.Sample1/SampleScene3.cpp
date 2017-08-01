#include "Precompiled.h"
#include "SampleScene3.h"

#include "Tile.h"
#include "Map.h"

SampleScene3::SampleScene3() {
}
SampleScene3::~SampleScene3() {
}

bool SampleScene3::Initialize() {
	Scene::Initialize();

	m_Map = Map::Create();
	m_Map->CreateMap(10, 10);
	AddChild(m_Map);

	GetCamera()->Translate(-640, 0);

	return true;
}

void SampleScene3::Update(float deltaTime) {
	static Tile* prevTile = nullptr;

	Scene::Update(deltaTime);

	
	//if (Input::GetInstance()->GetKeyState('A') == KeyState::Pressed) {
	//	player->Translate(-2, 0);
	//}
	//if (Input::GetInstance()->GetKeyState('W') == KeyState::Pressed) {
	//	player->Translate(0, -2);
	//}
	//if (Input::GetInstance()->GetKeyState('D') == KeyState::Pressed) {
	//	player->Translate(2, 0);
	//}
	//if (Input::GetInstance()->GetKeyState('S') == KeyState::Pressed) {
	//	player->Translate(0, 2);
	//}

	//auto tile = m_Map->GetTileFromPosition(player->GetPosition());
	//if (tile) {
	//	player->SetZOrder(tile->GetMapPosition().x + tile->GetMapPosition().y - 1);
	//	prevTile = tile;
	//	tile->SetState(TileType::Path);
	////}
	//auto mousePosition = GetCamera()->ScreenToWorldPoint(Input::GetInstance()->GetMousePosition());
	//if (Input::GetInstance()->GetMouseButtonState(MouseButton::Left) == KeyState::Down) {
	//	Tile* tile = m_Map->GetTileFromPosition(mousePosition);
	///*TODO: 	auto home = Sprite::Create(L"Resources\\isometric\\home.png");
	//	home->SetAnchorPoint(0.5f, 1.0f);
	//	home->SetPosition(tile->GetPosition());
	//	home->SetZOrder(tile->GetMapPosition().x -3 + tile->GetMapPosition().y - 3);
	//	AddChild(home);*/
	//	if(tile)
	//		tile->SetState(TileType::Start);

	//}

	//if (Input::GetInstance()->GetMouseButtonState(MouseButton::Right) == KeyState::Down) {
	//	Tile* tile = m_Map->GetTileFromPosition(mousePosition);
	//	tile->SetState(TileType::End);
	//}

	//box->SetPosition(mousePosition);
	
	UpdateCamera();
}

void SampleScene3::Render() {
	Object::Render();
}

void SampleScene3::UpdateCamera() {
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