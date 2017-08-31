#pragma once
class ProgressBar : public Object {
private:
	float m_MaximizeValue;
	float m_Value;

private:
	Sprite* m_Background;
	Sprite* m_Foreground;

public:
	ProgressBar()
		: m_MaximizeValue(100)
		, m_Value(0)
		, m_Background(nullptr)
		, m_Foreground(nullptr) {};
	~ProgressBar() {};

public:
	static ProgressBar* Create(const std::wstring& background, const std::wstring& foreground) {
		auto p = new (std::nothrow) ProgressBar();
		if (p && p->InitializeWithSprite(background, foreground)) {
			return p;
		}

		SAFE_DELETE(p);
		return nullptr;
	}

public:
	bool InitializeWithSprite(const std::wstring& background, const std::wstring& foreground) {
		m_Background = Sprite::Create(background);
		m_Background->SetAnchorPoint(0.f, 0.f);

		m_Foreground = Sprite::Create(foreground);
		m_Foreground->SetAnchorPoint(0.f, 0.f);

		AddChild(m_Background);
		AddChild(m_Foreground);

		return true;
	}

public:
	void Update(float deltaTime) {
		Object::Update(deltaTime);

		auto rect = m_Foreground->GetSourceRect();
		rect.right = m_Foreground->GetSize().x / m_MaximizeValue * m_Value;

		m_Foreground->SetSourceRect(rect);
	}

public:
	int GetValue() { return m_Value; }
	void SetValue(int value) { m_Value = value; }
};