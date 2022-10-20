#include "RenderCommands.h"
#include "glad/glad.h"

namespace BEngine
{
	void RenderCommands::Init()
	{
		// Enable transparent objects.
		glEnable(GL_BLEND);

		// Enable color blending for transparent objects.
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Enable z axis depth testing.
		glEnable(GL_DEPTH_TEST);

		// Set z axis depth testing rendering mode.
		glDepthFunc(GL_LEQUAL);
	}


	void RenderCommands::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void RenderCommands::ClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void RenderCommands::ClearColor(const glm::vec3& color)
	{
		ClearColor({ color.r, color.g, color.b, 1.0f });
	}
}