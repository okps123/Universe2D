#include "Precompiled.h"
#include "Sprite.h"

#include "Application.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Texture.h"

Sprite::Sprite()
	: m_ColorA(0)
	, m_ColorR(0)
	, m_ColorG(0)
	, m_ColorB(0)
	, m_Texture(nullptr)
{
}
Sprite::~Sprite()
{
	printf("[Sprite] Sprite Called Destructor\n");

	if (m_D3DSprite)
		SAFE_RELEASE(m_D3DSprite);
}

Sprite* Sprite::Create(std::wstring fileName)
{
	printf("[Sprite] Called Static Create()\n");

	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->InitializeWithFile(fileName))
	{
		sprite->AutoRelease();
		return sprite;
	}

	SAFE_DELETE(sprite);

	return nullptr;
}

bool Sprite::InitializeWithFile(const std::wstring & fileName)
{
	m_Texture = ResourceManager::GetInstance()->LoadTextureFromFile(fileName);
	if (!m_Texture)
		return false;

	auto textureSize = m_Texture->GetSize();
	SetSize(textureSize);

	auto renderer = Application::GetInstance()->GetRenderer();
	if FAILED(D3DXCreateSprite(renderer->GetDevice(), &m_D3DSprite))
		return false;

	SetAnchorPoint({ 0.5f, 0.5f });

	return true;
}

void Sprite::Resize(float width, float height)
{
	SetScale({
		width / m_Size.x,
		height / m_Size.y
	});
}

void Sprite::Render()
{
	if (!m_Visible)
		return;

	Object::Render();

	// 하나의 이미지에서 그려질 부분의 영역(Rect)을 설정 할 수 있음
	RECT srcRect;
	SetRect(&srcRect,
		0,
		0,
		static_cast<int>(m_Size.x),
		static_cast<int>(m_Size.y));

	auto center = D3DXVECTOR3(m_AnchorPointInPoints.x, m_AnchorPointInPoints.y, 0.f);

	m_D3DSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_D3DSprite->SetTransform(&m_Matrix);
	m_D3DSprite->Draw(
		m_Texture->GetD3DTexture(),
		&srcRect, &center, NULL,
		D3DCOLOR_ARGB(255 - m_ColorA, 255 - m_ColorR, 255 - m_ColorG, 255 - m_ColorB));
	m_D3DSprite->End();
}
