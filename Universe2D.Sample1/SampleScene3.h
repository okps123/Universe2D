#pragma once

class Map;
class SampleScene3 : public Scene {
private:
	Map* m_Map;
	Sprite* box;

	Sprite* player;

public:
	SampleScene3();
	~SampleScene3();

public:
	CREATE_FUNC(SampleScene3);

public:
	bool Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;

public:
	void UpdateCamera();
};

