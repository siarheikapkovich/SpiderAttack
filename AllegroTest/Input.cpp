#include "Input.h"

CInput::CInput()
{
	m_Event_Queue = al_create_event_queue();
#if _WIN32
	al_install_mouse();
	al_register_event_source(m_Event_Queue, al_get_mouse_event_source());
#else
	// Под Android нужен touch
	al_install_touch_input();
	al_register_event_source(m_Event_Queue, al_get_touch_input_event_source());
#endif
}

CInput::~CInput()
{
#if _WIN32
	al_uninstall_mouse();
#else
	al_uninstall_touch_input();
#endif
	al_destroy_event_queue(m_Event_Queue);
}

int CInput::GetInput(int &ioMouse_x, int &ioMouse_y)
{
	al_get_mouse_state(&m_MouseState);
	ioMouse_x = m_MouseState.x;
	ioMouse_y = m_MouseState.y;
	if (m_MouseState.buttons & 1)
	{
		// Нажатие кнопки
		return 1;
	}
	else
		return 0;
}