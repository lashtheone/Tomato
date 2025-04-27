#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Tomato {

	class TOMATO_API Log
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


// Core Log macros
#define TMT_CORE_TRACE(...)  ::Tomato::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TMT_CORE_INFO(...)   ::Tomato::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TMT_CORE_WARN(...)   ::Tomato::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TMT_CORE_ERROR(...)  ::Tomato::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TMT_CORE_FATAL(...)  ::Tomato::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log macros
#define TMT_TRACE(...)       ::Tomato::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TMT_INFO(...)        ::Tomato::Log::GetClientLogger()->info(__VA_ARGS__)
#define TMT_WARN(...)        ::Tomato::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TMT_ERROR(...)       ::Tomato::Log::GetClientLogger()->error(__VA_ARGS__)
#define TMT_FATAL(...)       ::Tomato::Log::GetClientLogger()->fatal(__VA_ARGS__)