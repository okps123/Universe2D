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

	auto textureSize = m_Texture->GetSize();
	SetSize(textureSize);

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

	//auto scene = Director::GetInstance()->GetScene();
	//Vector2 screenPosition = scene->GetCamera()->WorldToScreenPoint(m_Position);

	//if (screenPosition.x < 0
	//	|| screenPosition.y < 0
	//	|| screenPosition.x > scene->GetSize().x
	//	|| screenPosition.y > scene->GetSize().y) {
	//	printf("%f %f skip render\n", screenPosition.x, screenPosition.y);
	//	return;
	//}

	Object::Render();

	// 텍스쳐에서 그려질 부분의 영역을 설정 할 수 있음
	RECT srcRect;
	SetRect(&srcRect,
		0,
		0,
		static_cast<int>(m_Size.x),
		static_cast<int>(m_Size.y));

	D3DXVECTOR3 center(m_AnchorPointInPoints.x, m_AnchorPointInPoints.y, 0.f);

	auto sprite = Renderer::GetInstance()->GetSprite();
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	sprite->SetTransform(&m_Matrix);
	sprite->Draw(
		m_Texture->GetD3DTexture(),
		&srcRect, &center, NULL,
		D3DCOLOR_ARGB(255 - m_ColorA, 255 - m_ColorR, 255 - m_ColorG, 255 - m_ColorB));
	sprite->End();
}
