#include <BEngine.h>

class TestApp : public BEngine::Application
{
	virtual void OnTick() override
	{
		bool a = true;
		BEngine::Log::LogMessage(BEngine::Log::LogColor::Red, "Hello World!");
	}
};

BEngine::Application* CreateApplication()
{
	return new TestApp;
}