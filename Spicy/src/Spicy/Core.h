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

#endif

#define BIT(X) (1 << X)

#ifdef SPC_ENABLE_ASSERTS
#define SPC_CORE_ASSERT(x,...) { if (!(x)) {SPC_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#define SPC_ASSERT(x,...) { if (!(x)) {SPC_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__);__debugbreak();}}
#else
#define SPC_ASSERT(x,...)
#define SPC_CORE_ASSERT(x,...)
#endif
