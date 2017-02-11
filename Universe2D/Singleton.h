#pragma once

template<class T>
class Singleton
{
private:
    static T* instance;

public:
    static T* GetInstance()
    {
        if (instance == nullptr)
            instance = new T();

        return instance;
    }
};

template<class T>
T* Singleton<T>::instance = nullptr;