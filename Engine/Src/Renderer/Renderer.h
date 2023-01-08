#pragma once
#include "Core/Core.h"
#include "Shader.h"
#include "VertexData.h"
#include "Camera.h"

namespace Bonfire
{

	struct FrameData
	{
		glm::mat4 m_ViewProjectionMatrix;
	};

	class Renderer
	{
	public:
		static void BeginFrame(const RefPtr<PerspectiveCamera>& camera);
		static void Draw(const RefPtr<VertexData>& vertexData, const RefPtr<Shader>& shader, uint32_t indexCount = 0);

	private:
		static FrameData s_FrameData;
	};
}