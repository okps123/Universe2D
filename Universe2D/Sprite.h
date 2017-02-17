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
    byte GetOpacity() const { return m_ColorA; }
    void SetOpacity(byte opacity) { m_ColorA = opacity; }

    float GetWidth() const { return m_ImageWidth; }
    float GetHeight() const { return m_ImageHeight; }

	D3DXVECTOR2 GetCenter() const { return m_Center; }

	// 테스트 코드
	void OnCollisionEnter(Collider* collider) override
	{
		printf("아아아아아아ㅏ앙아ㅏㄱ!!!!\n");
	}

    // 특정 크기에 맞게 Scale을 수정함
    void Resize(float width, float height);

public:
    void Render() override;
};

