/*
 * ��
*/
#include "HUD.h"
#include "Input.h"
#include "Render.h"
//#include "GameObject.h"

enum class E_GAME_STATE
{
	Game_Init,		// ������������� ��������� � �������� ��������
	Game_Start,		// ��������� (�������) ����
	Game_Items,		// ���� ��������� ����� (��������) ���������
	Game_Person,	// �������� � ��������� ������������� ���������
	Game_Kraft,		// �������� ������� � �����
	Game_World,		// ��� ����
	Game_Exit		// ���������� � �����
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
				//_ ������������� ��������
				al_init();
				//_ ����� �������� � ������� :)
				CRender::instance().LoadTextures();
				
				//_ ���� ��� ������ ���������
				l_State = E_GAME_STATE::Game_Start;
				break;
			}
			case E_GAME_STATE::Game_Start:
			{
				//_ ������� ������� ����������
				CRender::instance().ClearSprites();
				// ������ ������ ������
				SSprite tmp_sprite = { "Menu_Item", 206.0f, 250.0f, 0.f };
				CRender::instance().AddBitmap(tmp_sprite);
				//tmp_sprite = { "Menu_Item", 206.0f, 500.0f, 0.f };
				//CRender::instance().AddBitmap(tmp_sprite);
				//tmp_sprite = { "Menu_Item", 562.0f, 250.0f, 0.f };
				//CRender::instance().AddBitmap(tmp_sprite);
				//tmp_sprite = { "Menu_Item", 562.0f, 500.0f, 0.f };
				//CRender::instance().AddBitmap(tmp_sprite);
				
				
				
				//_ ����������
				CRender::instance().Render();

				
				int x, y;
				//_ ��������� �����
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
				//_ ���������� ��� ��������� � ��������� �������
				break;
			}
			case E_GAME_STATE::Game_Person:
			{
				//_ ���������� � ��������� 

				//_ ������� ������� ����������
				CRender::instance().ClearSprites();

				//_ ����������
				CRender::instance().Render();
				//_ ��������� �����
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
				//_ �������� �����
				break;
			}
			case E_GAME_STATE::Game_World:
			{
				//_ ���� (������ ��������)
				break;
			}
			default:
			{
				// ���-�� ����� �� ���...
				l_State = E_GAME_STATE::Game_Exit;
				break;
			}
		}
	}
	return 0;
}