#pragma once
class SampleScene3 : public Scene {
public:
	SampleScene3();
	~SampleScene3();

public:
	CREATE_FUNC(SampleScene3);

public:
	bool Initialize() override;

public:
	void Update(float deltaTime) override;
};

