#pragma once

//#include <memory>
#include "spdlog/spdlog.h"
#include "core/Core.h"
class TE_API Log {
public:
	static void Init();
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){return s_CoreLogger;}
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){return s_ClientLogger;}
private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};  

// core log macros
#define TE_CORE_ERROR(...) ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TE_CORE_WARN(...)  ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TE_CORE_INFO(...)  ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TE_CORE_TRACE(...) ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TE_CORE_FATAL(...) ::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define TE_ERROR(...) ::Log::GetClientLogger()->error(__VA_ARGS__)
#define TE_WARN(...)  ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TE_INFO(...)  ::Log::GetClientLogger()->info(__VA_ARGS__)
#define TE_TRACE(...) ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TE_FATAL(...) ::Log::GetClientLogger()->fatal(__VA_ARGS__)
