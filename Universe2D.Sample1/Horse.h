#pragma once

class Horse : public Object {
public:
	Sprite* sprite;

public:
	// 번호
	int Numebr;

	// 스테미너
	int Stemina;

	// 속도
	int Speed;

	// 순간 가속 속도
	int SpurtSpeed;

	// 마지막 가속 속도
	int LastSpurtSpeed;
	
public:
	Horse() {};
	virtual ~Horse() {};

public:

};