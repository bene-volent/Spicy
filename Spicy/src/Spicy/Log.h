#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Spicy
{

	class SPICY_API Log
	{
	public:
		
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros

#define SPC_CORE_ERROR(...)	Spicy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SPC_CORE_INFO(...)	Spicy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SPC_CORE_TRACE(...) Spicy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SPC_CORE_WARN(...)	Spicy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SPC_CORE_FATAL(...) Spicy::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros

#define SPC_ERROR(...)	Spicy::Log::GetClientLogger()->error(__VA_ARGS__)
#define SPC_INFO(...)	Spicy::Log::GetClientLogger()->info(__VA_ARGS__)
#define SPC_TRACE(...)	Spicy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SPC_WARN(...)	Spicy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SPC_FATAL(...)	Spicy::Log::GetClientLogger()->critical(__VA_ARGS__)


