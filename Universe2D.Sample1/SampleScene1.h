#pragma once

class SampleScene1 : public Scene
{
private:
    Sprite* m_Sprite1;
    Sprite* m_Sprite2;

public:
    SampleScene1();
    ~SampleScene1();

    void Update(float deltaTime);
    void Render();
};