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

	void Translate(float x, float y);
	void Translate(Vector2 vector);

public:
    Object* GetParent() { return m_Parent; }
	void SetParent(Object* obj) { m_Parent = obj; }

	Vector2 GetPosition() { return m_Position; }
	void SetPosition(Vector2 position) { m_Position = position; }

	Vector2 GetSize() { return m_Size; }
	void SetSize(Vector2 size) 
	{ 
		m_Size = size; 
	}

	Vector2 GetScale() { return m_Scale; }
	void SetScale(Vector2 scale) { m_Scale = scale; }

	Vector2 GetCenter() const { return m_Center; }
	void SetCenter(Vector2 center) { m_Center = center; }

	float GetRotation() { return m_Rotation; }
	void SetRotation(float rotation) { m_Rotation = rotation; }

	bool GetVisible() { return m_Visible; }
	void SetVisible(bool visible) { m_Visible = visible; }

	D3DXMATRIX GetMatrix() { return m_Matrix; }
};