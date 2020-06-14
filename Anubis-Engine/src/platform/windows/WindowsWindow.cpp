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
            window->close();
            });

        glfwMakeContextCurrent(m_pGLFWWindow);
        s_WindowCount++;
    }

    WindowsWindow::~WindowsWindow(void)
    {
        close();
    }

    void WindowsWindow::updateEvents(void) 
    {
        ABE_ASSERT(!isClosed(), "Failed to update events on closed window");
        glfwPollEvents();
    }

    const char* WindowsWindow::getTitle(void) const
    {
        return m_Title.c_str();
    }

    uint WindowsWindow::getWidth(void) const
    {
        return m_Width;
    }

    uint WindowsWindow::getHeight(void) const
    {
        return m_Height;
    }


    void WindowsWindow::setTitle(const char* title) 
    { 
        ABE_ASSERT(!isClosed(), "Cannot rename a closed window!");
        m_Title = std::string(title);
        glfwSetWindowTitle(m_pGLFWWindow, title);
    }

    void WindowsWindow::setWidth(uint width)
    {
        ABE_ASSERT(!isClosed(), "Cannot resize a closed window!");
        m_Width = width;
        glfwSetWindowSize(m_pGLFWWindow, m_Width, m_Height);
    }

    void WindowsWindow::setHeight(uint height)
    {
        ABE_ASSERT(!isClosed(), "Cannot resize a closed window!");
        m_Height = height;
        glfwSetWindowSize(m_pGLFWWindow, m_Width, m_Height);
    }

    bool WindowsWindow::isClosed(void) const {
        return m_pGLFWWindow == nullptr;
    }

    void WindowsWindow::close(void) 
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
}