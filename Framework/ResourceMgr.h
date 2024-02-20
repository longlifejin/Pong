#pragma once
#include "Singleton.h"

template <typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>> // 템플릿 클래스
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

	bool Load(const std::string& filePath) // 리소스 업로드
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
		for (const auto& pair : resourceMap) // pair는 타입이 pair이다.
		{
			delete pair.second; // 전체 동적 할당 받은 두 번째 요소를 할당 해제
		}

		resourceMap.clear(); // 해시 맵 내용 정리
	}
	bool Unload(const std::string& filePath) // 리소스 언로드
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
	T* GetResource(const std::string& filePath) // 리소스 찾기
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
		if (it != resources.end()) //찾은 경우
			return *(it->second); //그럼 그거 걍 리턴

		if (!load || !Load(filePath)) //없으면
		{
			return Empty;
		}

		return *(resources.find(filePath)->second);
	}

};

template <typename T>
T ResourceMgr<T>::Empty;  // 정적 변수 초기화

#define RES_MGR_FONT (Singleton<ResourceMgr<sf::Font>>::Instance())
#define RES_MGR_TEXTURE (Singleton<ResourceMgr<sf::Texture>>::Instance())
#define RES_MGR_SOUND_BUFFER (Singleton<ResourceMgr<sf::SoundBuffer>>::Instance())