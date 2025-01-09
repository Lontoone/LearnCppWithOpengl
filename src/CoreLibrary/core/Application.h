#pragma once
#include "Core.h"
class TE_API Application
{
public:
	Application() {};
	virtual ~Application() {};

	void Run();

	// To be defined in client
	Application* CreateApplication();
private:
	
};

