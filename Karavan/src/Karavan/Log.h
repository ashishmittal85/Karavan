#ifndef LOG_H
#define LOG_H

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Karavan
{
    class KARAVAN_API Log
    {
    public:
        Log();
        ~Log();
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

// Core log macros
#define KV_CORE_TRACE(...)    ::Karavan::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define KV_CORE_INFO(...)     ::Karavan::Log::GetCoreLogger()->info(__VA_ARGS__)
#define KV_CORE_WARN(...)     ::Karavan::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define KV_CORE_ERROR(...)    ::Karavan::Log::GetCoreLogger()->error(__VA_ARGS__)
#define KV_CORE_FATAL(...)    ::Karavan::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define KV_TRACE(...)    ::Karavan::Log::GetClientLogger()->trace(__VA_ARGS__)
#define KV_INFO(...)     ::Karavan::Log::GetClientLogger()->info(__VA_ARGS__)
#define KV_WARN(...)     ::Karavan::Log::GetClientLogger()->warn(__VA_ARGS__)
#define KV_ERROR(...)    ::Karavan::Log::GetClientLogger()->error(__VA_ARGS__)
#define KV_FATAL(...)    ::Karavan::Log::GetClientLogger()->fatal(__VA_ARGS__)

#ifdef KV_ENABLE_ASSERTS
    #define KV_ASSERT(x, ...) { if(!(x)) { KV_ERROR("Assertion failed: {0}", __VA_ARGS__); __builtin_trap(); } }
    #define KV_CORE_ASSERT(x, ...) { if(!(x)) { KV_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __builtin_trap(); } }
#else
    #define KV_ASSERT(x, ...)
    #define KV_CORE_ASSERT(x, ...)
#endif


#endif