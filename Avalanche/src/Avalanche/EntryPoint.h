#pragma once

#ifdef AVL_PLATFORM_WINDOWS

extern AVL::Application* AVL::CreateApplication();

int main(int argc, char** argv) {
	auto app = AVL::CreateApplication();
	app->Run();
	delete app;

	return 0;
}
#endif