#pragma once
#include <string>
using std::string;
// 
class CSprite
{
private:
	string m_BitmapName;
	float  m_sx;	// Source x
	float  m_sy;
	float  m_sw;
	float  m_sh;
	float  m_Tint;	// Transparent
	float  m_cx;
	float  m_cy;
	float  m_dx;
	float  m_dy;
	float  m_xs;
	float  m_ys;
	float  m_an;
};
/*
void al_draw_tinted_scaled_rotated_bitmap_region(ALLEGRO_BITMAP *bitmap,
	float sx, float sy, float sw, float sh,
	ALLEGRO_COLOR tint,
	float cx, float cy, float dx, float dy, float xscale, float yscale,
	float angle, int flags)
*/