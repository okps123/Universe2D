#pragma once
#include "Object.h"

class Sprite;
class AnimationSprite : public Object
{
private:
	typedef std::vector<Sprite*> SpriteList;

	uint m_CurrentFrame;
	uint m_Delay;
	uint m_FrameCounter;

	SpriteList m_SpriteList;

public:
	AnimationSprite();
	~AnimationSprite();
	
public:
	static AnimationSprite* Create(int delay) {
		auto animationSprite = new (std::nothrow) AnimationSprite();
		if (animationSprite && animationSprite->InitializeWithAnimation(delay)) {
			return animationSprite;
		}

		SAFE_DELETE(animationSprite);
		return nullptr;
	}

public:
	bool InitializeWithAnimation(int delay);

public:
	const int GetDelay() const {
		return m_Delay; 
	}
	void SetDelay(int frame) {
		m_Delay = frame; 
	}

public:
	void AddFrame(std::wstring fileName);

public:
	void Update(float deltaTime) override;
	void Render() override;
};