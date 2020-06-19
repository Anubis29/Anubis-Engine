#include "Anubis-Engine/core/Application.hpp"
#include "Anubis-Engine/core/core.hpp"

namespace ABE 
{
    Application* Application::s_Instance = nullptr;

    Application* Application::GetInstance(void) { return Application::s_Instance; }

    Application::Application(void) : m_Window(nullptr)
    {
        ABE_ASSERT(s_Instance == nullptr, "Failed to create an Application. Another applmication was already created!");
        
        s_Instance = this;
    }

    Application::~Application(void) 
    {
        s_Instance = nullptr;
    }

    void Application::Run(void)
    {
        m_Window = Window::Create(800, 600, "Anubis_Engine");

        Window::PollEvents();
        while (!m_Window->IsClosed())
        {
            

            Window::PollEvents();
        }

    }

    Window& Application::GetWindow(void) {
        return *m_Window;
    }

}