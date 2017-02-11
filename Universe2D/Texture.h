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

public:
    int GetWidth() { return m_Width; }
    int GetHeight() { return m_Height; }

public:
    inline LPDIRECT3DTEXTURE9 GetD3DTexture() { return m_Texture; };
};
