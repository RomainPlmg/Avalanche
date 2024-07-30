#pragma once

#ifdef AVL_PLATFORM_WINDOWS

extern AVL::Application* AVL::CreateApplication();

int main(int argc, char** argv) {
	AVL::Log::Init();

	AVL_CORE_INFO("Core logger initialized");
	AVL_INFO("Cient logger initialized");

	auto app = AVL::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#endif