#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

#include "TypeDefine.h"
#include "Singleton.h"

#define SAFE_DELETE(x) { if(x) { delete x; x = NULL; } }
#define SAFE_RELEASE(x) { if(x) { x->Release(); x = NULL; } }