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
        m_TextureMap[fileName] = new Texture(fileName);
    }

    return m_TextureMap[fileName];
}
