#pragma once
#include "Object.h"

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
	virtual void Translate(float x, float y) override {
		m_Position.x += x;
		m_Position.y += y;

		m_TransformUpdate = true;
	}

	virtual void Scale(float sx, float sy) override {
		m_Scale.x += sx;
		m_Scale.y += sy;

		m_TransformUpdate = true;
	}

	virtual void Rotate(float r) override {
		m_Rotation += r;
		m_TransformUpdate = true;
	}
};

