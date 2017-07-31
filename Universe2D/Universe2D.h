#pragma once

#define SAFE_DELETE(x) { if(x) { delete x; x = NULL; } }
#define SAFE_RELEASE(x) { if(x) { x->Release(); x = NULL; } }

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <stdio.h>
#include <time.h>

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>

#include "TypeDefine.h"
#include "Singleton.h"

#include "Object.h"
#include "ObjecContainer.h"

#include "Camera.h"
#include "Scene.h"
#include "Director.h"

#include "Renderer.h"
#include "Application.h"

#include "Input.h"

#include "Texture.h"
#include "ResourceManager.h"

#include "Label.h"

#include "Frame.h"
#include "Sprite.h"
#include "AnimationSprite.h"

