#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	Hazel::Log::Init();
	Hazel::Log::GetCoreLogger()->warn("Initialized Log!");
	Hazel::Log::GetCoreLogger()->info("Hello!");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif