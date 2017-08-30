#pragma once

namespace ItemID {
	enum Enum {
		없음,
		// 도구
		숟가락,
		망치,
		손도끼,
		곡갱이,
		톱,
		물통,
		// 아이템
		귤,
		나무잎,
		나무줄기,
		나무장작,
		돌멩이,
		가죽,
		// 건물
		집,
		공작소,
		우물,
		// 생산품
		요새,
		밧줄,
		활,
		화살,
		투석기,
		특수무기
	};
}

class Item {
public:
	ItemID::Enum ID;

public:
	std::string Name;
	std::string Description;

public:
	Item()
		: ID(ItemID::없음)
		, Name("아이템 이름")
		, Description("설명") {};
	~Item() {};
};

