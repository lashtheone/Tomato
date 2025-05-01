#pragma once

#ifdef TMT_PLATFORM_WINDOWS
	#ifdef TMT_BUILD_DLL
		#define TOMATO_API __declspec(dllexport)
	#else
		#define TOMATO_API __declspec(dllimport)
	#endif
#else
	#error Tomato only supports Windows !
#endif

#ifdef TMT_ENABLE_ASSERTS
	#define TMT_ASSERT(x, ...) { if(!(x)) { TMT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define TMT_CORE_ASSERT(x, ...) { if(!(x)) { TMT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TMT_ASSERT(x, ...)
	#define TMT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)