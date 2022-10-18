#pragma once

// Create engine specific macros for configuration types.

#ifdef _DEBUG
	#define BE_DEBUG
#endif

#ifdef _RELEASE
	#define BE_RELEASE
#endif

#ifdef _DISTRIBUTE
	#define BE_DISTRIBUTE
#endif


#include <Windows.h>

// Initialize log macros if build configuration is not Distribute.

#if !defined(BE_DISTRIBUTE)
	#include "Log.h"
	#define BE_TRACE(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::White, std::string("[TRACE] ") + message);
	#define BE_INFO(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::Green, std::string("[INFO] ") + message);
	#define BE_WARN(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::Yellow, std::string("[WARN] ") + message);
	#define BE_ERROR(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::Red, std::string("[ERROR] ") + message);
	#define BE_ASSERT(condition, message)if(!condition) { BEngine::Log::LogMessage(BEngine::Log::LogColor::WhiteOnRed, std::string("[ASSERT] ") + message); DebugBreak(); }
#else
	#define BE_TRACE(message) 
	#define BE_INFO(message)
	#define BE_WARN(message)
	#define BE_ERROR(message) 
	#define BE_ASSERT(condition, message)
#endif


// Define free console macro if the config type is distribute, this macro removes the console from the application.

#ifdef BE_DISTRIBUTE
	#define SHOW_CONSOLE() ShowWindow(GetConsoleWindow(), FALSE); FreeConsole();
#else
	#define SHOW_CONSOLE() ShowWindow(GetConsoleWindow(), TRUE);
#endif

#include <memory>
namespace BEngine
{
	template<class T>
	using ScopePtr = std::unique_ptr<T>;

	template<class T>
	using RefPtr = std::shared_ptr<T>;
}