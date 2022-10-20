#pragma once
#include "Core/Core.h"
#include "Shader.h"
#include "RenderData.h"

namespace BEngine
{

	class Renderer
	{
	public:
		static void Draw(const RefPtr<RenderData>& renderDataObject, uint32_t indexCount = 0);
	};
}