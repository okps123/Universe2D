#pragma once

class Scene : public virtual Object
{
private:
	Camera* m_Camera;

public:
	Scene();
    virtual ~Scene();

public:
	CREATE_FUNC(Scene);

public:
	virtual bool Initialize() override;

	virtual void Update(float deltaTime) override;
	virtual void Render() override;

public:
	Camera* GetCamera() {
		return m_Camera;
	}
	void SetCamera(Camera* camera) {
		m_Camera = camera;
	}
};