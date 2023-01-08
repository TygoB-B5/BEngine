#pragma once
#include "glm/glm.hpp"

namespace Bonfire
{
	class RenderCommands
	{
	public:

		// Set default renderer settings.
		static void Init();

		// Clear the color and depth buffer.
		static void Clear();

		// Set the clear background color.
		static void ClearColor(const glm::vec4& color);
		static void ClearColor(const glm::vec3& color);
	};
	
}