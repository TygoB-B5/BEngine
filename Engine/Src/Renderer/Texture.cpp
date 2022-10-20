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
		// Bind current texture to be written to.
		Bind();

		// Get filetype of the image in filepath.
		FREE_IMAGE_FORMAT formato = FreeImage_GetFileType(filePath.c_str(), 0);
		BE_ASSERT(!(formato == FIF_UNKNOWN), "Image file type is unknown. " + filePath)

		// Load image data in to bitmap.
		FIBITMAP* img = FreeImage_Load(formato, filePath.c_str());
		BE_ASSERT(img, "Image can not be loaded. " + filePath);
		
		// Save the width and height of the image to this class.
		m_Width = FreeImage_GetWidth(img);
		m_Height = FreeImage_GetHeight(img);


		GLenum internalFormat = GL_RGB8;
		GLenum format = GL_RGB;

		// Change image format if image is transparent.
		if (FreeImage_IsTransparent(img))
		{
			internalFormat = GL_RGBA8;
			format = GL_RGBA;

			// Convert image to 32 bit so the image keeps its transparency.
			FIBITMAP* temp = FreeImage_ConvertTo32Bits(img);

			BE_ASSERT(temp, "Image can not be converted. " + filePath);

			img = temp;
		}

		// Set the texture data.
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_Width, m_Height, 0, format, GL_UNSIGNED_BYTE, (void*)FreeImage_GetBits(img));
		glGenerateMipmap(GL_TEXTURE_2D);

		// Set the texture properties.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Unload/Free the image.
		FreeImage_Unload(img);
	}

	void Texture2D::Bind(uint32_t textureSlot)
	{
		// Set active textureslot to bind to.
		glActiveTexture(GL_TEXTURE0 + textureSlot);

		// Bind texture to active textureslot.
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}
}