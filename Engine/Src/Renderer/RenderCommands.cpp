#include "RenderCommands.h"
#include "glad/glad.h"
#include "Core/Core.h"

namespace BEngine
{
	void RenderCommands::Init()
	{
		BE_TRACE("Initialized RenderCommands")

		// Enable transparent rendering & color blending for transparent objects.
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// Set z axis depth testing rendering mode.
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		// Disable back faces from being rendered.
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
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