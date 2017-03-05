#include "Precompiled.h"
#include "Texture.h"

#include "Application.h"
#include "Renderer.h"

Texture* Texture::Create(const std::wstring& fileName)
{
	auto texture = new (std::nothrow) Texture();
	if (texture && texture->InitializeWithFile(fileName))
	{
		return texture;
	}

	SAFE_DELETE(texture);
	return nullptr;
}

Texture::Texture()
	: m_D3DTexture(nullptr)
	, m_Size(0.f, 0.f)
{
}
Texture::~Texture()
{
	if(m_D3DTexture)
		SAFE_RELEASE(m_D3DTexture);
}

bool Texture::InitializeWithFile(const std::wstring& fileName)
{
	// Application에 강한 의존성을 가지고 있음
	auto renderer = Application::GetInstance()->GetRenderer();

	HRESULT hr;
	hr = D3DXCreateTextureFromFileEx(
		renderer->GetDevice(),
		fileName.c_str(),
		D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
		1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL,
		&m_D3DTexture);

	if FAILED(hr)
		return false;

	D3DSURFACE_DESC desc;
	m_D3DTexture->GetLevelDesc(0, &desc);

	m_Size.x = static_cast<float>(desc.Width);
	m_Size.y = static_cast<float>(desc.Height);

	m_FileName = fileName;

	return true;
}

const std::wstring & Texture::GetFileName() const
{
	return m_FileName;
}
const Vector2& Texture::GetSize() const
{
	return m_Size;
}

const LPDIRECT3DTEXTURE9 Texture::GetD3DTexture() const
{
	return m_D3DTexture;
}
