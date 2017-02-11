#include "Precompiled.h"
#include "SampleScene1.h"

SampleScene1::SampleScene1()
{
    sprite1 = new Sprite(L"C:\\Users\\Raye\\Pictures\\ÀÎÃ¼\\60791751_p0.jpg");
    sprite1->SetScale({ 0.5f, 0.5f });
    AddChild(sprite1);
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
