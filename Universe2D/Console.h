#pragma once
#include "Precompiled.h"

namespace Console
{
    inline void Initialize()
    {
        AllocConsole();

        FILE* stream;
        freopen_s(&stream, "CON", "w", stdout);
    }
    inline void Release()
    {
        FreeConsole();
    }
}