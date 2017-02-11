#include "Precompiled.h"
#include "Sprite.h"

#include "Application.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture.h"

Sprite::Sprite(std::wstring fileName)
    : m_ImageWidth(.0f), m_ImageHeight(.0f),
    m_ColorR(0), m_ColorG(0), m_ColorB(0), m_Opacity(0),
    m_Renderer(nullptr), m_Texture(nullptr)
{
    m_Renderer = Application::GetInstance()->GetRenderer();
    m_Texture = ResourceManager::GetInstance()->LoadTextureFromFile(fileName);

    m_ImageWidth = m_Texture->GetWidth();
    m_ImageHeight = m_Texture->GetHeight();

    D3DXCreateSprite(m_Renderer->GetDevice(), &m_D3DSprite);
}
Sprite::~Sprite()
{
    SAFE_RELEASE(m_D3DSprite);

    m_Texture = nullptr;
    m_Renderer = nullptr;
}

void Sprite::Render()
{
    if (!m_Visible) return;

    Object::Render();

    byte a = 255 - m_Opacity;
    byte r = 255 - m_ColorR;
    byte g = 255 - m_ColorG;
    byte b = 255 - m_ColorB;

    RECT srcRect;
    SetRect(&srcRect, 0, 0, m_ImageWidth, m_ImageHeight);

    m_D3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
    m_D3DSprite->SetTransform(&m_Matrix);
    m_D3DSprite->Draw(
        m_Texture->GetD3DTexture(),
        &srcRect, NULL, &D3DXVECTOR3(.0f, .0f, .0f), //-m_ImageWidth / 2, -m_ImageHeight / 2
        D3DCOLOR_ARGB(a, r, g, b));
    m_D3DSprite->End();
}
