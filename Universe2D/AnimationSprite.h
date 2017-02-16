#pragma once
#include "Object.h"

class Sprite;
class AnimationSprite : public Object
{
private:
	typedef std::vector<Sprite*> SpriteList;

	int m_CurrentFrame;
	int m_FrameDelay;
	int m_FrameCounter;

	SpriteList m_SpriteList;

public:
	AnimationSprite(int frameDelay);
	~AnimationSprite();

	int GetFrameDelay() { return m_FrameDelay; }
	void SetFrameDelay(int frame) { m_FrameDelay = frame; }

public:
	void AddFrame(std::wstring fileName);

public:
	void Update(float deltaTime) override;
	void Render() override;
};