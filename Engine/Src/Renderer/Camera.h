#pragma once

#include "bepch.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace BEngine
{

	class PerspectiveCamera
	{
	public:
		PerspectiveCamera(float fov, float aspectRatio, float zNear, float zFar);

		// Set the perspective projection settings.
		void SetProjection(float fov, float aspectRatio, float zNear, float zFar);

		// Re-calculates the view matrix.
		void CalculateViewMatrix();

		// Getters.
		const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		const glm::vec3& GetPosition() const { return m_Position; }
		const glm::vec3& GetRotation() const { return m_Rotation; }

		// Setters.
		void SetPosition(const glm::vec3& position) { m_Position = position; CalculateViewMatrix(); };
		void SetRotation(const glm::vec3& position) { m_Rotation = position; CalculateViewMatrix(); }

	private:

		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;
		glm::vec3 m_Position;
		glm::vec3 m_Rotation;
		float m_Fov;
		float m_Near, m_Far;
		float m_AspectRatio;
	};
}