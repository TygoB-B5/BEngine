#pragma once
#include "bepch.h"
#include "glad/glad.h"

namespace Bonfire
{
	struct FrameBufferProperties
	{
		uint32_t Width;
		uint32_t Height;
	};

	class FrameBuffer
	{
	public:
		// Construct frame buffer object.
		FrameBuffer(const FrameBufferProperties& properties);
		~FrameBuffer();

		// Bind frame buffer object.
		void Bind();

		// Binds the color attachment to texture 0.
		void BindColorAttachment(uint32_t index);

		// Binds the depth attachment to texture 0.
		void BindDepthAttachment(uint32_t index);

		// Unbind frame buffer object. (Revert to default framebuffer)
		void UnBind();

		// Set framebuffer properties
		void SetProperties(const FrameBufferProperties& properties);

	private:
		FrameBufferProperties properties;
		uint32_t m_RenderID, m_ColorAttachmentID, m_DepthAttachmentID;
	};
}