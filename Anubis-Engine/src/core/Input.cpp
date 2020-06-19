#include "Anubis-Engine/core/Inputs.hpp"

#ifdef ABE_PLATFORM_WINDOWS
#include "Anubis-Engine/platform/windows/WindowsInput.hpp"
#endif // ABE_PLATFORM_WINDOWS

namespace ABE
{
    Scope<Input> Input::s_Instance = Input::Create();

    Scope<Input> Input::Create(void) 
    {
        #ifdef ABE_PLATFORM_WINDOWS
        return std::make_unique<WindowsInput>();
        #endif // ABE_PLATFORM_WINDOWS
    }

    Input::~Input(void) { }

    bool Input::GetMouseButton(MouseButton button) {
        return s_Instance->GetMouseButtonImpl(button);
    }

    bool Input::GetKey(Key key) {
        return s_Instance->GetKeyImpl(key);
    }

    float Input::GetMouseX(void) {
        return s_Instance->GetMouseXImpl();
    }

    float Input::GetMouseY(void) {
        return s_Instance->GetMouseYImpl();
    }

}
