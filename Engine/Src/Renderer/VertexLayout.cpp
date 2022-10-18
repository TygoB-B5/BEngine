#include "VertexLayout.h"
#include "Src/Core.h"

namespace BEngine
{

	uint32_t glDatatypeSize(uint32_t type)
	{

		// Return size in bytes from Opengl datatype.
		switch (type)
		{
		case GL_FLOAT:        return 4;
		case GL_INT:          return 4;
		case GL_DOUBLE:       return 8;
		case GL_UNSIGNED_INT: return 4;

		default: BE_ASSERT(false, "Datatype not implemented."); return 0;
		}
	}

	BEngine::VertexLayout::VertexLayout(const std::vector<VertexDataElement>& vertexElements)
		: m_DataElements(vertexElements), m_Stride(0)
	{
	}

	void BEngine::VertexLayout::Bind()
	{
		uint32_t offset = 0;
		m_Stride = 0;

		// Set the vertex layout based on the vector of VertexDataElements.
		for (uint32_t i = 0; i < m_DataElements.size(); i++)
		{
			// Enable vertex attribute array of i.
			glEnableVertexAttribArray(i);

			// Set vertex attribute data.
			glVertexAttribPointer(i, m_DataElements[i].Amount, m_DataElements[i].DataType, GL_FALSE, 24, (const void*)offset);

			// Increase offset for next element.
			offset += glDatatypeSize(m_DataElements[i].DataType) * m_DataElements[i].Amount;
		}
	}

}