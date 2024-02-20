#pragma once
#include <memory>
class GameObject;

class Scene
{
protected:
	Scene(const Scene&) = delete;
	Scene(Scene&&) = delete;
	Scene& operator=(const Scene&) = delete;
	Scene& operator=(Scene&&) = delete;

	SceneIds id;
	std::unordered_map<size_t, std::vector<GameObject*>> gameObjectsMap;

	std::list<GameObject*> gameObjects; // ����Ʈ �����ͷ� ���� �ʿ�
	std::list<GameObject*> gameOBjectsActive; // Ȱ��ȭ �� GameObjects
	std::list<GameObject*> gameOBjectsInActive; // ��Ȱ��ȭ �� GameObjects

	ResourceMgr<sf::Texture>& textureManager;
	ResourceMgr<sf::Font>& fontManager;
	ResourceMgr<sf::SoundBuffer>& soundManager;

	// active, inactive �� gameobjects�� �ٸ��� �����ϴ� ����Ʈ �ʿ�

public:
	Scene(SceneIds id);
	virtual ~Scene() = default;

	virtual void Init() = 0; // Scene ���� ����
	virtual void Release();

	virtual void Enter(); // Scene ���� ��
	virtual void Exit() = 0;

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

	virtual GameObject* FindGameObject(const std::string& name);
	virtual std::list<GameObject*>& FindAllGameObjectwithName(const std::string& name);
	virtual bool FindAll(const std::string& name, std::list<GameObject*>& list);
	virtual GameObject* AddGameObject(GameObject* gameObject);
	virtual GameObject* AddGameObject(const std::string& name);
	virtual void RemoveGameObject(GameObject* gameObject);
	virtual void RemoveGameObject(std::string name);
};