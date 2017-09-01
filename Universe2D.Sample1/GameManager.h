#pragma once

class Player;

class GameManager : public Singleton<GameManager> {
public:
	bool IsStageClear1;
	bool IsStageClear2;

public:
	Player* Player;

public:
	GameManager()
		: IsStageClear1(false)
		, IsStageClear2(false)
		, Player(nullptr) {};
	virtual ~GameManager() {};
};

