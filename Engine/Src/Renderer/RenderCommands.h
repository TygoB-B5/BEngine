#pragma once
#include "glm/glm.hpp"

namespace BEngine
{
	class RenderCommands
	{
	public:
		static void Clear(const glm::vec4& color);
		static void Clear(const glm::vec3& color);

		static void DrawElements(uint32_t size);
	};
	
}