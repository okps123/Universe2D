#pragma once
class ProgressBar : public Object {
private:
	int m_MaximizeValue;
	int m_Value;

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
		m_Foreground = Sprite::Create(foreground);

		return true;
	}

	void Update(float deltaTime) {
		Object::Update(deltaTime);

		RECT rect = m_Foreground->GetSourceRect();

		int increment = (rect.right - rect.left) / m_MaximizeValue;
		int value = increment * m_Value;

		rect.right = rect.left + value;

		m_Foreground->SetSourceRect(rect);
	}
};