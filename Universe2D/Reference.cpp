#include "Precompiled.h"
#include "Reference.h"

#include "AutoReleasePool.h"

Reference::Reference()
	: m_Managed(false), m_ReferenceCount(1)
{
}
Reference::~Reference()
{
}

bool Reference::Initialize()
{
	return true;
}

void Reference::Retain()
{
	++m_ReferenceCount;

	printf("[Reference] Called Retain() RefCount: %d\n", m_ReferenceCount);
}
void Reference::Release()
{
	--m_ReferenceCount;

	printf("[Reference] Called Release() RefCount: %d\n", m_ReferenceCount);

	if (m_ReferenceCount == 0)
	{
		delete this;
	}
}

void Reference::AutoRelease()
{
	m_Managed = true;

	AutoReleasePool::GetInstance()->AddObject(this);
}
