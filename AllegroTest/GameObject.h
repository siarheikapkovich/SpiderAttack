#pragma once
#include <string>
#include <vector>
#include "GameMath.h"

using std::string;
using std::vector;
enum class E_OBJ_TYPE
{
	Null_Object,	// Объект не является подмножеством Static
	Box_Simple,		// Ящик с низким уровнем выпадания вещей
	Box_Improved,	// Ящик с повышенным уровнем выпадания вещей
	Floor_Small,	// Растение для питания пауков
	Item_Health,	// Аптечка +10%
	Item_Aptec,		// Аптечка +30%
	Item_Battery,	// Заряд аккумулятора +10%
	Item_Board		// Печатная плата с запчастями
};

const int C_DEFAUTT_LIFE_LEVEL = 1;

class CGameObject
{
public:
	CGameObject() = default;
		
	//_ Может не проверять колизии, а сразу взаимодействие (если не пересекаются то и не взаимодействуют)????
	virtual bool IsCollision(CGameObject &inObject) = 0;
	//_ Получение текущей текстуры объекта
	virtual string GetTextureName() const = 0;
	//_
	void MoveToPosition(const float x, const float y) { m_Position = CVector2D(x, y); }
	// Изменение внутреннего состояния объекта
	//virtual void Move() = 0;
	// Взаимодействие текущего с другим объектом
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
	CVector2D	m_Position;							// Мировая позиция
	//CVector2D   m_Velosity;							// Скорость
	float		m_Angle;							// Текущий угол поворота
	//float		m_CollisionRadius;					// Радиус ограничивающего круга
	E_OBJ_TYPE	m_Type;								// Тип объекта
	// Для объектов с ограниченным временем
	// существования (например взрыв)
	// Для автоматического восстановления
	// (регенерация) или уменьшения
	// например при отравлении
	//int32_t		m_LifeChangeDelta;					// Шаг изменения уровня жизни
	// При значении равном или меньше ноля,
	// объект уничтожается
	//int32_t		m_Life = C_DEFAUTT_LIFE_LEVEL;		// Время (значение) жизни объекта
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
	// Функция уменьшает/увеличивает жизнь на значение delta
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
	// Функция уменьшает/увеличивает жизнь на значение delta
	//void UpdateLife(const int delta = -1) { m_Life += delta; }
	//bool IsCollision(CGameObject *object) {}
	string GetTextureName() const override;
	//void Move() override;
private:
	vector<string> m_Frames;
	size_t m_CyrrentFrame;
	bool m_IsStoped;
};