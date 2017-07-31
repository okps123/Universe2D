#pragma once

class Scene;
class Camera : public Object {
protected:
	Scene* m_Scene;

private:
	Vector2 m_TargetPosition;
	Vector2 m_TargetScale;
	float	m_TargetRotation;

public:
	Camera();
	virtual ~Camera();

public:
	static Camera* Create(Scene* scene);

public:
	virtual bool InitializeWithScene(Scene* scene);

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

public:
	virtual void Translate(float x, float y) override;
	virtual void Scale(float sx, float sy) override;
	virtual void Rotate(float r) override;

public:
	Vector2 ScreenToWorldPoint(Vector2 position);
	Vector2 WorldToScreenPoint(Vector2 position);
};

