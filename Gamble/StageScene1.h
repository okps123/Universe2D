#pragma once
class StageScene1 : public Scene {
public:
	StageScene1();
	~StageScene1();

public:
	CREATE_FUNC(StageScene1);

public:
	bool Initialize() override;
	
public:
	void Update(float deltaTime) override;
};

