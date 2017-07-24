#pragma once

class Sprite : public Object {
protected:
	Texture* m_Texture;
	byte m_ColorA, m_ColorR, m_ColorG, m_ColorB;

public:
	Sprite();
	~Sprite();

	static Sprite* Create(std::wstring fileName);

private:
	bool InitializeWithFile(const std::wstring& fileName);

public:
	byte GetOpacity() { return m_ColorA; }
	void SetOpacity(byte opacity) { m_ColorA = opacity; }

	Texture* GetTexture() { return m_Texture; }
	void SetTexture(Texture* texture) { m_Texture = texture; }

public:
    void Resize(float width, float height);

public:
    void Render() override;
};

