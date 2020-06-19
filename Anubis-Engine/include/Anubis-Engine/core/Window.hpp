#ifndef ANUBIS_ENGINE_WINDOW_HPP
#define ANUBIS_ENGINE_WINDOW_HPP

#include "Anubis-Engine/core/core.hpp"
#include <string>

namespace ABE
{

    class Window
    {
    public:
        static Scope<Window> Create(uint w, uint h, const char* title);
        static void PollEvents(void);

        virtual ~Window(void) = default;


        virtual const char* Title(void) const = 0;
        virtual void SetTitle(const char* title) = 0;

        virtual uint Width(void) const = 0;
        virtual void SetWidth(uint width) = 0;

        virtual uint Height(void) const = 0;
        virtual void SetHeight(uint height) = 0;

        virtual bool IsClosed(void) const = 0;
        virtual void Close(void) = 0;

        virtual void* GetNativeWindow(void) const = 0;
    };
}

#endif // !ANUBIS_ENGINE_WINDOW_HPP