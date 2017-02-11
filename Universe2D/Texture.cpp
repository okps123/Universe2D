#include "Precompiled.h"
#include "Texture.h"

#include "Application.h"
#include "Renderer.h"

Texture::Texture(std::wstring fileName) :
    m_Texture(nullptr), m_Width(0), m_Height(0)
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
        printf("[Texture] 텍스쳐 생성 실패 (%s)\n", fileName.c_str());
        return;
    }

    D3DSURFACE_DESC desc;
    m_Texture->GetLevelDesc(0, &desc);

    m_Width = desc.Width;
    m_Height = desc.Height;
    
    m_FileName = fileName;
}
Texture* Texture::Create(std::wstring fileName)
{
    auto instance = new Texture(fileName);
    
    if (instance->GetWidth() == 0 && instance->GetHeight() == 0)
        return nullptr;

    return instance;
}
Texture::~Texture()
{
    SAFE_RELEASE(m_Texture);
}