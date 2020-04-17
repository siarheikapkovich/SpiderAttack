#pragma once
#include <string>
#include <vector>
#include "GameMath.h"

using std::string;
using std::vector;
enum class E_OBJ_TYPE
{
	Null_Object,	// ������ �� �������� ������������� Static
	Box_Simple,		// ���� � ������ ������� ��������� �����
	Box_Improved,	// ���� � ���������� ������� ��������� �����
	Floor_Small,	// �������� ��� ������� ������
	Item_Health,	// ������� +10%
	Item_Aptec,		// ������� +30%
	Item_Battery,	// ����� ������������ +10%
	Item_Board		// �������� ����� � ����������
};

const int C_DEFAUTT_LIFE_LEVEL = 1;

class CGameObject
{
public:
	CGameObject() = default;
		
	//_ ����� �� ��������� �������, � ����� �������������� (���� �� ������������ �� � �� ���������������)????
	virtual bool IsCollision(CGameObject &inObject) = 0;
	//_ ��������� ������� �������� �������
	virtual string GetTextureName() const = 0;
	//_
	void MoveToPosition(const float x, const float y) { m_Position = CVector2D(x, y); }
	// ��������� ����������� ��������� �������
	//virtual void Move() = 0;
	// �������������� �������� � ������ ��������
	//virtual void Process(CGameObject *object) = 0;
	//_ 
	//virtual bool IsMouseCliced(const int inMouseX, const int inMouseY) = 0;
	// ????????????????
	CVector2D GetPosition() const {
		return m_Position;
	}
	E_OBJ_TYPE GetType() const {
		return m_Type;
	}
	virtual ~CGameObject() {}
protected:
	CVector2D	m_Position;							// ������� �������
	//CVector2D   m_Velosity;							// ��������
	float		m_Angle;							// ������� ���� ��������
	//float		m_CollisionRadius;					// ������ ��������������� �����
	E_OBJ_TYPE	m_Type;								// ��� �������
	// ��� �������� � ������������ ��������
	// ������������� (�������� �����)
	// ��� ��������������� ��������������
	// (�����������) ��� ����������
	// �������� ��� ����������
	//int32_t		m_LifeChangeDelta;					// ��� ��������� ������ �����
	// ��� �������� ������ ��� ������ ����,
	// ������ ������������
	//int32_t		m_Life = C_DEFAUTT_LIFE_LEVEL;		// ����� (��������) ����� �������
};

class CObjectStatic : public CGameObject
{
public:
	CObjectStatic() : CGameObject() {}
	//CObjectStatic(ALLEGRO_BITMAP *bitmap) : CGameObject(), m_Bitmap(bitmap) {}
	//void MoveToPosition(const int x, const int y) { m_PosX = x, m_PosY = y; }
	//void RotateToAngle(const float angle) { m_Angle = angle; }
	string GetTextureName() const override {
		return m_TextureName;
	}
private:
	string m_TextureName;
};

class CObjectSpider final : public CGameObject
{
public:
	// ������� ���������/����������� ����� �� �������� delta
	//void UpdateLife(const int delta = -1) { m_Life += delta; }
	//bool IsCollision(CGameObject *object) {}
	string GetTextureName() const override;
	//void Move() override;
private:
	vector<string> m_Frames;
	size_t m_CyrrentFrame;
	bool m_IsStoped;
};

class CObjectPlayer final : public CGameObject
{
public:
	// ������� ���������/����������� ����� �� �������� delta
	//void UpdateLife(const int delta = -1) { m_Life += delta; }
	//bool IsCollision(CGameObject *object) {}
	string GetTextureName() const override;
	//void Move() override;
private:
	vector<string> m_Frames;
	size_t m_CyrrentFrame;
	bool m_IsStoped;
};