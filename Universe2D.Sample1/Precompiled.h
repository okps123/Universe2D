#pragma once

template<class T, class K>
bool IsContains(T& data, K& value) {
	return std::find(data.begin(), data.end(), value) != data.end();
}

#include "Universe2D.h"