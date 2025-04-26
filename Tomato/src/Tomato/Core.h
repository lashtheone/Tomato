#pragma once

#ifdef TMT_PLATFORM_WINDOWS
	#ifdef TMT_BUILD_DLL
		#define Tomato_API __declspec(dllexport)
	#else
		#define Tomato_API __declspec(dllimport)

	#endif

#else
	#error Tomato only supports Windows !

#endif