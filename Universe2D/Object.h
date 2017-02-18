#pragma once
class Collider;
class Object
{
protected:
    typedef std::vector<Object*> ObjectList;

    Object* m_Parent;
    ObjectList m_ChildList;

    D3DXVECTOR2 m_Position;
    D3DXVECTOR2 m_Center;
    D3DXVECTOR2 m_Scale;
    float m_Rotation;

    D3DXMATRIX m_Matrix;

	D3DXVECTOR2 m_Size;
    bool m_Visible;

public:
    Object();
    virtual ~Object();

public:
	virtual void OnCollisionEnter(Collider* collider) {};

    virtual void Update(float deltaTime);
    virtual void Render();

public:
	void AddChild(Object* obj);
	void RemoveChild(Object* obj, bool deleteMemory);

	void Transform(float x, float y);
	void Transform(D3DXVECTOR2 vector);

public:
    Object* GetParent() { return m_Parent; }
	void SetParent(Object* obj) { m_Parent = obj; }

	D3DXVECTOR2 GetPosition() { return m_Position; }
	void SetPosition(D3DXVECTOR2 position) { m_Position = position; }

	D3DXVECTOR2 GetSize() { return m_Size; }
	void SetSize(D3DXVECTOR2 size) { m_Size = size; }

	D3DXVECTOR2 GetScale() { return m_Scale; }
	void SetScale(D3DXVECTOR2 scale) { m_Scale = scale; }

	float GetRotation() { return m_Rotation; }
	void SetRotation(float rotation) { m_Rotation = rotation; }

	bool GetVisible() { return m_Visible; }
	void SetVisible(bool visible) { m_Visible = visible; }

	D3DXMATRIX GetMatrix() { return m_Matrix; }
};