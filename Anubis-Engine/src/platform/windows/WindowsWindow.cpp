#include "Anubis-Engine/platform/windows/WindowsWindow.hpp"

namespace ABE
{
    // GLFW lifetime managment 
    uint WindowsWindow::s_WindowCount = 0;

    WindowsWindow::WindowsWindow(uint w, uint h, const char* title) : m_Title(title), m_Width(w), m_Height(h), m_pGLFWWindow(nullptr)
    {
        if (s_WindowCount == 0)
        {
            int initResult = glfwInit();
            ABE_ASSERT(initResult == GLFW_TRUE, "Failed to init GLFW!")
        }

        m_pGLFWWindow = glfwCreateWindow(w, h, title, nullptr, nullptr);
        ABE_ASSERT(m_pGLFWWindow != nullptr, "Failed to create window!")
        glfwSetWindowUserPointer(m_pGLFWWindow, this);

        glfwSetWindowCloseCallback(m_pGLFWWindow, [](GLFWwindow* pWindow) {
            WindowsWindow* window = reinterpret_cast<WindowsWindow*>(glfwGetWindowUserPointer(pWindow));
            window->Close();
            });

        glfwMakeContextCurrent(m_pGLFWWindow);
        s_WindowCount++;
    }

    WindowsWindow::~WindowsWindow(void)
    {
        Close();
    }

    void WindowsWindow::PollEvents(void)
    {
        ABE_ASSERT(s_WindowCount != 0, "Failed to update events. GLFW is not initialized!");
        glfwPollEvents();
    }

    const char* WindowsWindow::Title(void) const
    {
        return m_Title.c_str();
    }

    uint WindowsWindow::Width(void) const {  return m_Width; }
    uint WindowsWindow::Height(void) const { return m_Height; }


    void WindowsWindow::SetTitle(const char* title) 
    { 
        ABE_ASSERT(!IsClosed(), "Cannot rename a closed window!");
        m_Title = std::string(title);
        glfwSetWindowTitle(m_pGLFWWindow, title);
    }

    void WindowsWindow::SetWidth(uint width)
    {
        ABE_ASSERT(!IsClosed(), "Cannot resize a closed window!");
        m_Width = width;
        glfwSetWindowSize(m_pGLFWWindow, m_Width, m_Height);
    }

    void WindowsWindow::SetHeight(uint height)
    {
        ABE_ASSERT(!IsClosed(), "Cannot resize a closed window!");
        m_Height = height;
        glfwSetWindowSize(m_pGLFWWindow, m_Width, m_Height);
    }

    bool WindowsWindow::IsClosed(void) const {
        return m_pGLFWWindow == nullptr;
    }

    void WindowsWindow::Close(void) 
    {
        if (m_pGLFWWindow != nullptr) 
        {
            glfwDestroyWindow(m_pGLFWWindow);
            m_pGLFWWindow = nullptr; 
            s_WindowCount -= 1;

            if (s_WindowCount == 0) {
                glfwTerminate();
            }
        }
    }

    void* WindowsWindow::GetNativeWindow(void) const {
        return m_pGLFWWindow;
    }

}