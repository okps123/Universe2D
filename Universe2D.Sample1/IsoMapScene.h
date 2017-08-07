#pragma once

class Map;
class IsoMapScene : public Scene {
private:
	Map* m_Map;
	Sprite* box;

	Sprite* player;

public:
	IsoMapScene();
	~IsoMapScene();

public:
	CREATE_FUNC(IsoMapScene);

public:
	bool Initialize() override;
	void Update(float deltaTime) override;
	void Render() override;

public:
	void UpdateCamera();
};

