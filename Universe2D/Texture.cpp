#include "Precompiled.h"
#include "Texture.h"

#include "Application.h"
#include "Renderer.h"

Texture::Texture(std::wstring fileName)
	: m_D3DTexture(nullptr)
	, m_Size(0.f, 0.f)
{
    HRESULT hr;
    hr = D3DXCreateTextureFromFileEx(
        Application::GetInstance()->GetRenderer()->GetDevice(),
        fileName.c_str(),
        D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
        1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
        D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL,
        &m_D3DTexture);

    if FAILED(hr)
    {
        // 오류 처리
        printf("[Texture] 텍스쳐 생성 실패 (%s)\n", fileName.c_str());
        return;
    }

    D3DSURFACE_DESC desc;
    m_D3DTexture->GetLevelDesc(0, &desc);

	m_Size.x = static_cast<float>(desc.Width);
	m_Size.y = static_cast<float>(desc.Height);
    
    m_FileName = fileName;
}
Texture* Texture::Create(std::wstring fileName)
{
    auto texture = new (std::nothrow) Texture(fileName);
	

    return nullptr;
}
Texture::~Texture()
{
    SAFE_RELEASE(m_D3DTexture);
}

const Vector2& Texture::GetSize() const
{
	return m_Size;
}

LPDIRECT3DTEXTURE9 Texture::GetD3DTexture()
{
	return m_D3DTexture;
}
