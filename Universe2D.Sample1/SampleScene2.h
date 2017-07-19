#pragma once

class Tile : public Object {
private:
	Tile* m_ParentTile;

	int m_X, m_Y;
	int m_F, m_G, m_H;

	bool m_IsObstacle;

	Sprite* m_Sprite;

public:
	Tile() : m_ParentTile(nullptr), m_X(0), m_Y(0), m_F(0), m_G(0), m_H(0), m_IsObstacle(false) {};
	~Tile() {};

	static Tile* Create(int x, int y, bool isObstacle, Sprite* sprite) {
		auto tile = new (std::nothrow) Tile();
		if (tile && tile->InitializeWithTile(x, y, isObstacle, sprite)) {
			return tile;
		}

		SAFE_DELETE(tile);
		return nullptr;
	}

public:
	bool InitializeWithTile(int x, int y, bool isObstacle, Sprite* sprite) {
		SetX(x);
		SetY(y);
		SetObstacle(isObstacle);
		SetSprite(sprite);

		GetSprite()->SetParent(this);

		return true;
	}

	void Update(float deltaTime) override {
		Object::Update(deltaTime);

		if (m_Sprite) {
			m_Sprite->Update(deltaTime);
		}
	}

	void Render() override {
		Object::Render();

		if (m_Sprite) {
			m_Sprite->Render();
		}
	}

public:
	int GetX() { return m_X; }
	void SetX(int x) { m_X = x; }

	int GetY() { return m_Y; }
	void SetY(int y) { m_Y = y; }

	int GetF() { return m_F; }
	void SetF(int f) { m_F = f; }

	int GetG() { return m_G; }
	void SetG(int g) { m_G = g; }

	int GetH() { return m_H; }
	void SetH(int h) { m_H = h; }

	bool GetObstacle() { return m_IsObstacle; }
	void SetObstacle(bool isObstacle) { m_IsObstacle = isObstacle; }

	Sprite* GetSprite() { return m_Sprite; }
	void SetSprite(Sprite* sprite) { m_Sprite = sprite; }
};

class Map : public Object {
public:
	Tile*** tileMap;
	int Width, Height;

public:
	Map() : Width(0), Height(0) {
	}
	~Map() {};

public:
	static Map* Create(int width, int height) {
		auto map = new (std::nothrow) Map();
		if (map && map->InitializeWithMap(width, height)) {
			return map;
		}

		SAFE_DELETE(map);
		return nullptr;
	}

public:
	bool Initialize() override {
		return false;
	}
	bool InitializeWithMap(int width, int height) {
		Object::Initialize();

		Width = width;
		Height = height;

		tileMap = new Tile**[height];
		for (int i = 0; i < height; i++) {
			tileMap[i] = new Tile*[width];
			for (int j = 0; j < width; j++) {
				Tile* tile = Tile::Create(j, i, false, Sprite::Create(L"Resources\\ground.png"));
				tile->SetPosition(32 + j * 64, 32 + i * 64);

				tileMap[i][j] = tile;
				AddChild(tile);
			}
		}

		auto block1 = Tile::Create(3, 3, true, Sprite::Create(L"Resources\\box.png"));
		block1->SetPosition(3 * 64, 3 * 64);

		tileMap[3][3] = block1;
		AddChild(block1);
		return true;
	}

	void Update(float deltaTime) override {
		Object::Update(deltaTime);
	}
};

class SampleScene2 : public Scene {
public:
	SampleScene2();
	~SampleScene2();

public:
	CREATE_FUNC(SampleScene2);

public:
	bool Initialize() override;

public:
	void Update(float deltaTime) override;
	void Render() override;
};