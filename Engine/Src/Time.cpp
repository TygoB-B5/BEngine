#include "Time.h"
#include "GLFW/glfw3.h"

namespace BEngine
{
	// Create singleton instance.
	Time* Time::s_Time = new Time;

	Time::Time()
		: m_DeltaTime(0), m_ElapsedTime(0), m_OldElapsedTime(0)
	{}

	void Time::TickImpl()
	{

		// Get current glfw time.
		m_ElapsedTime = (float)glfwGetTime();

		// Update deltaTime;
		m_DeltaTime = m_ElapsedTime - m_OldElapsedTime;

		// Sync old and new elapsed time.
		m_OldElapsedTime = m_ElapsedTime;
	}
}