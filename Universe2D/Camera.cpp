#include "Precompiled.h"
#include "Camera.h"

Camera::Camera() {
}
Camera::~Camera() {
}

Camera* Camera::Create(Scene * scene) {
	auto camera = new (std::nothrow) Camera();
	if (camera && camera->Initialize()) {
		return camera;
	}

	SAFE_DELETE(camera);
	return nullptr;
}
