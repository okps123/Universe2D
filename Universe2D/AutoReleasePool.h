#pragma once

class Reference;
class AutoReleasePool : public Singleton<AutoReleasePool>
{
private:
	std::vector<Reference*> m_ManagedObjectList;

public:
	AutoReleasePool();
	~AutoReleasePool();

	void AddObject(Reference* object);
	void Clear();

	bool Contains(Reference* object);
};

