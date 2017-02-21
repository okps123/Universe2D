#include "Precompiled.h"
#include "ResourceManager.h"

#include "Texture.h"

ResourceManager::ResourceManager()
{
}
ResourceManager::~ResourceManager()
{
}

Texture* ResourceManager::LoadTextureFromFile(std::wstring fileName)
{
    if (!m_TextureMap[fileName])
    {
        auto texture = Texture::Create(fileName);
     
        // 텍스쳐 생성에 실패했다면 nullptr 반환
        if (!texture)
            return nullptr;

        m_TextureMap[fileName] = texture;
    }

    return m_TextureMap[fileName];
}

Sound * ResourceManager::LoadSoundFromFile(std::wstring fileName)
{
	return nullptr;
}
