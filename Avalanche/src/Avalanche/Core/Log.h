#pragma once

namespace AVL {
class AVL_API Log {
   public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return m_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return m_ClientLogger; }

   private:
    static std::shared_ptr<spdlog::logger> m_CoreLogger;
    static std::shared_ptr<spdlog::logger> m_ClientLogger;
};
}  // namespace AVL

#ifdef AVL_DEBUG
// Core log macros
#define AVL_CORE_TRACE(...) ::AVL::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AVL_CORE_INFO(...) ::AVL::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AVL_CORE_WARN(...) ::AVL::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AVL_CORE_ERROR(...) ::AVL::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AVL_CORE_FATAL(...)                                 \
    {                                                       \
        ::AVL::Log::GetCoreLogger()->critical(__VA_ARGS__); \
        AVL_DEBUGBREAK;                                     \
    }

// Client log macros
#define AVL_TRACE(...) ::AVL::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AVL_INFO(...) ::AVL::Log::GetClientLogger()->info(__VA_ARGS__)
#define AVL_WARN(...) ::AVL::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AVL_ERROR(...) ::AVL::Log::GetClientLogger()->error(__VA_ARGS__)
#define AVL_FATAL(...)                                        \
    {                                                         \
        ::AVL::Log::GetClientLogger()->critical(__VA_ARGS__); \
        AVL_DEBUGBREAK;                                       \
    }

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
#define AVL_CORE_TRACE(...)
#define AVL_CORE_INFO(...)
#define AVL_CORE_WARN(...)
#define AVL_CORE_ERROR(...)
#define AVL_CORE_FATAL(...)

#define AVL_TRACE(...)
#define AVL_INFO(...)
#define AVL_WARN(...)
#define AVL_ERROR(...)
#define AVL_FATAL(...)

#define AVL_CORE_ASSERT(x, ...)
#define AVL_ASSERT(x, ...)
#endif