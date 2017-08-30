#include "Precompiled.h"
#include "Sprite.h"

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
}

Sprite* Sprite::Create(std::wstring fileName)
{
	auto sprite = new (std::nothrow) Sprite();
	if (sprite && sprite->InitializeWithFile(fileName))
	{
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

	auto size = m_Texture->GetSize();
	SetRect(&m_SourceRect, 0, 0, size.x, size.y);
	SetSize(size);
	

	SetAnchorPoint({ 0.5f, 0.5f });

	return true;
}

void Sprite::Resize(float width, float height)
{
	// width, height를 통해 scale을 계산합니다
	float scaleX = width / m_Size.x;
	float scaleY = height / m_Size.y;

	SetScale(scaleX, scaleY);
}

void Sprite::Render()
{
	if (!m_Visible)
		return;

	Object::Render();

	D3DXVECTOR3 center;
	center.x = m_AnchorPointInPoints.x;
	center.y = m_AnchorPointInPoints.y;
	center.z = 0.f;

	auto sprite = Renderer::GetInstance()->GetSprite();
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->SetTransform(&m_Matrix);
	sprite->Draw(
		m_Texture->GetD3DTexture(),
		&m_SourceRect, &center, NULL,
		D3DCOLOR_ARGB(255 - m_ColorA, 255 - m_ColorR, 255 - m_ColorG, 255 - m_ColorB));
	sprite->End();
}
