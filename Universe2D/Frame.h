#pragma once

class Frame : public Object {
public:
	Frame() {
	}
	~Frame() {
	}

public:
	virtual void Update(float deltaTime) {
		Object::Update(deltaTime);
	}
	virtual void Render() {
		Object::Render();
	}
};

