#pragma once

typedef unsigned int uint;

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;
typedef D3DXMATRIX Matrix;

#define CREATE_FUNC(type) \
static type* Create() { \
	auto instance = new(std::nothrow) type(); \
	if(instance && instance->Initialize()) { \
		return instance; \
	} \
	SAFE_DELETE(instance); \
	return nullptr; \
}