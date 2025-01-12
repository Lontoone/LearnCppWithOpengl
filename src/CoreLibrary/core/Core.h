#pragma once

#ifdef TE_PLATFORM_WINDOES
	#ifdef TE_BUILD_DLL
		#define TE_API __declspec(dllexport)
	#else
		#define TE_API __declspec(dllimport)
	#endif // TE_BUILD_DLL

#else
	#error Only support Windows
#endif // TE_PLATFORM_WINDOES

#define BIT(x) (1<<x)