/*
 * ПП
*/
#include "HUD.h"
#include "Input.h"
#include "Render.h"
//#include "GameObject.h"

enum class E_GAME_STATE
{
	Game_Init,		// Инициализация программы и загрузка ресурсов
	Game_Start,		// Стартовое (главное) меню
	Game_Items,		// Меню просмотра вещей (ресурсов) персонажа
	Game_Person,	// Просмотр и улучшение характеристик персонажа
	Game_Kraft,		// Саздание модулей и вещей
	Game_World,		// Мир игры
	Game_Exit		// Завершение и выход
};

int main()
{
	E_GAME_STATE l_State = E_GAME_STATE::Game_Init;
	
	while (l_State != E_GAME_STATE::Game_Exit)
	{
		// Game main
		switch (l_State)
		{
			case E_GAME_STATE::Game_Init:
			{
				//_ Инициализация объектов
				al_init();
				//_ Можно выводить в консоль :)
				CRender::instance().LoadTextures();
				
				//_ Если все прошло нормально
				l_State = E_GAME_STATE::Game_Start;
				break;
			}
			case E_GAME_STATE::Game_Start:
			{
				//_ Очистка очереди рендеринга
				CRender::instance().ClearSprites();
				// Четыре кнопки рисуем
				SSprite tmp_sprite = { "Menu_Item", 206.0f, 250.0f, 0.f };
				CRender::instance().AddBitmap(tmp_sprite);
				//tmp_sprite = { "Menu_Item", 206.0f, 500.0f, 0.f };
				//CRender::instance().AddBitmap(tmp_sprite);
				//tmp_sprite = { "Menu_Item", 562.0f, 250.0f, 0.f };
				//CRender::instance().AddBitmap(tmp_sprite);
				//tmp_sprite = { "Menu_Item", 562.0f, 500.0f, 0.f };
				//CRender::instance().AddBitmap(tmp_sprite);
				
				
				
				//_ Прорисовка
				CRender::instance().Render();

				
				int x, y;
				//_ Обработка ввода
				if (CInput::instance().GetInput(x, y))
				{
					//CObjectButton button;
					//CObjectButton mouse;
					//button.MoveToPosition(206.f, 250.f);
					//button.SetWH(50.f, 50.f);
					//mouse.MoveToPosition(x, y);
					if (button.IsCollision(mouse))
					{
						l_State = E_GAME_STATE::Game_Person;
					}
					//l_State = E_GAME_STATE::Game_Exit;
				}
				break;
			}
			case E_GAME_STATE::Game_Items:
			{
				//_ Отобразить все собранные и созданные ресурсы
				break;
			}
			case E_GAME_STATE::Game_Person:
			{
				//_ Информация о персонаже 

				//_ Очистка очереди рендеринга
				CRender::instance().ClearSprites();

				//_ Прорисовка
				CRender::instance().Render();
				//_ Обработка ввода
				//al_rest(5);
				int x, y;
				if (CInput::instance().GetInput(x, y))
				{
					l_State = E_GAME_STATE::Game_Exit;
				}
				break;
			}
			case E_GAME_STATE::Game_Kraft:
			{
				//_ Крафтинг вещей
				break;
			}
			case E_GAME_STATE::Game_World:
			{
				//_ Игра (добыча ресурсов)
				break;
			}
			default:
			{
				// Что-то пошло не так...
				l_State = E_GAME_STATE::Game_Exit;
				break;
			}
		}
	}
	return 0;
}