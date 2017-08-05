#include "Precompiled.h"
#include "ItemCreateScene.h"

ItemCreateScene::ItemCreateScene() {}
ItemCreateScene::~ItemCreateScene() {}

bool ItemCreateScene::Initialize() {

	auto runAnimation = AnimationSprite::Create(3);
	runAnimation->AddFrame(L"Resources\\Horse_01.png");
	runAnimation->AddFrame(L"Resources\\Horse_02.png");
	runAnimation->AddFrame(L"Resources\\Horse_03.png");
	runAnimation->AddFrame(L"Resources\\Horse_04.png");
	runAnimation->AddFrame(L"Resources\\Horse_05.png");
	runAnimation->AddFrame(L"Resources\\Horse_06.png");
	runAnimation->AddFrame(L"Resources\\Horse_07.png");
	runAnimation->AddFrame(L"Resources\\Horse_08.png");
	runAnimation->AddFrame(L"Resources\\Horse_09.png");
	runAnimation->AddFrame(L"Resources\\Horse_10.png");
	runAnimation->AddFrame(L"Resources\\Horse_11.png");
	runAnimation->AddFrame(L"Resources\\Horse_12.png");
	runAnimation->AddFrame(L"Resources\\Horse_13.png");
	runAnimation->AddFrame(L"Resources\\Horse_14.png");
	runAnimation->AddFrame(L"Resources\\Horse_15.png");

	auto group = AnimationGroup::Create();
	group->AddChild(runAnimation);

	group->SetPosition(300, 300);
	group->SetIndex(0);

	AddChild(group);

	return true;
}

void ItemCreateScene::Update(float deltaTime) {
	Scene::Update(deltaTime);
}

void ItemCreateScene::Render() {
	Scene::Render();
}
