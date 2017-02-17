#pragma once
#include "Object.h"

class Renderer;
class Texture;

class Sprite : public Object
{
public:
    bool IsLoaded;

protected:
    float m_ImageWidth;
    float m_ImageHeight;
    
    byte m_ColorA, m_ColorR, m_ColorG, m_ColorB;

    LPD3DXSPRITE m_D3DSprite;

private:
    Texture* m_Texture;
    Renderer* m_Renderer;

    Sprite(std::wstring fileName);
public:
    static Sprite* Create(std::wstring fileName);
    ~Sprite();

public:
    byte GetOpacity() { return m_ColorA; }
    void SetOpacity(byte opacity) { m_ColorA = opacity; }

    float GetWidth() { return m_ImageWidth; }
    float GetHeight() { return m_ImageHeight; }

	Texture* GetTexture() { return m_Texture; }
	void SetTexture(Texture* texture) { m_Texture = texture; }

	D3DXVECTOR2 GetCenter() const { return m_Center; }

public:
    void Resize(float width, float height);

public:
    void Render() override;
};

