#pragma once
#include "GameObject.h"

class CObjectButton final : public CGameObject
{
public:
	bool IsCollision(CGameObject &inObject) override
	{
		float l_x = m_Position.Get_X();
		float l_y = m_Position.Get_Y();
		l_x = std::abs(l_x - inObject.GetPosition().Get_X());
		l_y = std::abs(l_y - inObject.GetPosition().Get_Y());
		return (l_x < m_Width && l_y < m_Height);
	}
	string GetTextureName() const override
	{
		return m_TextureName;
	}
	//_ 
	void SetWH(const float inWidth, const float inHeight)
	{
		m_Width = inWidth;
		m_Height = inHeight;
	}
	void SetTextureName(const string inTextureName)
	{
		m_TextureName = inTextureName;
	}
private:
	float m_Width, m_Height;
	string m_TextureName;
};