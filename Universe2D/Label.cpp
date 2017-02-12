#include "Precompiled.h"
#include "Label.h"

#include "Application.h"
#include "Renderer.h"

Label::Label(std::wstring text, std::wstring fontFace, int fontSize) : m_Font(nullptr), m_Color(D3DCOLOR_XRGB(0,0,0))
{
    m_Text = text;
    m_FontFace = fontFace;
    m_FontSize = fontSize;

    HRESULT hr = D3DXCreateFont(Application::GetInstance()->GetRenderer()->GetDevice(),
        fontSize, 0, FW_NORMAL, D3DX_DEFAULT, false, DEFAULT_CHARSET, OUT_TT_PRECIS,
        ANTIALIASED_QUALITY, NULL, fontFace.c_str(), &m_Font);

    if FAILED(hr)
    {
        printf("[Label] 폰트 생성 실패\n");
    }
}
Label* Label::Create(std::wstring text, std::wstring fontFace, int fontSize)
{
    auto instance = new Label(text, fontFace, fontSize);
    return instance;
}

Label * Label::Create(std::wstring text, std::wstring fontFace, int fontSize, D3DCOLOR color)
{
    auto instance = new Label(text, fontFace, fontSize);
    instance->SetColor(color);

    return instance;
}

Label::~Label()
{
    SAFE_RELEASE(m_Font);
}

void Label::Render()
{
    Object::Render();

    RECT rect;
    SetRectEmpty(&rect);

    m_Font->DrawTextW(NULL, m_Text.c_str(), m_Text.size(), &rect, DT_CALCRECT, m_Color);

    float x = m_Position.x;
    float y = m_Position.y;

    RECT wrapRect;
    SetRect(&wrapRect, x, y, x + rect.right, y + rect.bottom);

    m_Font->DrawTextW(NULL, m_Text.c_str(), m_Text.size(), &wrapRect, DT_NOCLIP, m_Color);
}
