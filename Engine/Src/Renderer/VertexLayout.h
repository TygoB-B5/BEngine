#pragma once
#include "bepch.h"
#include "glad/glad.h"

namespace BEngine
{

	struct VertexDataElement
	{
		VertexDataElement(GLuint dataType, GLuint amount)
			: DataType(dataType), Amount(amount)
		{}

		GLuint DataType;
		GLuint Amount;
	};

	class VertexLayout
	{
	public:
		VertexLayout(const std::vector<VertexDataElement>& vertexElements);

		// Bind vertex layout
		void Bind();

	private:

		GLuint m_Stride;
		std::vector<VertexDataElement> m_DataElements;
	};

}