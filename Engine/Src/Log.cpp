#include "Log.h"

namespace BEngine
{

	Log* Log::s_Instance = new Log;

	void Log::LogMessageImpl(LogColor color, const std::string& message)
	{
		
		// Get current time point before doing anything else as to make the log time as accurate as possible.
		std::chrono::system_clock::time_point now = std::chrono::system_clock::now();

		// Get required time values.
		uint32_t milliseconds = GetMillisecondsInCurrentSecond(now);
		LocalTime localTime = GetSystemTime(now);

		// Ignore color update if last message was the same color.
		if (color != m_LastLogColor)
		{
			m_LastLogColor = color;

			// Sets the text color of the messages printed next.
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (uint8_t)color);
		}

		// Prints the log message in the console.
		std::cout << FormatTime(
			localTime.tm_year, 
			localTime.tm_mon,
			localTime.tm_mday,
			localTime.tm_hour,
			localTime.tm_min,
			localTime.tm_sec,
			milliseconds)
			+ ' ' + message + '\n';
	}

	std::string Log::FormatTime(uint32_t year, uint32_t month, uint32_t day, uint32_t hour, uint32_t minutes, uint32_t seconds, uint32_t milliseconds)
	{
		std::ostringstream date;

		// Format the time in to a good looking string.
		date << year << '-' << month << '-' << day << ' '
			<< hour << ':' << minutes << ':' << seconds << ':' << std::setfill('0') << std::setw(4) << milliseconds;

		return date.str();
	}

	Log::LocalTime Log::GetSystemTime(const std::chrono::system_clock::time_point& timePoint)
	{
		using namespace std::chrono;

		// Convert current time point to time_t
		time_t tTime = system_clock::to_time_t(timePoint);

		// Fill local_tm container with local time data.
		tm localTime;
		localtime_s(&localTime, &tTime);

		// Calculation done to account for apoch.
		localTime.tm_year += 1900;

		// Calculation done to account for month starting at 0 instead of 1.
		localTime.tm_mon += 1;

		return localTime;
	}

	uint32_t Log::GetMillisecondsInCurrentSecond(const std::chrono::system_clock::time_point& timePoint)
	{
		return (uint32_t)std::chrono::duration_cast<std::chrono::milliseconds>(timePoint.time_since_epoch()).count() % 1000;
	}
}