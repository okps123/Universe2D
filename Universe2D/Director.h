#pragma once
class Director : public Singleton<Director>
{
public:
    Director();
    ~Director();

public:
    bool Initialize();
    bool Release();
};

