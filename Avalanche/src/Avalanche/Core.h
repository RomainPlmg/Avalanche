#pragma once

#ifdef AVL_PLATFORM_WINDOWS
#ifdef AVL_BUILD_DLL
#define AVL_API __declspec(dllexport)
#else
#define AVL_API __declspec(dllimport)
#endif // AVL_BUILD_DLL
#else
#error Avalanche only support Window
#endif // AVL_PLATFORM_WINDOWS