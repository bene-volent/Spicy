#pragma once

#ifdef SPC_PLATFORM_WINDOWS
	#ifdef SPC_BUILD_DLL
		#define  SPICY_API __declspec(dllexport)
	#else
		#define  SPICY_API __declspec(dllimport)
	#endif
#else
	#error Spicy only Supports windows.
#endif

