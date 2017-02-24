#include "Precompiled.h"
#include "Label.h"

#include "Application.h"
#include "Renderer.h"

Label* Label::Create(const std::wstring& fontFace, int fontSize)
{
	return Label::Create(fontFace, fontSize, D3DCOLOR_XRGB(0, 0, 0));
}
Label* Label::Create(const std::wstring& fontFace, int fontSize, D3DCOLOR color)
{
	auto label = new (std::nothrow) Label();
	if (label && label->InitializeWithFont(fontFace, fontSize, color))
	{
		label->AutoRelease();
		return label;
	}

	SAFE_DELETE(label);
	return nullptr;
}

Label::Label()
	: m_Font(nullptr)
	, m_Color(D3DCOLOR_XRGB(0,0,0))
	, m_Text(nullptr)
	, m_FontFace(nullptr)
	, m_FontSize(0)
{
}

Label::~Label()
{
    SAFE_RELEASE(m_Font);
}

bool Label::InitializeWithFont(const std::wstring& fontFace, int fontSize, D3DCOLOR fontColor)
{
	m_FontFace = fontFace;
	m_FontSize = fontSize;

	auto renderer = Application::GetInstance()->GetRenderer();
	HRESULT hr = D3DXCreateFont(renderer->GetDevice(),
		fontSize, 0, FW_NORMAL, D3DX_DEFAULT, false, DEFAULT_CHARSET, OUT_TT_PRECIS,
		ANTIALIASED_QUALITY, NULL, fontFace.c_str(), &m_Font);

	if FAILED(hr)
		return false;

	return true;
}

void Label::Render()
{
    Object::Render();

    RECT rect;
    SetRectEmpty(&rect);

    m_Font->DrawTextW(NULL, m_Text.c_str(), m_Text.size(), &rect, DT_CALCRECT, m_Color);

	Vector2 position = GetPosition();

    RECT wrapRect;
    SetRect(&wrapRect,
		position.x,
		position.y,
		position.x + rect.right,
		position.y + rect.bottom);

    m_Font->DrawTextW(NULL, m_Text.c_str(), m_Text.size(), &wrapRect, DT_NOCLIP, m_Color);
}
