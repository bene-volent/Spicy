#pragma once

#ifdef SPC_PLATFORM_WINDOWS

extern Spicy::Application* Spicy::CreateApplication();

int main(int args, char** argc)
{

	Spicy::Log::Init();

	auto app = Spicy::CreateApplication();

	app->Run();
	delete app;
}
#endif