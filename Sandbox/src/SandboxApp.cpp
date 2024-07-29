#include <Avalanche.h>

class Sandbox : public AVL::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

AVL::Application* AVL::CreateApplication() {
	return new Sandbox();
}