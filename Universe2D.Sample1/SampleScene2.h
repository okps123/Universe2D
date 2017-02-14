#pragma once

class SampleScene2 : public Scene
{
private:
	Sprite* Background;

public:
	SampleScene2();
	~SampleScene2();

	void Update(float deltaTime);
	void Render();
};