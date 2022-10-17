#pragma once
#include "bepch.h"
#include "glad/glad.h"

#define VERTEX_SRC_PREFIX "#vertex"
#define FRAGMENT_SRC_PREFIX "#fragment"

namespace BEngine
{

	class Shader
	{
	public:
		Shader();
		Shader(const std::string& filename);

		void SetShader(const std::string& filename);

		void Bind();

	private:
		std::unordered_map<GLenum, std::string> PreProcess(const std::string& source);
		void Compile(const std::unordered_map<GLenum, std::string>& sources);

	private:
		std::unordered_map<GLenum, std::string> m_Sources;

		GLuint m_RendererID;
	};


}