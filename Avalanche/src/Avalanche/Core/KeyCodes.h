#pragma once

namespace AVL {

    /* From https://asawicki.info/nosense/doc/devices/keyboard/key_codes.html */
    enum KeyCode {

        Backspace       = 8 ,
        Tab             = 9 ,
        Enter           = 13,
        Shift           = 16,
        Ctrl            = 17,
        Alt             = 18,
        Pause           = 19,
        CapsLock        = 20,
        Esc             = 27,
        Space           = 32,
        PageUp          = 33,
        PageDown        = 34,
        End             = 35,
        Home            = 36,
        Leftarrow       = 37,
        Uparrow         = 38,
        RightArrow      = 39,
        DownArrow       = 40,
        PrintScreen     = 44,
        Insert          = 45,
        Delete          = 46,

        D0              = 48,
        D1              = 49,
        D2              = 50,
        D3              = 51,
        D4              = 52,
        D5              = 53,
        D6              = 54,
        D7              = 55,
        D8              = 56,
        D9              = 57,

        A               = 65,
        B               = 66,
        C               = 67,
        D               = 68,
        E               = 69,
        F               = 70,
        G               = 71,
        H               = 72,
        I               = 73,
        J               = 74,
        K               = 75,
        L               = 76,
        M               = 77,
        N               = 78,
        O               = 79,
        P               = 80,
        Q               = 81,
        R               = 82,
        S               = 83,
        T               = 84,
        U               = 85,
        V               = 86,
        W               = 87,
        X               = 88,
        Y               = 89,
        Z               = 90,


        LeftWin         = 91,
        RightWin        = 92,
        Popup           = 93,

        DN0             = 96,
        DN1             = 97,
        DN2             = 98,
        DN3             = 99,
        DN4             = 100,
        DN5             = 101,
        DN6             = 102,
        DN7             = 103,
        DN8             = 104,
        DN9             = 105,
        DNMult          = 106,
        DNPlus          = 107,
        DNMinus         = 109,
        DNPoint         = 110,
        DNDivide        = 111,

        F1              = 112,
        F2              = 113,
        F3              = 114,
        F4              = 115,
        F5              = 116,
        F6              = 117,
        F7              = 118,
        F8              = 119,
        F9              = 120,
        F10             = 121,
        F11             = 122,
        F12             = 123,

        NumLock         = 144,
        ScrollLock      = 145,
        LeftShift       = 160,
        RightShift      = 161,
        LeftCtrl        = 162,
        RightCtrl       = 163
    };
}