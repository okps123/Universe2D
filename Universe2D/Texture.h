#pragma once
class Texture
{
private:
    std::wstring m_FileName;
	Vector2 m_Size;

    LPDIRECT3DTEXTURE9 m_D3DTexture;

    Texture(std::wstring fileName);
public:
    static Texture* Create(std::wstring& fileName);
    ~Texture();

	bool InitializeWithFile(std::wstring fileName);

public:
	const std::wstring& GetFileName() const;
	const Vector2& GetSize() const;

	const LPDIRECT3DTEXTURE9 GetD3DTexture() const;
};
