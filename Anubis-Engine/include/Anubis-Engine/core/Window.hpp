#ifndef ANUBIS_ENGINE_WINDOW_HPP
#define ANUBIS_ENGINE_WINDOW_HPP

#include "Anubis-Engine/core/core.hpp"
#include <string>

namespace ABE
{

    class Window
    {
    public:
        static Scope<Window> create(uint w, uint h, const char* title);
        static void pollEvents(void);

        virtual ~Window(void) = default;


        virtual const char* getTitle(void) const = 0;
        virtual void setTitle(const char* title) = 0;

        virtual uint getWidth(void) const = 0;
        virtual void setWidth(uint width) = 0;

        virtual uint getHeight(void) const = 0;
        virtual void setHeight(uint height) = 0;

        virtual bool isClosed(void) const = 0;
        virtual void close(void) = 0;
    };
}

#endif // !ANUBIS_ENGINE_WINDOW_HPP