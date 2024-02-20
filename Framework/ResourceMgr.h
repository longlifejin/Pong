#pragma once
#include "Singleton.h"

template <typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>> // ���ø� Ŭ����
{
private:
	std::unordered_map<std::string, T*> resourceMap;
	friend class Singleton<ResourceMgr<T>>;

public:
	ResourceMgr(const ResourceMgr& ref) = delete;
	ResourceMgr(ResourceMgr&& ref) = delete;
	ResourceMgr& operator=(const ResourceMgr& ref) = delete;
	ResourceMgr& operator=(ResourceMgr&& ref) = delete;

	static T Empty;
	ResourceMgr() = default;
	virtual ~ResourceMgr()
	{
		UnloadAll();
	}

	bool Load(const std::string& filePath) // ���ҽ� ���ε�
	{
		if (resourceMap.find(filePath) != resourceMap.end())
		{
			return false;
		}

		T* resource = new T();

		bool isSuccess = resource->loadFromFile(filePath);

		if (isSuccess)
		{
			resourceMap[filePath] = resource;
		}

		return isSuccess;
	}
	void UnloadAll()
	{
		for (const auto& pair : resourceMap) // pair�� Ÿ���� pair�̴�.
		{
			delete pair.second; // ��ü ���� �Ҵ� ���� �� ��° ��Ҹ� �Ҵ� ����
		}

		resourceMap.clear(); // �ؽ� �� ���� ����
	}
	bool Unload(const std::string& filePath) // ���ҽ� ��ε�
	{
		auto it = resourceMap.find(filePath);
		if (it == resourceMap.end())
		{
			return false;
		}

		delete it->second;
		resourceMap.erase(it);
		return true;
	}
	T* GetResource(const std::string& filePath) // ���ҽ� ã��
	{
		auto it = resourceMap.find(filePath);
		if (it == resourceMap.end())
		{
			return nullptr;
		}

		return it->second;
	}

	T& Get(const std::string& filePath, bool load = true)
	{
		auto it = resources.find(filePath);
		if (it != resources.end()) //ã�� ���
			return *(it->second); //�׷� �װ� �� ����

		if (!load || !Load(filePath)) //������
		{
			return Empty;
		}

		return *(resources.find(filePath)->second);
	}

};

template <typename T>
T ResourceMgr<T>::Empty;  // ���� ���� �ʱ�ȭ

#define RES_MGR_FONT (Singleton<ResourceMgr<sf::Font>>::Instance())
#define RES_MGR_TEXTURE (Singleton<ResourceMgr<sf::Texture>>::Instance())
#define RES_MGR_SOUND_BUFFER (Singleton<ResourceMgr<sf::SoundBuffer>>::Instance())