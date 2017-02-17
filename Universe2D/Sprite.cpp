#include "Precompiled.h"
#include "Sprite.h"

#include "Application.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture.h"

Sprite::Sprite(std::wstring fileName)
	: m_ImageWidth(.0f), m_ImageHeight(.0f),
	m_ColorA(0), m_ColorR(0), m_ColorG(0), m_ColorB(0),
	m_Renderer(nullptr), m_Texture(nullptr), IsLoaded(false)
{
	m_Renderer = Application::GetInstance()->GetRenderer();
	m_Texture = ResourceManager::GetInstance()->LoadTextureFromFile(fileName);

	// 텍스쳐가 정상적으로 불러와졌는지 검사
	IsLoaded = m_Texture ? true : false;

	// 텍스쳐가 정상적이지않으므로 그냥 중지
	// 오류 처리에 따라서 오류 메세지가 담긴 이미지로 바꾸는 등 후처리를 할 수 있을 듯.
	if (!IsLoaded)
		return;

	m_ImageWidth = static_cast<float>(m_Texture->GetWidth());
	m_ImageHeight = static_cast<float>(m_Texture->GetHeight());

	m_Center = {
		m_ImageWidth / 2,
		m_ImageHeight / 2
	};

	//m_Position = m_Center;

	D3DXCreateSprite(m_Renderer->GetDevice(), &m_D3DSprite);
}
Sprite* Sprite::Create(std::wstring fileName)
{
	auto instance = new Sprite(fileName);
	return instance;
}
Sprite::~Sprite()
{
	SAFE_RELEASE(m_D3DSprite);

	m_Texture = nullptr;
	m_Renderer = nullptr;
}

void Sprite::Resize(float width, float height)
{
	m_Scale = {
		width / m_ImageWidth,
		height / m_ImageHeight
	};

	m_Center = m_Scale / 2;
}

void Sprite::Render()
{
	if (!m_Visible || !IsLoaded) return;

	Object::Render();

	// 하나의 이미지에서 그려질 부분의 영역(Rect)을 설정 할 수 있음

	RECT srcRect;
	SetRect(&srcRect,
		0,
		0,
		static_cast<int>(m_ImageWidth),
		static_cast<int>(m_ImageHeight));

	m_D3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_D3DSprite->SetTransform(&m_Matrix);
	m_D3DSprite->Draw(
		m_Texture->GetD3DTexture(),
		&srcRect, NULL, &D3DXVECTOR3(-m_ImageWidth / 2, -m_ImageHeight / 2, .0f), //-m_ImageWidth / 2, -m_ImageHeight / 2
		D3DCOLOR_ARGB(255 - m_ColorA, 255 - m_ColorR, 255 - m_ColorG, 255 - m_ColorB));
	m_D3DSprite->End();
}
