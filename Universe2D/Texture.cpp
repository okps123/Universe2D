#include "Precompiled.h"
#include "Texture.h"

#include "Application.h"
#include "Renderer.h"

Texture::Texture(std::wstring fileName)
{
    HRESULT hr;
    hr = D3DXCreateTextureFromFileEx(
        Application::GetInstance()->GetRenderer()->GetDevice(),
        fileName.c_str(),
        D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
        1, 0, D3DFMT_A8R8G8B8, D3DPOOL_MANAGED,
        D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL,
        &m_Texture);

    if FAILED(hr)
    {
        // 오류 처리
        printf("[Texture] 텍스쳐 생성 실패 (%s)\n", fileName);
        return;
    }

    D3DSURFACE_DESC desc;
    m_Texture->GetLevelDesc(0, &desc);

    m_Width = desc.Width;
    m_Height = desc.Height;
}
Texture::~Texture()
{
    SAFE_RELEASE(m_Texture);
}