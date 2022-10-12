#include "BEngine.h"

class TestApp : public BEngine::Application
{

};

BEngine::Application* CreateApplication()
{
	return new BEngine::Application();
}