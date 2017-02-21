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
	bool m_IsDestroyed;

public:
    Object();
    virtual ~Object();

public:
	virtual void OnCollision(Collider* collider) {};

    virtual void Update(float deltaTime);
    virtual void Render();

public:
	void AddChild(Object* obj);
	void RemoveChild(Object* obj, bool deleteMemory);

	void Transform(float x, float y);
	void Transform(D3DXVECTOR2 vector);

	void Destroy();

public:
    Object* GetParent() { return m_Parent; }
	void SetParent(Object* obj) { m_Parent = obj; }

	D3DXVECTOR2 GetPosition() { return m_Position; }
	void SetPosition(D3DXVECTOR2 position) { m_Position = position; }

	D3DXVECTOR2 GetSize() { return m_Size; }
	void SetSize(D3DXVECTOR2 size) 
	{ 
		m_Size = size; 
		m_Center = size / 2;
	}

	D3DXVECTOR2 GetScale() { return m_Scale; }
	void SetScale(D3DXVECTOR2 scale) { m_Scale = scale; }

	D3DXVECTOR2 GetCenter() const { return m_Center; }
	void SetCenter(D3DXVECTOR2 center) { m_Center = center; }

	float GetRotation() { return m_Rotation; }
	void SetRotation(float rotation) { m_Rotation = rotation; }

	bool GetVisible() { return m_Visible; }
	void SetVisible(bool visible) { m_Visible = visible; }

	D3DXMATRIX GetMatrix() { return m_Matrix; }

	bool IsDestoryed() { return m_IsDestroyed; }
};