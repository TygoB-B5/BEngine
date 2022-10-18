#pragma once
#include "bepch.h"
#include "VertexLayout.h"
#include "glad/glad.h"

#define VERTEX_SRC_PREFIX "#vertex"
#define FRAGMENT_SRC_PREFIX "#fragment"

namespace BEngine
{

	class Shader
	{
	public:
		// Create a shader instance with shader file.
		Shader(const std::string& filename);

		~Shader();

		// Bind this shader.
		void Bind();

		// Unbind this shader.
		void UnBind();

	private:
		// Split ever shader type to type and source.
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);

		// Compile every shader in the map by type and source.
		void Compile(const std::unordered_map<GLenum, std::string>& sources);

	private:
		std::unordered_map<GLenum, std::string> m_Sources;
		GLuint m_RendererID;
	};


}