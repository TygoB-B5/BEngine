#include <BEngine.h>

class TestApp : public BEngine::Application
{
public:

	TestApp()
	{

	}

	virtual void OnUpdate() override
	{
		BE_LOG_TRACE("Hello")
			BE_LOG_INFO("Hello")
			BE_LOG_WARN("Hello")
			BE_LOG_ERROR("Hello")
	}
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}