#pragma once
#include "Renderer/Camera.h"
#include "Core/Input.h"
#include "glm/glm.hpp"

namespace Bonfire
{
	class CameraController
	{
	public:
		CameraController(const RefPtr<PerspectiveCamera>& camera, float sensitivity, float speed, float boostedSpeed)
			: m_Camera(camera), m_CameraSensitivity(sensitivity), m_CameraTranslationSpeed(speed), m_CameraTranslationBoostedSpeed(boostedSpeed),
			m_MouseAcceleration({ 0, 0 }), m_CameraPosition(camera->GetPosition()), m_CameraRotation(camera->GetRotation())
		{}
		
		void Update();

		glm::vec3 GetPosition() const { return m_CameraPosition; }
		glm::vec3 GetForward();
		glm::vec3 GetRight();
		glm::vec3 GetUp();

		const RefPtr<PerspectiveCamera>& GetCamera() const { return m_Camera; }

	private:
		RefPtr<PerspectiveCamera> m_Camera;

		glm::vec3 m_CameraPosition, m_CameraRotation;

		float m_CameraSensitivity;
		float m_CameraTranslationSpeed, m_CameraTranslationBoostedSpeed;
		glm::vec2 m_MouseAcceleration;
	};
}