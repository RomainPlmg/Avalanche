#include "Application.h"

#include "Avalanche/Events/EventKeyboard.h"
#include "Log.h"

namespace AVL {
Application::Application() : m_Window(nullptr) {
    m_Window = std::unique_ptr<Window>(Window::Create());
}

void Application::Run() {
    while (!m_Window->ShouldClose()) {
        m_Window->Update();
    }
    m_Window->Shutdown();
}
}  // namespace AVL
