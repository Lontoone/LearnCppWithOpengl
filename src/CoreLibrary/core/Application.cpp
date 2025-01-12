#include "Application.h"

#include "GLFW/glfw3.h"
Application::Application()
{
	m_Window = std::unique_ptr< Window>(Window::Create());
}
void Application::Run()
{
	while (m_running)
	{
		glClearColor(1,0,1,1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->OnUpdate();
	}

}

