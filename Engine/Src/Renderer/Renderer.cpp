#include "Renderer.h"
#include "glad/glad.h"

namespace BEngine
{
	FrameData Renderer::s_FrameData;

	void Renderer::BeginFrame(const RefPtr<PerspectiveCamera> camera)
	{
		s_FrameData.m_ViewProjectionMatrix = camera->GetViewProjectionMatrix();
	}

	void Renderer::Draw(const RefPtr<VertexData>& vertexData, const RefPtr<Shader>& shader, uint32_t indexCount)
	{
		// Bind vertex array with the data vertex layout.
		vertexData->GetVertexArray()->Bind();

		// Bind shader and upload camera view projection matrix from framedata.
		shader->Bind();
		shader->UploadUniformMat4("uViewProjection", s_FrameData.m_ViewProjectionMatrix);

		// Get element count.
		uint32_t count = indexCount == 0 ? vertexData->GetIndexBuffer()->GetElementCount() : indexCount;

		// Gl call to draw elements.
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}
}