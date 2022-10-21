#include "FrameBuffer.h"
#include "Core/Core.h"

namespace BEngine
{
	FrameBuffer::FrameBuffer(const FrameBufferProperties& properties)
	{
		SetProperties(properties);
	}

	FrameBuffer::~FrameBuffer()
	{
		// Delete objects.
		glDeleteFramebuffers(1, &m_RenderID);
		glDeleteTextures(1, &m_ColorAttachmentID);
		glDeleteTextures(1, &m_DepthAttachmentID);
	}

	void FrameBuffer::Bind()
	{
		// Bind frame buffer object.
		glBindFramebuffer(GL_FRAMEBUFFER, m_RenderID);
	}

	void FrameBuffer::BindColorAttachment()
	{
		// Set active textureslot to 0.
		glActiveTexture(GL_TEXTURE0);

		// Bind color texture.
		glBindTexture(GL_TEXTURE_2D, m_ColorAttachmentID);
	}

	void FrameBuffer::BindDepthAttachment()
	{
		// Set active textureslot to 0.
		glActiveTexture(GL_TEXTURE0);

		// Bind color texture.
		glBindTexture(GL_TEXTURE_2D, m_DepthAttachmentID);
	}

	void FrameBuffer::UnBind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	void FrameBuffer::SetProperties(const FrameBufferProperties& properties)
	{
		// Delete old frame buffer and texture objects if framebuffer was already instantiated.
		if (m_RenderID)
		{
			glDeleteFramebuffers(1, &m_RenderID);
			glDeleteTextures(1, &m_ColorAttachmentID);
			glDeleteTextures(1, &m_DepthAttachmentID);
		}

		// Generate frame buffer object and set its properties.
		glCreateFramebuffers(1, &m_RenderID);

		Bind();

		BE_ASSERT((properties.Width != 0), "Texture width can not be 0.");
		BE_ASSERT((properties.Height != 0), "Texture height can not be 0.");

		// Generate color texture and bind it.
		glGenTextures(1, &m_ColorAttachmentID);
		glBindTexture(GL_TEXTURE_2D, m_ColorAttachmentID);

		// Write data to the color texture.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, properties.Width, properties.Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);

		// Set texture properties.
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Set color texture to frame buffer color attachment.
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachmentID, 0);
		
		// Generate color texture and bind it.
		glGenTextures(1, &m_DepthAttachmentID);
		glBindTexture(GL_TEXTURE_2D, m_DepthAttachmentID);

		// Write data to the depth texture.
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, properties.Width, properties.Height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, NULL);

		// Set depth texture to frame buffer depth attachment.
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_TEXTURE_2D, m_DepthAttachmentID, 0);

		BE_ASSERT((glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE), "Framebuffer is not complete.")

		UnBind();
	}
}