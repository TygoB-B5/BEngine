#include <BEngine.h>

class TestApp : public BEngine::Application
{
public:

	TestApp()
	{
		BE_LOG_TRACE("Hello")
		BE_LOG_INFO("Hello")
		BE_LOG_WARN("Hello")
		BE_LOG_ERROR("Hello")
		BE_ASSERT(false, "Assertion found, oh no")
	}

	virtual void OnUpdate() override
	{
		
	}
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}