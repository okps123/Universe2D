#pragma once

class ItemCreateScene : public Scene {
public:
	ItemCreateScene();
	~ItemCreateScene();

public:
	CREATE_FUNC(ItemCreateScene);

public:
	bool Initialize() override;

	void Update(float deltaTime) override;
	void Render() override;

};

