#include "Precompiled.h"
#include "SampleScene1.h"

SampleScene1::SampleScene1()
{
    sprite1 = Sprite::Create(L"C:\\Users\\Raye\\Pictures\\인체\\60791751_p0.jpg");

    sprite2 = Sprite::Create(L"C:\\Users\\Raye\\Pictures\\인체\\앞으로 숙임.jpg");
    sprite2->Resize(1280, 720);
    //AddChild(sprite1);
    AddChild(sprite2);
}
SampleScene1::~SampleScene1()
{
}

void SampleScene1::Update(float deltaTime)
{
}
void SampleScene1::Render()
{
    Scene::Render();
}
