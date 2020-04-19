#include "GameObject.h"

string CObjectSpider::GetTextureName() const
{
	return m_Frames[m_CyrrentFrame];
}
/*
void CObjectSpider::Move()
{
	if (!m_IsStoped)
	{
		++m_CyrrentFrame;
		if (m_CyrrentFrame >= m_Frames.size())
			m_CyrrentFrame = 0;
	}
}
*/