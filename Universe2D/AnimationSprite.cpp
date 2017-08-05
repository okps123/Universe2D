#include "Precompiled.h"
#include "AnimationSprite.h"

#include "Sprite.h"

AnimationSprite::AnimationSprite()
	: m_CurrentFrame(0)
	, m_Delay(0)
	, m_FrameCounter(0) {}

void AnimationSprite::AddFrame(std::wstring fileName) {
	auto spriteFrame = Sprite::Create(fileName);
	spriteFrame->SetParent(this);

	m_SpriteList.push_back(spriteFrame);
}

AnimationSprite::~AnimationSprite() {}

bool AnimationSprite::InitializeWithAnimation(int delay) {
	m_Delay = delay;

	return true;
}

void AnimationSprite::Update(float deltaTime) {
	Object::Update(deltaTime);

	m_FrameCounter++;
	if (m_FrameCounter >= m_Delay) {
		m_FrameCounter = 0;
		m_CurrentFrame++;
	}

	if (m_CurrentFrame > (m_SpriteList.size() - 1))
		m_CurrentFrame = 0;

	m_SpriteList.at(m_CurrentFrame)->Update(deltaTime);
}

void AnimationSprite::Render() {
	Object::Render();

	m_SpriteList.at(m_CurrentFrame)->Render();
}