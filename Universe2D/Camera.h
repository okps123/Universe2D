#pragma once

class Scene;
class Camera : public Object {
protected:
	Scene* m_Scene;

public:
	Camera();
	virtual ~Camera();

public:
	static Camera* Create(Scene* scene);

public:
	virtual bool InitializeWithScene(Scene* scene);

	virtual void Update(float deltaTime) override {
		Object::Update(deltaTime);
	}
	virtual void Render() override {
		Object::Render();
	}

public:
	virtual void Translate(float x, float y) override;
	virtual void Scale(float sx, float sy) override;
	virtual void Rotate(float r) override;
};

