#pragma once

#ifndef SPC_LOG_H_
#define SPC_LOG_H_


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

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


#if defined (SPC_DEBUG)|| defined (SPC_RELEASE)
// FOR DEBUG OR RELEASE CONFIGURATION
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

#else
// FOR DISTRIBUTION CONFIGURATION
	#define SPC_CORE_ERROR(...)	
	#define SPC_CORE_INFO(...)	
	#define SPC_CORE_TRACE(...) 
	#define SPC_CORE_WARN(...)	
	#define SPC_CORE_FATAL(...) 

	// Client Log Macros

	#define SPC_ERROR(...)	
	#define SPC_INFO(...)	
	#define SPC_TRACE(...)	
	#define SPC_WARN(...)	
	#define SPC_FATAL(...)	

#endif
#endif
