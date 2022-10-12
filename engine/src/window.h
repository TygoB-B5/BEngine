#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace glr
{

	class window
	{

	public:

		// Creates the window.
		window(uint32_t width, uint32_t height, const char* name, bool isVsync = true);

		// Returns the GLFWwindow ptr.
		GLFWwindow* getGlfwWindow() const { return _window; }

		// Returns window width.
		uint32_t getWidth() const { return _width; }

		// Returns window height.
		uint32_t getHeight() const { return _height; }

		// Returns if the window has been closed.
		bool shouldClose() const;

		// Updates the GLFWwindow.
		void update() const;

		// Enable and disable vertical sync.
		void setVsync(bool enabled) const;

	private:

		GLFWwindow* _window;

		uint32_t _width;
		uint32_t _height;
	};

}