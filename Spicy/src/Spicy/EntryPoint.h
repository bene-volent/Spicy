#pragma once

#ifdef SPC_PLATFORM_WINDOWS

extern Spicy::Application* Spicy::CreateApplication();

int main(int args, char** argc)
{

	Spicy::Log::Init();
	SPC_CORE_WARN("Hello Var={0}", 1);
	SPC_INFO("Client Logger Initialized");

	auto app = Spicy::CreateApplication();

	app->Run();
	delete app;
}
#endif