#pragma once
#include "Core.h"
#include "Windows.h"
class TE_API Application
{
public:
	Application();
	virtual ~Application() {};

	void Run();

	// To be defined in client
	Application* CreateApplication();
private:
	std::unique_ptr<Window> m_Window;
	bool m_running = true;
};

