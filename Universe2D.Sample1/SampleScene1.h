 #pragma once

class SampleScene1 : public Scene
{
private:
	Sprite* m_Circle1;

public:
    SampleScene1();
    ~SampleScene1();

public:
    void Update(float deltaTime);
    void Render();
};