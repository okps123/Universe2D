#include "Precompiled.h"
#include "SampleScene2.h"

SampleScene2::SampleScene2() {
}
SampleScene2::~SampleScene2() {
}

bool SampleScene2::Initialize() {
	auto map = Map::Create(10, 10);
	AddChild(map);

	return true;
}

void SampleScene2::Update(float deltaTime) {
	Scene::Update(deltaTime);
}

void SampleScene2::Render() {
	Scene::Render();
}
