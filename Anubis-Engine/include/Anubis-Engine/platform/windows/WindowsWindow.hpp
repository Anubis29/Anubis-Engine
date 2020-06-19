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

        static void PollEvents(void);

        virtual const char* Title(void) const override;
        virtual void SetTitle(const char* title) override;

        virtual uint Width(void) const override;
        virtual void SetWidth(uint width) override;

        virtual uint Height(void) const override;
        virtual void SetHeight(uint height) override;

        virtual bool IsClosed(void) const override;
        virtual void Close(void) override;

        virtual void* GetNativeWindow(void) const override;


    private :
        static uint s_WindowCount;

        GLFWwindow* m_pGLFWWindow;

        std::string m_Title;
        uint m_Width;
        uint m_Height;
    };
}

#endif // !ANUBIS_ENGINE_WINDOWSWINDOW_HPP
