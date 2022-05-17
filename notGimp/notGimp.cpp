#include "Application.h"

int main(int argc, char** argv)
{
	
	ngp::Application* app = new ngp::Application();
	app->Run();
	delete app;
	return 0;
	
}

