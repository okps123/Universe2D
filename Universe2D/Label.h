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

private:
    Label(std::wstring text, std::wstring fontFace, int fontSize);
public:
    static Label* Create(std::wstring text, std::wstring fontFace, int fontSize);
    ~Label();

    void Render() override;
};

