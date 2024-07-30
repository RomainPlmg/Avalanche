#pragma once

#ifdef AVL_PLATFORM_WINDOWS
    #ifdef AVL_BUILD_DLL
        #define AVL_API __declspec(dllexport)
    #else
        #define AVL_API __declspec(dllimport)
    #endif // AVL_BUILD_DLL
#elif AVL_PLATFORM_UNIX
    #ifdef AVL_BUILD_DLL
        #define AVL_API __attribute__ ((visibility ("default")))
    #else
        #define AVL_API
    #endif
#else
    #error Avalanche only support Window
#endif // AVL_PLATFORM_WINDOWS