#pragma once

class CMsgRessiver
{
public:
	static CMsgRessiver &instance() 
	{
		static CMsgRessiver _instance;
		return _instance;
	}

	void Send() {}
	void Get() {}
private:
};