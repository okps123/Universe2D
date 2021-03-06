#include "Precompiled.h"
#include "Label.h"

Label* Label::Create(const std::wstring& fontFace, int fontSize)
{
	return Label::Create(fontFace, fontSize, D3DCOLOR_XRGB(0, 0, 0));
}
Label* Label::Create(const std::wstring& fontFace, int fontSize, D3DCOLOR color)
{
	auto label = new (std::nothrow) Label();
	if (label && label->InitializeWithFont(fontFace, fontSize, color))
	{
		return label;
	}

	SAFE_DELETE(label);
	return nullptr;
}

Label::Label()
	: m_Font(nullptr)
	, m_Color(D3DCOLOR_XRGB(0,0,0))
	, m_Text(L"")
	, m_FontFace(L"")
	, m_FontSize(0) {
}

Label::~Label()
{
    SAFE_RELEASE(m_Font);
}

bool Label::InitializeWithFont(const std::wstring& fontFace, int fontSize, D3DCOLOR fontColor)
{
	HRESULT hr = D3DXCreateFont(Renderer::GetInstance()->GetDevice(),
		fontSize, 0, FW_NORMAL, D3DX_DEFAULT, false, DEFAULT_CHARSET, OUT_TT_PRECIS,
		ANTIALIASED_QUALITY, NULL, fontFace.c_str(), &m_Font);

	// 폰트 생성에 실패
	if FAILED(hr)
		return false;

	m_FontFace = fontFace;
	m_FontSize = fontSize;
	m_Color = fontColor;

	return true;
}

void Label::Render()
{
    Object::Render();

    RECT rect;
    SetRectEmpty(&rect);

    m_Font->DrawTextW(NULL, m_Text.c_str(), m_Text.size(), &rect, DT_CALCRECT, m_Color);

	Vector3 position = *(Vector3*)&m_Matrix._41;

    RECT wrapRect;
    SetRect(&wrapRect,
		position.x,
		position.y,
		position.x + rect.right,
		position.y + rect.bottom);

    m_Font->DrawTextW(NULL, m_Text.c_str(), m_Text.size(), &wrapRect, DT_NOCLIP, m_Color);
}
