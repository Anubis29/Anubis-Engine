#ifndef ANUBIS_ENGINE_WINDOWSWINDOW_HPP
#define ANUBIS_ENGINE_WINDOWSWINDOW_HPP

#include "Anubis-Engine/core/Window.hpp"
#include <GLFW/glfw3.h>

namespace ABE
{
    class WindowsWindow : public Window 
    {  
    public :
        WindowsWindow(uint w, uint h, const char *title);
        virtual ~WindowsWindow(void);

        static void pollEvents(void);

        virtual const char* getTitle(void) const override;
        virtual void setTitle(const char* title) override;

        virtual uint getWidth(void) const override;
        virtual void setWidth(uint width) override;

        virtual uint getHeight(void) const override;
        virtual void setHeight(uint height) override;

        virtual bool isClosed(void) const override;
        virtual void close(void) override;

    private :
        static uint s_WindowCount;

        GLFWwindow* m_pGLFWWindow;

        std::string m_Title;
        uint m_Width;
        uint m_Height;
    };
}

#endif // !ANUBIS_ENGINE_WINDOWSWINDOW_HPP
