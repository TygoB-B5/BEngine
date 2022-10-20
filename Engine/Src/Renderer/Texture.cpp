#include "Texture.h"
#include "Core/Core.h"
#include "glad/glad.h"

namespace BEngine
{
	Texture2D::Texture2D(const std::string& filePath)
	{
		// Generate texture object.
		glGenTextures(1, &m_TextureID);
		SetTexture(filePath);
	}

	void Texture2D::SetTexture(const std::string& filePath)
	{
		Bind();
		FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(filePath.c_str(), 0);

		BE_ASSERT(!(formato == FIF_UNKNOWN), "Image file type is unknown. " + filePath)

		FIBITMAP* imagen = FreeImage_Load(formato, filePath.c_str());

		BE_ASSERT(imagen, "Image can not be loaded. " + filePath);

		FIBITMAP* temp = FreeImage_ConvertTo32Bits(imagen);

		BE_ASSERT(temp, "Image can not be converted. " + filePath);

		imagen = temp;

		m_Width = FreeImage_GetWidth(imagen);
		m_Height = FreeImage_GetHeight(imagen);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_BGRA, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(imagen));
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


		FreeImage_Unload(imagen);
	}

	void Texture2D::Bind(uint32_t textureSlot)
	{
		// Set active textureslot to bind to.
		glActiveTexture(GL_TEXTURE0 + textureSlot);

		// Bind texture to active textureslot.
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}
}