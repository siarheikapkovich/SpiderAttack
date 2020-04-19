#pragma once
#include <vector>
#include "GameObject.h"
class CGame
{
public:
	static CGame &instance()
	{
		static CGame _instance;
		return _instance;
	}
	/*
	CGameObject& GetGameObj(const size_t inNumber)
	{
		return *m_GameObjects[inNumber];
	}*/
private:
	vector<std::unique_ptr<CGameObject>> m_GameObjects;
};