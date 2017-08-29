#pragma once

#include "Universe2D.h"

template<class T, class K>
bool IsContains(T& data, K& value) {
	return std::find(data.begin(), data.end(), value) != data.end();
}

inline float GetDistance(const D3DXVECTOR2& v1, const D3DXVECTOR2& v2) {
	return sqrtf(powf(v1.x - v2.x, 2) + powf(v1.y - v2.y, 2));
} 