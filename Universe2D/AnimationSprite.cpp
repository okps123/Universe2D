#include "Precompiled.h"
#include "AnimationSprite.h"

#include "Sprite.h"

AnimationSprite::AnimationSprite(int frameDelay) 
	: m_CurrentFrame(0)
	, m_FrameDelay(0)
	, m_FrameCounter(0)
{
	m_FrameDelay = frameDelay;
}

void AnimationSprite::AddFrame(std::wstring fileName)
{
	auto spriteFrame = Sprite::Create(fileName);
	spriteFrame->SetParent(this);

	m_SpriteList.push_back(spriteFrame);
}

AnimationSprite::~AnimationSprite()
{
}

void AnimationSprite::Update(float deltaTime)
{
	Object::Update(deltaTime);

	m_FrameCounter++;
	if (m_FrameCounter >= m_FrameDelay)
	{
		m_FrameCounter = 0;
		m_CurrentFrame++;
	}

	if (m_CurrentFrame > (m_SpriteList.size() - 1))
		m_CurrentFrame = 0;

	m_SpriteList.at(m_CurrentFrame)->Update(deltaTime);
}

void AnimationSprite::Render()
{
	Object::Render();

	if (!m_Visible)
		return;

	m_SpriteList.at(m_CurrentFrame)->Render();
}