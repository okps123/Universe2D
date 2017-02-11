#include "Precompiled.h"
#include "SampleScene1.h"

SampleScene1::SampleScene1()
{
    sprite1 = new Sprite(L"C:\\Users\\Raye\\Pictures\\인체\\60791751_p0.jpg");
    sprite1->SetScale({ 0.5f, 0.5f });

    sprite2 = new Sprite(L"C:\\Users\\Raye\\Pictures\\인체\\앞으로 숙임.jpg");
    sprite2->SetPosition({ 100, 100 });
    sprite2->SetScale({ 0.7f, 0.7f });

    AddChild(sprite1);
    AddChild(sprite2);
}
SampleScene1::~SampleScene1()
{
}

void SampleScene1::Update(float deltaTime)
{
    printf("SampleScene1: Update\n");
}
void SampleScene1::Render()
{
    Scene::Render();
    printf("SampleScene1: Render\n");
}
