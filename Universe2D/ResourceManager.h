#pragma once

class Texture;
class Sound;
class ResourceManager : public Singleton<ResourceManager>
{
private:
    std::unordered_map<std::wstring, Texture*> m_TextureMap;

public:
    ResourceManager();
    ~ResourceManager();

    Texture* LoadTextureFromFile(std::wstring fileName);
	Sound* LoadSoundFromFile(std::wstring fileName);
};

