

#pragma once
#include "Interactable.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	void Add(std::string name, Interactable* gameObject);
	void Remove(std::string name);
	int GetObjectCount() const;
	Interactable* Get(std::string name) const;

	void DrawAll(sf::RenderWindow& renderWindow);

private:
	std::map<std::string, Interactable*> _gameObjects;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string,Interactable*> & p) const
		{
			delete p.second;
		}
	};
};
