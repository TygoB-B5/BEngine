#pragma once
#include "bepch.h"
#include "FreeImage.h"

namespace BEngine
{
	class Texture2D
	{
	public:
		Texture2D(const std::string& filePath);

		void SetTexture(const std::string& filePath);

		void Bind(uint32_t textureSlot = 0);
	private:
		uint32_t m_Width, m_Height;
		uint32_t m_TextureID;
	};
}