#include "Precompiled.h"
#include "StageScene1.h"

#include "Player.h"

StageScene1::StageScene1() {}
StageScene1::~StageScene1() {}

bool StageScene1::Initialize() {
	auto player = Player::Create();
	AddChild(player);

	return true;
}

void StageScene1::Update(float deltaTime) {
	Scene::Update(deltaTime);
}
