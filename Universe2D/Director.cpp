#include "Precompiled.h"
#include "Director.h"

Director::Director()
{
}
Director::~Director()
{
    Release();
}

bool Director::Initialize()
{
    return true;
}
bool Director::Release()
{
    return true;
}
