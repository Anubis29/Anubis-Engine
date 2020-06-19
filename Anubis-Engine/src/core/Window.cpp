#include "Anubis-Engine/core/Window.hpp"

#ifdef ABE_PLATFORM_WINDOWS
#include "Anubis-Engine/platform/windows/WindowsWindow.hpp"
#define ABE_WINDOW_PLATFORM_CLASS WindowsWindow
#endif // ABE_PLATFORM_WINDOWS



namespace ABE
{
    Scope<Window> Window::Create(uint w, uint h, const char *title) 
    {
        return std::make_unique<ABE_WINDOW_PLATFORM_CLASS>(w, h, title);
    }

    void Window::PollEvents(void) {
        ABE_WINDOW_PLATFORM_CLASS::PollEvents();
    }

}