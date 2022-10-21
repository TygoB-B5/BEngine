#include "Input.h"
#include "Core.h"

namespace BEngine
{
	// Initialize input singleton.
	Input* Input::s_Input = new Input;

	// Initialize bitsets and other static input variables.
	std::bitset<KEYCODE_AMOUNT> Input::s_KeysPressed = std::bitset<KEYCODE_AMOUNT>();
	std::bitset<KEYCODE_AMOUNT> Input::s_KeysRepeating = std::bitset<KEYCODE_AMOUNT>();
	std::bitset<KEYCODE_AMOUNT> Input::s_KeysReleased = std::bitset<KEYCODE_AMOUNT>();

	std::bitset<MOUSECODE_AMOUNT> Input::s_MouseButtonsPressed = std::bitset<MOUSECODE_AMOUNT>();
	std::bitset<MOUSECODE_AMOUNT> Input::s_MouseButtonsRepeating = std::bitset<MOUSECODE_AMOUNT>();
	std::bitset<MOUSECODE_AMOUNT> Input::s_MouseButtonsReleased = std::bitset<MOUSECODE_AMOUNT>();

	int8_t Input::s_ScrollDelta = 0;

	glm::ivec2 Input::s_MousePosition = { 0, 0 };

	void Input::Init()
	{

		GLFWwindow* window = Application::Get()->GetWindow()->GetNativeWindow();

		// Setup key callback.
		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				// Update bitsets accordingly.
				switch (action)
				{
				case 0:
					s_KeysReleased.set(key, 1);
					s_KeysRepeating.set(key, action);
					break;

				case 1:
					s_KeysPressed.set(key, action);
					s_KeysRepeating.set(key, action);
					break;
				}
			});

		// Setup mousebutton callback.
		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods)
			{
				// Update bitsets accordingly.
				switch (action)
				{
				case 0:
					s_MouseButtonsReleased.set(button, 1);
					s_MouseButtonsRepeating.set(button, action);
					break;

				case 1:
					s_MouseButtonsPressed.set(button, action);
					s_MouseButtonsRepeating.set(button, action);
					break;
				}
			});

		// Setup scroll callback.
		glfwSetScrollCallback(window, [](GLFWwindow* window, double xoffset, double yoffset)
			{
				s_ScrollDelta = (int8_t)yoffset;
			});


		// Setup scroll callback.
		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xpos, double ypos)
			{
				s_MousePosition = { xpos, ypos };
			});
	}

	void Input::Flush()
	{
		// Reset all bits in keypresszed to flush keypressed input.
		s_KeysPressed.reset();
		s_KeysReleased.reset();

		s_MouseButtonsPressed.reset();
		s_MouseButtonsReleased.reset();

		s_ScrollDelta = 0;
	}

	bool Input::IsKeyPressed(uint32_t keyCode)
	{
		return s_KeysPressed[keyCode];
	}

	bool Input::IsKeyReleased(uint32_t keyCode)
	{
		return s_KeysReleased[keyCode];
	}

	bool Input::IsKeyHeld(uint32_t keycode)
	{
		return s_KeysRepeating[keycode];
	}

	bool Input::IsMouseButtonPressed(uint32_t button)
	{
		return s_MouseButtonsPressed[button];
	}

	bool Input::IsMouseButtonHeld(uint32_t button)
	{
		return s_MouseButtonsRepeating[button];
	}

	bool Input::IsMouseButtonReleased(uint32_t button)
	{
		return s_MouseButtonsReleased[button];
	}

	int8_t Input::GetScrollDelta()
	{
		return s_ScrollDelta;
	}

	const glm::ivec2& Input::GetMousePosition()
	{
		return s_MousePosition;
	}
}