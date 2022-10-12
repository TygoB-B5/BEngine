#pragma once

#include "core.h"
#include "GLFW/glfw3.h"

#ifdef GLR_DEBUG
	#define GLR_PROFILE_START glr::profiler p;
	#define GLR_PROFILE_GET(message) GLR_LOG(message << p.stop())
#else
	#define GLR_PROFILE_START
	#define GLR_PROFILE_GET(message)
#endif

namespace glr
{

	class profiler
	{
	public:

		profiler()
		{
			// Set start time when creating this object.
			_startTime = (float)glfwGetTime();
		}

		float stop()
		{
			// Set the stop time and return the amount of time between the creation and destruction of this object
			float startTime = _startTime;
			_endTime = (float)glfwGetTime();
			_startTime = _endTime;
			return (_endTime - startTime) * 1000;
		}


	private:

		float _startTime;
		float _endTime;
	};
}