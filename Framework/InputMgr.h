#pragma once

enum class Axis
{
	Horizontal,
	Vertical,
};

struct AxisInfo
{
	Axis axis;

	std::list<sf::Keyboard::Key> positives; //양의 입력
	std::list<sf::Keyboard::Key> negatives; //음의 입력

	float sensi; //가속의 빠르고 느림을 조절
	float value; //입력한 값 0, -1, 1 저장
};



class InputMgr
{
private:
	static std::map<Axis, AxisInfo> axisInfoMap;

	static std::list<sf::Keyboard::Key> downList;
	static std::list<sf::Keyboard::Key> upList;
	static std::list<sf::Keyboard::Key> ingList;

public:
	static void Init();

	static void UpdateEvent(const sf::Event& ev);
	static void Update(float dt); //키 설정 입력을 받은 후 갱신


	static void Clear();

	static float GetAxisRaw(Axis axis); //-1, 0, 1 리턴
	static float GetAxis(Axis axis); //값의 범위 -1.0 ~ 1.0 리턴
	static bool GetKeyDown(sf::Keyboard::Key key);
	static bool GetKeyUp(sf::Keyboard::Key key);
	static bool GetKey(sf::Keyboard::Key key);

	int keyboardToMouse();

	static sf::Vector2f GetMousePos();
	static bool GetMouseButtonDown(sf::Mouse::Button key);
	static bool GetMouseButtonUp(sf::Mouse::Button key);
	static bool GetMouseButton(sf::Mouse::Button key);

	static sf::Keyboard::Key MouseButtonToKey(sf::Mouse::Button button)
	{
		// list에 넣을 때도 기존 keyboard값들이랑 겹치지 않게 더해준 것
		return (sf::Keyboard::Key)(button + sf::Keyboard::Key::KeyCount);
	}

	static sf::Mouse::Button KeyToMouseButton(sf::Mouse::Button button)
	{
		return (sf::Mouse::Button)(button + sf::Keyboard::Key::KeyCount);
	}
};

