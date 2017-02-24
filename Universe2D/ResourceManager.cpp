#include "Precompiled.h"
#include "ResourceManager.h"

#include "Texture.h"

ResourceManager::ResourceManager()
{
}
ResourceManager::~ResourceManager()
{
}

Texture* ResourceManager::LoadTextureFromFile(const std::wstring& fileName)
{
	// 캐시맵에 텍스쳐가 없으면 새로 생성해서 캐시로 등록합니다
    if (!m_TextureCacheMap.count(fileName))
    {
        auto texture = Texture::Create(fileName);

        // 텍스쳐 생성에 실패했다면 nullptr 반환
        if (texture == nullptr)
            return nullptr;

		// CacheMap에 등록하고 참조 카운터를 증가시킵니다
		m_TextureCacheMap[fileName] = texture;
		texture->Retain();
    }

    return m_TextureCacheMap[fileName];
}

Sound* ResourceManager::LoadSoundFromFile(const std::wstring& fileName)
{
	return nullptr;
}
