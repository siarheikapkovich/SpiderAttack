#pragma once
#include <cmath>

const float PI = 3.1415926535f;

class CVector2D;

//CVector2D GetRandomPosition();
//float GetRandomAngle();


inline float ToDegrees(float inRadians)
{
	return inRadians * 180.0f / PI;
}

class CVector2D
{
public:
	CVector2D() : m_X(0.f), m_Y(0.f)	{}
	CVector2D(const float x, const float y) : m_X(x), m_Y(y) {}

	friend CVector2D operator- (const CVector2D &inVecL, const CVector2D &inVecR)
	{
		return CVector2D(inVecL.m_X - inVecR.m_X, inVecL.m_Y - inVecR.m_Y);
	}
	
	float Get_X() const
	{
		return m_X;
	}

	float Get_Y() const
	{
		return m_Y;
	}

	float Length()
	{
		return sqrtf(LengthSq());
	}

	float LengthSq()
	{
		return m_X * m_X + m_Y * m_Y;
	}

	void Normalize()
	{
		float length = Length();
		m_X /= length;
		m_Y /= length;
	}

	friend float Dot(const CVector2D& inLeft, const CVector2D& inRight)
	{
		return (inLeft.m_X * inRight.m_X + inLeft.m_Y * inRight.m_Y);
	}

private:
	float m_X;
	float m_Y;

};