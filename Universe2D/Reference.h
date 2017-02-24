#pragma once
class Reference
{
protected:
	bool m_Managed;
	uint m_ReferenceCount;

public:
	Reference();
	~Reference();

public:
	virtual bool Initialize();

public:
	void Retain();
	void Release();

	void AutoRelease();
};

