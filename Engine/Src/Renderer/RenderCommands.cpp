#include "RenderCommands.h"
#include "glad/glad.h"

namespace BEngine
{

	void RenderCommands::Clear(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void RenderCommands::Clear(const glm::vec3& color)
	{
		Clear({ color.r, color.g, color.b, 1.0f });
	}

	void RenderCommands::DrawElements(uint32_t size)
	{
		glDrawElements(GL_TRIANGLES, size, GL_UNSIGNED_INT, 0);
	}
}