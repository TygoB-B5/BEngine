#include "RenderData.h"

namespace BEngine
{
	void RenderData::Init()
	{
		m_VertexArray = std::make_shared<VertexArray>();
		m_VertexBuffer = std::make_shared<VertexBuffer>();
		m_IndexBuffer = std::make_shared<IndexBuffer>();
	}

	RenderData::RenderData()
	{
		Init();
	}

	RenderData::RenderData(const std::vector<VertexDataElement>& layout, const std::vector<float>& vertices, const std::vector<uint32_t>& indices)
	{
		Init();

		m_VertexArray->Bind();

		SetVertexData(vertices);
		SetIndexData(indices);

		m_VertexArray->SetLayout(layout);
	}

	void RenderData::SetVertexLayout(const std::vector<VertexDataElement>& layout)
	{
		m_VertexArray->SetLayout(layout);
	}

	void RenderData::SetVertexData(const std::vector<float>& vertices)
	{
		m_VertexBuffer->SetData(vertices);
	}

	void RenderData::SetIndexData(const std::vector<uint32_t>& indices)
	{
		m_IndexBuffer->SetData(indices);
	}

	void RenderData::SetVertexDataDynamic(const std::vector<float>& vertices)
	{
		m_VertexBuffer->SetDataDynamic(vertices);
	}

	void RenderData::SetIndexDataDynamic(const std::vector<uint32_t>& indices)
	{
		m_IndexBuffer->SetDataDynamic(indices);
	}
}