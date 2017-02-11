#pragma once
class Object
{
private:
    typedef std::vector<Object*> ObjectList;

    Object* m_Parent;
    ObjectList m_ChildList;

private:
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

    D3DXMATRIX GetMatrix() { return m_Matrix; }

    void AddChild(Object* obj);
    void RemoveChild(Object* obj);
};