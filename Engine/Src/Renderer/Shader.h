#pragma once
#include "bepch.h"
#include "VertexLayout.h"
#include "glad/glad.h"
#include "glm/glm.hpp"

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

		// Upload different variable types to shader.
		void UploadUniformFloat(const std::string& uniformName, float value);
		void UploadUniformInt(const std::string& uniformName, int value);
		void UploadUniformVec3(const std::string& uniformName, const glm::vec3& value);
		void UploadUniformVec4(const std::string& uniformName, const glm::vec4& value);

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