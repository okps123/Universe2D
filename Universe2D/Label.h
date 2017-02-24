#pragma once
#include "Object.h"

class Label : public Object
{
private:
	LPD3DXFONT m_Font;
	D3DCOLOR m_Color;

	std::wstring m_Text;
	std::wstring m_FontFace;
	int m_FontSize;

public:
	static Label* Create(const std::wstring& fontFace, int fontSize);
	static Label* Create(const std::wstring& fontFace, int fontSize, D3DCOLOR color);

	Label();
	~Label();

private:
	bool InitializeWithFont(const std::wstring& fontFace, int fontSize, D3DCOLOR fontColor);

public:
	const std::wstring& GetText() const
	{
		return m_Text; 
	}
	void SetText(const std::wstring& text) 
	{
		m_Text = text; 
	}

	D3DCOLOR GetColor() const { return m_Color; }
	void SetColor(D3DCOLOR color) { m_Color = color; }

public:
	void Render() override;
};

