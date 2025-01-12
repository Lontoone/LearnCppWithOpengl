#include "Application.h"
//#include "events/Event.h"
#include "GLFW/glfw3.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
Application::Application()
{
	m_Window = std::unique_ptr< Window>(Window::Create());
	m_Window->SetEventCallback(
		BIND_EVENT_FN(OnEvent)
	);
}
void Application::Run()
{
	WindowResizeEvent e(1280,720);
	if(e.IsInCategory(EventCategoryApplication)){
		TE_TRACE(e.ToString());
	}
	if(e.IsInCategory(EventCategoryInput)){
		TE_TRACE(e.ToString());
	}


	while (m_running)
	{
		glClearColor(1,0,1,1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}

}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));

	TE_INFO("{0}" , e.ToString());
}

bool Application::onWindowClosed(WindowCloseEvent& e)
{
	m_running = false;
	return true;
}

