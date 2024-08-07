#pragma once
extern AVL::Application* AVL::CreateApplication();

int main(int argc, char** argv) {
    AVL::Log::Init();
    const auto app = AVL::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
