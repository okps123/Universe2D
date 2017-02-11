#pragma once
class Object
{
private:
    typedef std::vector<Object*> ObjectList;

    Object* m_Parent;
    ObjectList m_ChildList;

protected:
    D3DXVECTOR2 m_Position;
    D3DXVECTOR2 m_Center;
    D3DXVECTOR2 m_Scale;
    float m_Rotation;

    bool m_Visible;

    D3DXMATRIX m_Matrix;

public:
    Object();
    virtual ~Object();

public:
    virtual void Update(float deltaTime);
    virtual void Render();

public:
    Object* GetParent() { return m_Parent; }
    void SetParent(Object* obj) { m_Parent = obj; }

    D3DXVECTOR2 GetPosition() { return m_Position; }
    void SetPosition(D3DXVECTOR2 position) { m_Position = position; }

    D3DXVECTOR2 GetScale() { return m_Scale; }
    void SetScale(D3DXVECTOR2 scale) { m_Scale = scale; }

    D3DXMATRIX GetMatrix() { return m_Matrix; }

public:
    void AddChild(Object* obj);
    void RemoveChild(Object* obj);
};