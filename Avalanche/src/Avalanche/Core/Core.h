#pragma once

#ifdef AVL_PLATFORM_WINDOWS
#ifdef AVL_BUILD_DLL
#define AVL_API __declspec(dllexport)
#else
#define AVL_API __declspec(dllimport)
#endif  // AVL_BUILD_DLL
#elif AVL_PLATFORM_UNIX
#ifdef AVL_BUILD_DLL
#define AVL_API __attribute__((visibility("default")))
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
#ifdef AVL_ENABLE_ASSERTS
#define AVL_CORE_ASSERT(x, ...)                              \
    if (!(x)) {                                              \
        AVL_CORE_FATAL("Assertion failed: {0}", __VA_ARGS__) \
    }
#define AVL_ASSERT(x, ...)                              \
    if (!(x)) {                                         \
        AVL_FATAL("Assertion failed: {0}", __VA_ARGS__) \
    }
#else
#define AVL_CORE_ASSERT(x, ...)
#define AVL_ASSERT(x, ...)
#endif
#else
#define AVL_DEBUGBREAK
#define AVL_CORE_ASSERT(x, ...) x;
#define AVL_ASSERT(x, ...) x;
#endif

#define AVL_BIND_EVENT_FN(fn)                                   \
    [this](auto&&... args) -> decltype(auto) {                  \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }
