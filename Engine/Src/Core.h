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


// Initialize log macros if build configuration is not Distribute.

#if defined(BE_DEBUG) || defined(BE_RELEASE)
	#include "Log.h"
	#define BE_TRACE(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::White, std::string("[TRACE] ") + message);
	#define BE_INFO(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::Green, std::string("[INFO] ") + message);
	#define BE_WARN(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::Yellow, std::string("[WARN] ") + message);
	#define BE_ERROR(message) BEngine::Log::LogMessage(BEngine::Log::LogColor::Red, std::string("[ERROR] ") + message);
	#include <Windows.h>
	#define BE_ASSERT(condition, message)if(!condition) { BEngine::Log::LogMessage(BEngine::Log::LogColor::WhiteOnRed, std::string("[ASSERT] ") + message); DebugBreak(); }
#else
	#define BE_TRACE(message) 
	#define BE_INFO(message)
	#define BE_WARN(message)
	#define BE_ERROR(message) 
	#define BE_ASSERT(message)
	#define BE_ASSERT(condition, message)
#endif


#include <memory>
namespace BEngine
{
	template<class T>
	using ScopePtr = std::unique_ptr<T>;

	template<class T>
	using RefPtr = std::shared_ptr<T>;
}