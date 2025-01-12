#pragma once
#include "Core.h"
#include "Windows.h"
#include "core/LayerStack.h"
#include "events/Event.h"
#include "events/ApplicationEvent.h"

class TE_API Application
{
public:
	Application();
	virtual ~Application() {};

	void Run();
	void OnEvent(Event& e);

	void PushLayer(Layer* layer);
	void PushOverlay(Layer* layer);

	inline Window& GetWindow(){return *m_Window;}
	inline static Application& Get(){return *s_Instance;}

	// To be defined in client
	Application* CreateApplication();
private:
	bool onWindowClosed(WindowCloseEvent& e);

	std::unique_ptr<Window> m_Window;
	bool m_running = true;
	LayerStack m_LayerStack;
	static Application* s_Instance;
};

