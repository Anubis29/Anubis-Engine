#ifndef ANUBIS_ENGINE_APPLICATION_HPP
#define ANUBIS_ENGINE_APPLICATION_HPP

#include "Anubis-Engine/core/core.hpp"
#include "Anubis-Engine/core/Window.hpp"

namespace ABE
{



    /**
     * La classe application contient le code de l'execution de la boucle principale de 
     * l'application.
     * Elle est accessible à tout moment avec Application::getInstance()
     *
     */
    class Application
    {
        
    public :
        Application(void);
        virtual ~Application(void);

        static Application* GetInstance(void);
        Window& GetWindow(void);

        void Run(void);

    private :
        static Application* s_Instance;

        Scope<Window> m_Window;
    };
}

#endif // !ANUBIS_ENGINE_APPLICATION_HPP

