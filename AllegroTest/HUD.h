#pragma once
#include "ObjectButton.h"

enum class E_HUD_BUTTONS
{
	ButtonNull,		// Нет нажатия
	ButtonExit,		// Выход из программы или возврат в предыдущее меню
	ButtonPersn,
	ButtonItems,
	ButtonWorld,
	ButtonKraft,
};

enum class E_HUD_STATES
{
	StateStart,
	StatePersn,
	StateItems,
	StateWorld,
	StateKraft
};

class CHud
{
public:
	static CHud instance()
	{
		static CHud _instance;
		return _instance;
	}
	void SetCyrrentState(const E_HUD_STATES inNewState) { m_CyrrentState = inNewState; }
	E_HUD_BUTTONS GetActivedButton(const int inMouseX, const int inMouseY) {}
	void GetVisibleButtons(vector<size_t> &ioVector) {
		ioVector.clear();
		switch (m_CyrrentState)
		{
			case E_HUD_STATES::StateStart:
			{
				ioVector.push_back(m_ButtonExit.GetSpriteID());
				break;
			}
		}
	}
private:
	CHud() = default;
	~CHud() = default;
	E_HUD_STATES m_CyrrentState = E_HUD_STATES::StateStart;
	CObjectButton m_ButtonExit;
	CObjectButton m_ButtonPersn;
	CObjectButton m_ButtonItems;
	CObjectButton m_ButtonWorld;
	CObjectButton m_ButtonKraft;
};