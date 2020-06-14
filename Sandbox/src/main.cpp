#include <stdlib.h>

#include "Anubis-Engine/core/core.hpp"
#include "Anubis-Engine/core/Window.hpp"

#include <glfw/glfw3.h>

int main(void) {

    ABE::Scope<ABE::Window> window = ABE::Window::create(800, 600, "Sandbox");
    
    while (!window->isClosed())
    {
        glfwPollEvents();
    }

    return EXIT_SUCCESS;
}