#pragma once
class AnimationGroup : public Object
{
private:
	uint m_Index;

public:
	AnimationGroup();
	virtual ~AnimationGroup();

public:
	CREATE_FUNC(AnimationGroup);

public:
	const uint& GetIndex() const {
		return m_Index;
	}
	void SetIndex(uint index) {
		m_Index = index;
	}

public:
	void Update(float deltaTime) override;
	void Render() override;
};