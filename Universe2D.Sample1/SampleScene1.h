#pragma once

class Collider;
class SampleScene1 : public Scene
{
private:
	Sprite* circle1;
	Sprite* circle2;

	Collider* collider1;
	Collider* collider2;

public:
    SampleScene1();
    ~SampleScene1();

public:
    void Update(float deltaTime);
    void Render();
};