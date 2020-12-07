#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv) {
	Hazel::Log::Init();
	HZ_CORE_WARN("Initialized Log!");
	int a = 5;
	HZ_INFO("Hello! var={0}", a);
	HZ_ERROR("OH NOOOOOOOO");
	HZ_CORE_TRACE("ERRROROROROROROR");
	HZ_CRITICAL("GOD SEX");

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif 