#pragma once
#include "Core.h"
#include "Windows.h"
#include "events/Event.h"
#include "events/ApplicationEvent.h"

class TE_API Application
{
public:
	Application();
	virtual ~Application() {};

	void Run();
	void OnEvent(Event& e);

	// To be defined in client
	Application* CreateApplication();
private:
	bool onWindowClosed(WindowCloseEvent& e);

	std::unique_ptr<Window> m_Window;
	bool m_running = true;
};

