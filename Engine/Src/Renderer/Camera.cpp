#include "Camera.h"

namespace BEngine
{
	PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, float zNear, float zFar)
		: m_Fov(fov), m_AspectRatio(aspectRatio), m_Near(zNear), m_Far(zFar), m_Position(glm::vec3(0.0f)), m_Rotation(glm::vec3(0.0f))
	{
		SetProjection(fov, aspectRatio, zNear, zFar);
	}

	void PerspectiveCamera::SetProjection(float fov, float aspectRatio, float zNear, float zFar)
	{
		// Calculate and set new perspective projection.
		m_ProjectionMatrix = glm::perspective(fov, aspectRatio, zNear, zFar);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	void PerspectiveCamera::CalculateViewMatrix()
	{
		// Calculate viewmatrix.
		glm::mat4 transform = glm::translate(glm::mat4(0.1f), m_Position);
		glm::mat4 rotatex = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.x), glm::vec3(1, 0, 0));
		glm::mat4 rotatey = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.y), glm::vec3(0, 1, 0));
		glm::mat4 rotatez = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.z), glm::vec3(0, 0, 1));

		// Calculate inverse.
		m_ViewMatrix = glm::inverse((transform * rotatey) * rotatex * rotatez);

		// Calculate view projection matrix.
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}
}