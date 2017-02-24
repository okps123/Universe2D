#pragma once
class Texture
{
private:
    std::wstring m_FileName;
	Vector2 m_Size;

    LPDIRECT3DTEXTURE9 m_D3DTexture;

    Texture(std::wstring fileName);
public:
    static Texture* Create(std::wstring fileName);
    ~Texture();

public:
	const Vector2& GetSize() const;

	LPDIRECT3DTEXTURE9 GetD3DTexture();
};
