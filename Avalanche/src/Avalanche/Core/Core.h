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
    #error Avalanche does not support this platform
#endif

// Macro for debugger
#ifdef AVL_DEBUG
    #ifdef AVL_PLATFORM_WINDOWS
        #define AVL_DEBUGBREAK __debugbreak()
    #elif AVL_PLATFORM_UNIX
        #include <csignal>
        #define AVL_DEBUGBREAK raise(SIGTRAP)
    #endif
#else
    #define AVL_DEBUGBREAK
#endif
