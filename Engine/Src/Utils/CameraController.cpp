#include "CameraController.h"
#include "Core/Time.h"

namespace Bonfire
{

	glm::vec3 CameraController::GetForward()
	{
		auto& a = m_Camera->GetViewMatrix();
		return  glm::normalize(-glm::vec3(a[0].z, a[1].z, a[2].z));
	}

	glm::vec3 CameraController::GetRight()
	{
		auto& a = m_Camera->GetViewMatrix();
		return glm::normalize(-glm::vec3(a[0].x, a[1].x, a[2].x));
	}

	glm::vec3 CameraController::GetUp()
	{
		auto& a = m_Camera->GetViewMatrix();
		return glm::normalize(-glm::vec3(a[0].y, a[1].y, a[2].y));
	}

	void CameraController::Update()
	{

		float speed = m_CameraTranslationSpeed;

		if (Input::IsKeyHeld(KEY_LEFT_SHIFT))
			speed = m_CameraTranslationBoostedSpeed;

		if (Input::IsKeyHeld(KEY_W))
			m_CameraPosition += GetForward() * speed * Time::GetDeltaTime();

		if (Input::IsKeyHeld(KEY_S))
			m_CameraPosition += -GetForward() * speed * Time::GetDeltaTime();

		if (Input::IsKeyHeld(KEY_D))
			m_CameraPosition += -GetRight() * speed * Time::GetDeltaTime();

		if (Input::IsKeyHeld(KEY_A))
			m_CameraPosition += GetRight() * speed * Time::GetDeltaTime();

		if (Input::IsKeyHeld(KEY_Q))
			m_CameraPosition += GetUp() * speed * Time::GetDeltaTime();

		if (Input::IsKeyHeld(KEY_E))
			m_CameraPosition += -GetUp() * speed * Time::GetDeltaTime();

		glm::vec2 newMousePos = Input::GetMousePosition();

		if (Input::IsMouseButtonHeld(1))
		{
			glm::vec2 acceleration = (m_MouseAcceleration - newMousePos) * m_CameraSensitivity;
			m_CameraRotation += glm::vec3(acceleration.y, acceleration.x, 0);

		}
		m_MouseAcceleration = newMousePos;

		m_Camera->SetPosition(m_CameraPosition);
		m_Camera->SetRotation(m_CameraRotation);
	}
}