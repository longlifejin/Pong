#pragma once

enum class Axis
{
	Horizontal,
	Vertical,
};

struct AxisInfo
{
	Axis axis;

	std::list<sf::Keyboard::Key> positives; //���� �Է�
	std::list<sf::Keyboard::Key> negatives; //���� �Է�

	float sensi; //������ ������ ������ ����
	float value; //�Է��� �� 0, -1, 1 ����
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
	static void Update(float dt); //Ű ���� �Է��� ���� �� ����


	static void Clear();

	static float GetAxisRaw(Axis axis); //-1, 0, 1 ����
	static float GetAxis(Axis axis); //���� ���� -1.0 ~ 1.0 ����
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
		// list�� ���� ���� ���� keyboard�����̶� ��ġ�� �ʰ� ������ ��
		return (sf::Keyboard::Key)(button + sf::Keyboard::Key::KeyCount);
	}

	static sf::Mouse::Button KeyToMouseButton(sf::Mouse::Button button)
	{
		return (sf::Mouse::Button)(button + sf::Keyboard::Key::KeyCount);
	}
};

