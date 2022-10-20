#pragma once
#include "bepch.h"
#include "FreeImage.h"

namespace BEngine
{
	class Texture2D
	{
	public:
		Texture2D(const std::string& filePath);

		// Set texture data.
		void SetTexture(const std::string& filePath);

		// Bind texture to textureslot.
		void Bind(uint32_t textureSlot = 0);

	private:
		uint32_t m_Width, m_Height;
		uint32_t m_TextureID;
	};
}