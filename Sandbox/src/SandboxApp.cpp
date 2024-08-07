#include <Avalanche.h>

class Sandbox : public AVL::Application {
   public:
    Sandbox() = default;
    ~Sandbox() = default;
};

AVL::Application* AVL::CreateApplication() {
    return new Sandbox();
}