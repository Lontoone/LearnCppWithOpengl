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

		for (Layer* layer : m_LayerStack) {
			layer->OnUpdate();
		}

		m_Window->OnUpdate();
	}

}

void Application::OnEvent(Event& e)
{
	EventDispatcher dispatcher(e);
	dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));

	TE_CORE_TRACE("{0}" , e.ToString());

	// handle the event from back to front;
	for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
		(*--it)->OnEvent(e);
		if (e.Handled) {
			break;
		}
	}
}

void Application::PushLayer(Layer* layer)
{
	m_LayerStack.PushLayer(layer);
}

void Application::PushOverlay(Layer* layer)
{
	m_LayerStack.PushOverlay(layer);
}

bool Application::onWindowClosed(WindowCloseEvent& e)
{
	m_running = false;
	return true;
}

