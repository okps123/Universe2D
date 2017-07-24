#pragma once

class ObjecContainer : public Object {
public:
	ObjecContainer() {
	}
	virtual ~ObjecContainer() {
	}

	CREATE_FUNC(ObjecContainer);

public:
	bool Initialize() override {
		Object::Initialize();

		return true;
	}

	void Update(float deltaTime) override {
		Object::Update(deltaTime);
	}
	void Render() override {
		Object::Render();
	}
};