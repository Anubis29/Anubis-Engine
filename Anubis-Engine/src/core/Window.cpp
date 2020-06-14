#include "Anubis-Engine/core/Window.hpp"

#ifdef ABE_PLATFORM_WINDOWS
#include "Anubis-Engine/platform/windows/WindowsWindow.hpp"
#endif // ABE_PLATFORM_WINDOWS


namespace ABE
{
    Scope<Window> Window::create(uint w, uint h, const char *title) 
    {
        #ifdef ABE_PLATFORM_WINDOWS
        return std::make_unique<WindowsWindow>(w, h, title);
        #endif  
    }
}