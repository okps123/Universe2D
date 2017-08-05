#include "Precompiled.h"
#include "AnimationGroup.h"

AnimationGroup::AnimationGroup() : m_Index(0) {}
AnimationGroup::~AnimationGroup() {}

void AnimationGroup::Update(float deltaTime) {
	if (m_Index < m_Children.size())
		m_Children[m_Index]->Update(deltaTime);
}
void AnimationGroup::Render() {
	if (m_Index < m_Children.size())
		m_Children[m_Index]->Render();
}
