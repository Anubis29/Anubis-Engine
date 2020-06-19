#ifndef ABE_WINDOWS_INPUTS_HPP
#define ABE_WINDOWS_INPUTS_HPP

#include "Anubis-Engine/core/core.hpp"
#include "Anubis-Engine/core/Inputs.hpp"
#include "Anubis-Engine/core/Application.hpp"
#include <GLFW/glfw3.h>

#define ABE_GLFW_WINDOW_PTR reinterpret_cast<GLFWwindow*>(Application::GetInstance()->GetWindow().GetNativeWindow())

namespace ABE
{
    class WindowsInput : public Input
    {

    protected :
        virtual bool GetMouseButtonImpl(MouseButton button) override
        {
            return static_cast<bool>(glfwGetMouseButton(ABE_GLFW_WINDOW_PTR, static_cast<int>(button)));
        }

        virtual bool GetKeyImpl(Key key) override 
        {
            return static_cast<bool>(glfwGetKey(ABE_GLFW_WINDOW_PTR, static_cast<int>(key)));
        }

        virtual float GetMouseXImpl(void) override
        {
            double x, y;
            glfwGetCursorPos(ABE_GLFW_WINDOW_PTR, &x, &y);
            return static_cast<float>(x);
        }
        
        virtual float GetMouseYImpl(void) override
        {
            double x, y;
            glfwGetCursorPos(ABE_GLFW_WINDOW_PTR, &x, &y);
            return static_cast<float>(y);
        }

    };
}

#endif // !ABE_WINDOWS_INPUTS_HPP
