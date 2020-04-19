#pragma once
#include <allegro5/allegro.h>
class CInput
{
public:
	static CInput &instance() {
		static CInput _instance;
		return _instance;
	}
	int GetInput(int &ioMouse_x, int &ioMouse_y);
	~CInput();
private:
	CInput();

	ALLEGRO_MOUSE_STATE m_MouseState;
	ALLEGRO_EVENT_QUEUE *m_Event_Queue = nullptr;
	ALLEGRO_EVENT		m_Event;
};