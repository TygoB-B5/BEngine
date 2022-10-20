#include "VertexData.h"

namespace BEngine
{
	void VertexData::Init()
	{
		m_VertexArray = std::make_shared<VertexArray>();
		m_VertexBuffer = std::make_shared<VertexBuffer>();
		m_IndexBuffer = std::make_shared<IndexBuffer>();
	}

	VertexData::VertexData()
	{
		Init();
	}

	VertexData::VertexData(const std::vector<VertexDataElement>& layout, const std::vector<float>& vertices, const std::vector<uint32_t>& indices)
	{
		Init();

		m_VertexArray->Bind();

		SetVertexData(vertices);
		SetIndexData(indices);

		m_VertexArray->SetLayout(layout);
	}

	void VertexData::SetVertexLayout(const std::vector<VertexDataElement>& layout)
	{
		m_VertexArray->SetLayout(layout);
	}

	void VertexData::SetVertexData(const std::vector<float>& vertices)
	{
		m_VertexBuffer->SetData(vertices);
	}

	void VertexData::SetIndexData(const std::vector<uint32_t>& indices)
	{
		m_IndexBuffer->SetData(indices);
	}

	void VertexData::SetVertexDataDynamic(const std::vector<float>& vertices)
	{
		m_VertexBuffer->SetDataDynamic(vertices);
	}

	void VertexData::SetIndexDataDynamic(const std::vector<uint32_t>& indices)
	{
		m_IndexBuffer->SetDataDynamic(indices);
	}
}