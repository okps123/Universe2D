#pragma once

/* 
모든 오브젝트의 부모가 되는 클래스입니다

간결하게 사용하기 위해 Transform 속성과 합쳐져 있습니다.
추후에 분리할 예정입니다
*/

class Collider;
class Object
{
protected:
	typedef std::vector<Object*> ObjectList;

	bool m_Visible;
	bool m_TransformUpdated;

	Object* m_Parent;
	ObjectList m_Children;

	Vector2 m_Size;
	Vector2 m_Position;
	Vector2 m_Scale;
	float m_Rotation;

	Vector2 m_AnchorPoint;
	Vector2 m_AnchorPointInPoints;

	Matrix m_Matrix;

	std::string m_Name;

public:
	static Object* Create();

	Object();
	virtual ~Object();

public:
	virtual bool Initialize();

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

private:
	// 실제 AnchorPoint의 위치를 계산하는 함수입니다
	void CalculateAnchorPointInPoint();

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

		m_TransformUpdated = false;
	}
	virtual void SetPosition(float x, float y)
	{
		m_Position.x = x;
		m_Position.y = y;

		m_TransformUpdated = false;
	}

	virtual const Vector2& GetSize() const
	{
		return m_Size; 
	}
	virtual void SetSize(const Vector2& size)
	{
		m_Size = size;

		m_TransformUpdated = false;
	}
	virtual void SetSize(float sx, float sy)
	{
		m_Size.x = sx;
		m_Size.y = sy;

		m_TransformUpdated = false;
	}

	virtual const Vector2& GetScale() const 
	{
		return m_Scale; 
	}
	virtual void SetScale(const Vector2& scale)
	{
		m_Scale = scale;

		m_TransformUpdated = false;
	}
	virtual void SetScale(float sx, float sy)
	{
		m_Scale.x = sx;
		m_Scale.y = sy;

		m_TransformUpdated = false;
	}

	virtual const Vector2& GetAnchorPoint() const
	{
		return m_AnchorPoint;
	}
	virtual void SetAnchorPoint(const Vector2& anchorPoint)
	{
		m_AnchorPoint = anchorPoint;
		
		// 실제 위치를 계산하는 함수를 호출합니다
		CalculateAnchorPointInPoint();

		m_TransformUpdated = false;
	}
	virtual void SetAnchorPoint(float ax, float ay)
	{
		m_AnchorPoint.x = ax;
		m_AnchorPoint.y = ay;

		// 실제 위치를 계산하는 함수를 호출합니다
		CalculateAnchorPointInPoint();

		m_TransformUpdated = false;
	}

	virtual float GetRotation() const
	{
		return m_Rotation; 
	}
	virtual void SetRotation(float rotation) 
	{
		m_Rotation = rotation; 

		m_TransformUpdated = false;
	}

	virtual bool GetVisible() const 
	{
		return m_Visible; 
	}
	virtual void SetVisible(bool visible)
	{
		m_Visible = visible; 

		m_TransformUpdated = false;
	}
	
	virtual const std::string& GetName() const
	{
		return m_Name;
	}
	virtual void SetName(const std::string& name)
	{
		m_Name = name;
	}

	virtual D3DXMATRIX GetMatrix() 
	{
		return m_Matrix; 
	}
};