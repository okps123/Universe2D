#pragma once

class Texture;
class Sound;

class ResourceManager : public Singleton<ResourceManager>
{
private:
    std::unordered_map<std::wstring, Texture*> m_TextureCacheMap;

public:
    ResourceManager();
    ~ResourceManager();

    Texture* LoadTextureFromFile(const std::wstring& fileName);
	Sound* LoadSoundFromFile(const std::wstring& fileName);
};

