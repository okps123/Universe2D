#pragma once

class Scene;
class Director : public Singleton<Director>
{
private:
    Scene* m_CurrentScene;

public:
    Director();
    ~Director();

public:
    bool Initialize();
    bool Release();

    bool Update(float deltaTime);
    bool Render();

public:
    Scene* GetScene() { return m_CurrentScene; }
    bool SetScene(Scene* scene);

	Vector2 GetWindowSize();
};

