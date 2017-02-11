#pragma once
class Texture
{
private:
    std::wstring m_FileName;
    int m_Width;
    int m_Height;

    LPDIRECT3DTEXTURE9 m_Texture;

public:
    Texture(std::wstring fileName);
    ~Texture();

    inline LPDIRECT3DTEXTURE9 GetD3DTexture() { return m_Texture; };
};
