#pragma once

class SampleScene2 : public Scene
{
public:
	SampleScene2();
	~SampleScene2();

	static Scene* Create();

public:
	bool Initialize() override;

public:
	void Update(float deltaTime) override;
	void Render() override;
};