#pragma once
// allegro5
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
// STL
#include <string>
#include <vector>
#include <map>

using std::vector;
using std::string;
using std::map;

enum class E_TEXTURES
{

};

/* 
 * Текстура грунта 128х128
 * размеры окна и игрового мира кратны ей
*/

const int ScreenW = 768;	// 128 Х 6
const int ScreenH = 640;	// 128 Х 5

struct SSprite
{
	string bitmap_name;
	float pos_x = 0;
	float pos_y = 0;
	float angle = 0.0f;
};

/*
 * 
 * Отвечает за прорисовку объектов экранной области
 * 
 *
*/
class CRender
{
public:
	//_
	static CRender &instance() 
	{
		static CRender _instance;
		return _instance;
	}
	//_
	void LoadTextures() {}
	//_
	void Render();
	//_
	void ClearSprites() { m_Sprites.clear(); }
	//_
	void AddBitmap(const SSprite &sprite) 
	{
		m_Sprites.push_back(sprite);
	}
	//_ Создает спрайт и возвращает его ID
	void CreateSprite(string inBitmapName, float in) {}
	//_ Добавляет спрайт в очередь рендеринга
	void DrawSprite() {}
	//_ 
	CRender(const CRender &) = delete;
	//_ 
	CRender & operator=(const CRender &) = delete;
	//_
	~CRender() 
	{
		for (auto i : m_Bitmaps)
		{
			al_destroy_bitmap(i.second);
		}
		al_destroy_display(m_Display);
	}
private:
	CRender();

	ALLEGRO_DISPLAY* m_Display;
	//_ Очередь рендеринга
	vector<SSprite> m_Sprites;
	//_ Все загруженные ресурсы изображений
	map<string, ALLEGRO_BITMAP*> m_Bitmaps;
};