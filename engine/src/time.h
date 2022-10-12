#pragma once

#include <chrono>

namespace glr
{

	class time
	{
	public:

		time();

		void update();

		// Returns time the frame took to render.
		float getDeltaTime() const { return _deltaTime; }

		// Returns elapsed game time.
		float getElapsedTime() const { return _elapsedTime; }

		// Returns Frames per second.
		uint32_t getFPS() const { return (uint32_t)(1 / _deltaTime); }


	private:

		float _elapsedTime, _oldElapsedTime;
		float _deltaTime;
	};

}