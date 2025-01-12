#include "pch.h"
#include "ImGuiLayer.h"
#define IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
//#include "Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "GLFW/glfw3.h"
#include "core/Application.h"
ImGuiLayer::ImGuiLayer() : Layer("ImguiLayer")
{
}

ImGuiLayer::~ImGuiLayer()
{
}

void ImGuiLayer::OnAttach()
{
    ImGui::CreateContext();
    ImGui::StyleColorsDark();


    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    //Application& app = Application::Get();  
    //ImGui_ImplGlfw_InitForOpenGL(app.GetWindow(), true);
    //ImGui_ImplOpenGL3_Init("#version 330");
    ImGui_ImplOpenGL3_Init("#version 410");
}

void ImGuiLayer::OnDetach()
{
}

void ImGuiLayer::OnUpdate()
{

    ImGuiIO& io = ImGui::GetIO();
    Application& app = Application::Get();  
    io.DisplaySize = ImVec2(app.GetWindow().GetWidth() , app.GetWindow().GetHeight());

    
    float time = (float)glfwGetTime();
    io.DeltaTime = m_Time > 0.0? (time-m_Time):(1.0f/60.0f);
    m_Time = time;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiLayer::OnEvent(Event& event)
{
}
