#pragma once
#include "bepch.h"

namespace BEngine
{

	class Time
	{
	public:

		Time();

		// Tick application time.
		static void Tick() { s_Time->TickImpl(); }

		// Return time between this and the last frames.
		static float GetDeltaTime() { return s_Time->m_DeltaTime; }

		// Return total elapsed time since application start.
		static float GetElapsedTime() { return s_Time->m_ElapsedTime; }

		// Return frames per second.
		static uint32_t GetFPS() { return (uint32_t)(1 / s_Time->m_DeltaTime); }

	private:
		void TickImpl();

	private:
		float m_ElapsedTime, m_OldElapsedTime;
		float m_DeltaTime;

		static Time* s_Time;
	};

}