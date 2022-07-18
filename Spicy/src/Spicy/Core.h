#pragma once


#ifndef SPC_CORE_H_
#define SPC_CORE_H_

#ifdef SPC_PLATFORM_WINDOWS
	#ifdef SPC_BUILD_DLL
		#define  SPICY_API __declspec(dllexport)
	#else
		#define  SPICY_API __declspec(dllimport)
	#endif
#else
	#error Spicy only Supports windows.
#endif

#define BIT(X) (1 << X)
#endif