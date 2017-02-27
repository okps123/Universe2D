 #pragma once

class SampleScene1 : public Scene
{
private:
	Sprite* circle1;

public:
    SampleScene1();
    ~SampleScene1();

public:
    void Update(float deltaTime);
    void Render();
};