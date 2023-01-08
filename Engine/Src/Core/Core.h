#pragma once

// Create engine specific macros for configuration types.

#ifdef _DEBUG
	#define BF_DEBUG
#endif

#ifdef _RELEASE
	#define BF_RELEASE
#endif

#ifdef _DISTRIBUTE
	#define BF_DISTRIBUTE
#endif


#include <Windows.h>

// Initialize log macros if build configuration is not Distribute.

#if !defined(BF_DISTRIBUTE)

	#include "Utils/Log.h"

	#define BF_TRACE(message) Bonfire::Log::LogMessage(Bonfire::Log::LogColor::White, std::string("[TRACE] ") + message);
	#define BF_INFO(message) Bonfire::Log::LogMessage(Bonfire::Log::LogColor::Green, std::string("[INFO] ") + message);
	#define BF_WARN(message) Bonfire::Log::LogMessage(Bonfire::Log::LogColor::Yellow, std::string("[WARN] ") + message);
	#define BF_ERROR(message) Bonfire::Log::LogMessage(Bonfire::Log::LogColor::Red, std::string("[ERROR] ") + message);
	#define BF_NOTIF(message) Bonfire::Log::LogMessage(Bonfire::Log::LogColor::Purple, std::string("[NOTIF] ") + message);
	#define BF_ASSERT(condition, message)if(!condition) { Bonfire::Log::LogMessage(Bonfire::Log::LogColor::WhiteOnRed, std::string("[ASSERT] ") + message); DebugBreak(); }
#else
	#define BF_TRACE(message) ;;
	#define BF_INFO(message)  ;;
	#define BF_WARN(message)  ;;
	#define BF_ERROR(message) ;;
	#define BF_NOTIF(message) ;;
	#define BF_ASSERT(condition, message) ;;
#endif


// Define free console macro if the config type is distribute, this macro removes the console from the application.

#ifdef BF_DISTRIBUTE
	#define SHOW_CONSOLE() ShowWindow(GetConsoleWindow(), FALSE); FreeConsole();
#else
	#define SHOW_CONSOLE() ShowWindow(GetConsoleWindow(), TRUE);
#endif

// Typedef used to make the definition of shared and unique ptr more clear.

#include <memory>
namespace Bonfire
{
	template<class T>
	using ScopePtr = std::unique_ptr<T>;

	template<class T>
	using RefPtr = std::shared_ptr<T>;
}


// Defined to make FreeImage bit arrangement RGB instead of BGR
#define FREEIMAGE_COLORORDER FREEIMAGE_COLORORDER_RGB