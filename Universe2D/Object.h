#pragma once

class Collider;
class Object
{
protected:
	typedef std::vector<Object*> ObjectList;

	bool m_Visible;

	bool m_Managed;
	uint m_ReferenceCount;

	Object* m_Parent;
	ObjectList m_Children;

	Vector2 m_Size;
	Vector2 m_Center;
	Vector2 m_Position;
	Vector2 m_Scale;
	float m_Rotation;

	Vector2 m_AnchorPoint;
	Vector2 m_AnchorPointInPoints;

	Matrix m_Matrix;

public:
	static Object* Create();

	Object();
	virtual ~Object();

public:
	virtual bool Initialize();

	// 참조 카운트 증가
	void Retain();
	// 참조 카운트 감소
	void Release();

	// AutoReleasePool 등록
	void AutoRelease();

public:
	virtual void OnCollision(Collider* collider) {};

	virtual void Update(float deltaTime);
	virtual void Render();

public:
	void AddChild(Object* obj);
	void RemoveChild(Object* obj);

public:
	void Translate(Vector2 v);
	void Translate(float x, float y);

	void TranslateScale(Vector2 sv);
	void TranslateScale(float sx, float sy);

	void TranslateRotate(float r);

public:
	Object* GetParent() 
	{
		return m_Parent; 
	}
	void SetParent(Object* obj) 
	{
		m_Parent = obj;
	}

	virtual const Vector2& GetPosition() const
	{
		return m_Position;
	}
	virtual void SetPosition(const Vector2& position) 
	{
		m_Position = position;
	}

	virtual const Vector2& GetSize() const
	{
		return m_Size; 
	}
	virtual void SetSize(const Vector2& size)
	{
		m_Size = size;
	}

	virtual const Vector2& GetScale() const 
	{
		return m_Scale; 
	}
	virtual void SetScale(const Vector2& scale)
	{
		m_Scale = scale;
	}

	virtual const Vector2& GetCenter() const
	{
		return m_Center;
	}
	virtual void SetCenter(const Vector2& center)
	{
		m_Center = center;
	}

	virtual const Vector2& GetAnchorPoint() const
	{
		return m_AnchorPoint;
	}
	virtual void SetAnchorPoint(const Vector2& anchorPoint)
	{
		m_AnchorPoint = anchorPoint;
	}

	virtual float GetRotation() const
	{
		return m_Rotation; 
	}
	virtual void SetRotation(float rotation) 
	{
		m_Rotation = rotation; 
	}

	virtual bool GetVisible() const 
	{
		return m_Visible; 
	}
	virtual void SetVisible(bool visible)
	{
		m_Visible = visible; 
	}

	virtual D3DXMATRIX GetMatrix() { return m_Matrix; }
};