#pragma once
#include "Object.h"

class Renderer;
class Texture;

class Sprite : public Object
{
protected:
    float m_ImageWidth;
    float m_ImageHeight;
    
    unsigned char m_ColorR, m_ColorG, m_ColorB;
    unsigned char m_Opacity;

    LPD3DXSPRITE m_D3DSprite;

private:
    Texture* m_Texture;
    Renderer* m_Renderer;

public:
    Sprite(std::wstring fileName);
    ~Sprite();

public:
    void Render() override;
};

