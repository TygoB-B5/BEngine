#pragma once
#include "bepch.h"

namespace BEngine
{

	class Log
	{
	public:

		// Type define tm to LocalTime to make code more readable.
		typedef tm LocalTime;

		// Types of logs that are possible to log
		// LogColor values are the windows console color id's.
		enum class LogColor
		{
			White = 0x0F,
			Blue = FOREGROUND_BLUE,
			Green = FOREGROUND_GREEN,
			Red = FOREGROUND_RED,
			Purple = 0x05,
			Yellow = 0x06,
			WhiteOnRed = 0x0F | BACKGROUND_RED,
		};

		Log();

		// Logs a message in the console with a specified LogType.
		static void LogMessage(LogColor type, const std::string& message)
		{
			s_Instance->LogMessageImpl(type, message);
		}

		static void Init()
		{
			s_Instance->InitImpl();
		}

	private:

		// Initializes the log system.
		void InitImpl();

		// Member implementation of LogMessage
		void LogMessageImpl(LogColor type, const std::string& message);

		// Formats the time values so they look pretty.
		inline std::string FormatTime(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minutes, uint32_t seconds, uint32_t milliseconds);
		
		// Return LocalTime object with local time variables.
		inline LocalTime GetSystemTime(const std::chrono::system_clock::time_point& timePoint);

		// Returns the amount of milliseconds that have passed in the current second.
		inline uint32_t GetMillisecondsInCurrentSecond(const std::chrono::system_clock::time_point& timePoint);

	private:

		// Singleton
		static Log* s_Instance;

		LogColor m_LastLogColor;
		HANDLE m_ConsoleHandle;
		bool m_Initialized;

	};
}