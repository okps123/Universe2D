#pragma once

class Map;
class Player;

class IsoMapScene : public Scene {
private:
	Map* m_Map;
	Player* m_Player;

	Object* m_UI;

public:
	IsoMapScene();
	~IsoMapScene();

public:
	CREATE_FUNC(IsoMapScene);

public:
	bool Initialize() override;

	void InitializeUI();

public:
	void Update(float deltaTime) override;
	void UpdateCamera();

public:
	void Render() override;
};

