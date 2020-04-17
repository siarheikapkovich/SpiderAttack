#include "Render.h"
CRender::CRender()
{

	al_init_image_addon();
	m_Display = al_create_display(ScreenW, ScreenH);
	//_ Загрузка текстур
	m_Bitmap["Spider_1"] = al_load_bitmap("GFX/Spider_1.bmp");
	al_convert_mask_to_alpha(m_Bitmap["Spider_1"], al_map_rgb(255, 0, 255));
	m_Bitmap["Spider_2"] = al_load_bitmap("GFX/Spider_2.bmp");
	al_convert_mask_to_alpha(m_Bitmap["Spider_2"], al_map_rgb(255, 0, 255));
	m_Bitmap["Spider_3"] = al_load_bitmap("GFX/Spider_3.bmp");
	al_convert_mask_to_alpha(m_Bitmap["Spider_3"], al_map_rgb(255, 0, 255));
	m_Bitmap["Spider_4"] = al_load_bitmap("GFX/Spider_4.bmp");
	al_convert_mask_to_alpha(m_Bitmap["Spider_4"], al_map_rgb(255, 0, 255));
	m_Bitmap["Zvanie_1"] = al_load_bitmap("GFX/Radovoi.bmp");
	al_convert_mask_to_alpha(m_Bitmap["Zvanie_1"], al_map_rgb(255, 0, 255));
	m_Bitmap["Menu_Item"] = al_load_bitmap("GFX/Menu_Item.bmp");
	al_convert_mask_to_alpha(m_Bitmap["Menu_Item"], al_map_rgb(255, 0, 255));
}

void CRender::Render()
{
	al_clear_to_color(al_map_rgb(150, 200, 235));
	for (auto i : m_Sprites)
	{
		float w = al_get_bitmap_width(m_Bitmap[i.bitmap_name]);
		float h = al_get_bitmap_height(m_Bitmap[i.bitmap_name]);
		al_draw_rotated_bitmap(m_Bitmap[i.bitmap_name], w / 2.0f, h / 2.0f, i.pos_x, i.pos_y, i.angle, 0);
	}
	al_flip_display();
}
