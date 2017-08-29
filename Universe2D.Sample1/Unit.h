#pragma once
class Unit : public Object {
public:
	int HP;

public:
	float MoveSpeed;

public:
	Unit() 
		: HP(1)
		, MoveSpeed(1.f) {
	};
	virtual ~Unit() {};
};

