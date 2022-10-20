#include "Renderer.h"
#include "glad/glad.h"

namespace BEngine
{
	void Renderer::Draw(const RefPtr<RenderData>& renderDataObject, uint32_t indexCount)
	{
		// Bind vertex array with the data vertex layout.
		renderDataObject->GetVertexArray()->Bind();

		uint32_t count = indexCount == 0 ? renderDataObject->GetIndexBuffer()->GetElementCount() : indexCount;
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
	}
}