#pragma once

class Object;
class AutoReleasePool : public Singleton<AutoReleasePool>
{
private:
	std::vector<Object*> m_ManagedObjectList;

public:
	AutoReleasePool();
	~AutoReleasePool();

	void Clear();
	void AddObject(Object* object);

	bool Contains(Object* object);
};

