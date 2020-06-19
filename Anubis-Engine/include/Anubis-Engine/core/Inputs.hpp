#ifndef ANUBIS_ENGINE_INPUTS_HPP
#define ANUBIS_ENGINE_INPUTS_HPP

#include "Anubis-Engine/core/core.hpp"

namespace ABE 
{
    // Codes pour les touches de la souris
    enum class MouseButton 
    {
        B1 = 0,
        B2 = 1,
        B3 = 2,
        B4 = 3,
        B5 = 4,
        B6 = 5,
        B7 = 6,
        B8 = 7,
        Left = B1,
        Right = B2,
        Middle = B3,
        Last = B8
    };

    enum class Key : uint16_t
    {
        Space             = 32,
        Apostrophe        = 39,  /* ' */
        Comma             = 44,  /* , */
        Minus             = 45,  /* - */
        Period            = 46,  /* . */
        Slash             = 47,  /* / */
        K0                = 48,
        K1                = 49,
        K2                = 50,
        K3                = 51,
        K4                = 52,
        K5                = 53,
        K6                = 54,
        K7                = 55,
        K8                = 56,
        K9                = 57,
        Semicolon         = 59,  /* ; */
        Equal             = 61,  /* = */
        A                 = 65,
        B                 = 66,
        C                 = 67,
        D                 = 68,
        E                 = 69,
        F                 = 70,
        G                 = 71,
        H                 = 72,
        I                 = 73,
        J                 = 74,
        K                 = 75,
        L                 = 76,
        M                 = 77,
        N                 = 78,
        O                 = 79,
        P                 = 80,
        Q                 = 81,
        R                 = 82,
        S                 = 83,
        T                 = 84,
        U                 = 85,
        V                 = 86,
        W                 = 87,
        X                 = 88,
        Y                 = 89,
        Z                 = 90,
        Left_Bracket      = 91,  /* [ */
        Backslash         = 92,  /* \ */
        Right_Bracket     = 93,  /* ] */
        GraveAccent       = 96,  /* ` */
        World1           = 161, /* non-US #1 */
        World2           = 162, /* non-US #2 */
                          
        /* Function keys */
        Escape            = 256,
        Enter             = 257,
        Tab               = 258,
        Backspace         = 259,
        Insert            = 260,
        Delete            = 261,
        Right             = 262,
        Left              = 263,
        Down              = 264,
        Up                = 265,
        PageUp            = 266,
        PageDown          = 267,
        Home              = 268,
        End               = 269,
        CapsLock          = 280,
        ScrollLock        = 281,
        NumLock           = 282,
        PrintScreen       = 283,
        Pause             = 284,
        F1                = 290,
        F2                = 291,
        F3                = 292,
        F4                = 293,
        F5                = 294,
        F6                = 295,
        F7                = 296,
        F8                = 297,
        F9                = 298,
        F10               = 299,
        F11               = 300,
        F12               = 301,
        F13               = 302,
        F14               = 303,
        F15               = 304,
        F16               = 305,
        F17               = 306,
        F18               = 307,
        F19               = 308,
        F20               = 309,
        F21               = 310,
        F22               = 311,
        F23               = 312,
        F24               = 313,
        F25               = 314,
        KP_0              = 320,
        KP_1              = 321,
        KP_2              = 322,
        KP_3              = 323,
        KP_4              = 324,
        KP_5              = 325,
        KP_6              = 326,
        KP_7              = 327,
        KP_8              = 328,
        KP_9              = 329,
        KP_Decimal        = 330,
        KP_Divide         = 331,
        KP_Multiply       = 332,
        KP_Subtract       = 333,
        KP_Add            = 334,
        KP_Enter          = 335,
        KP_Equal          = 336,
        Left_Shift        = 340,
        Left_Control      = 341,
        Left_Alt          = 342,
        LEFT_Super        = 343,
        Right_Shift       = 344,
        Right_Control     = 345,
        Right_Alt         = 346,
        Right_Super       = 347,
        Menu              = 348
    };



    class Input 
    {
    public :
        Input(void) = default;
        virtual ~Input(void);

        static bool GetMouseButton(MouseButton button);
        static bool GetKey(Key key);
        static float GetMouseX(void);
        static float GetMouseY(void);
      //  static float getMouseRelX(void);
       // static float getMouseRelY(void);

    protected :

        virtual bool GetMouseButtonImpl(MouseButton button) = 0;
        virtual bool GetKeyImpl(Key key) = 0;
        virtual float GetMouseXImpl(void) = 0;
        virtual float GetMouseYImpl(void) = 0;
     //   virtual float getMouseRelX(void) = 0;
       // virtual float getMouseRelY(void) = 0;

    private :
        static Scope<Input> Create(void);
        static Scope<Input> s_Instance;
    };
}

#endif // !ANUBIS_ENGINE_INPUTS_HPP

