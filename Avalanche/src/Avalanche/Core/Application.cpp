#include "Application.h"
#include "Avalanche/Events/EventKeyboard.h"

#include <memory>

#include "Log.h"

namespace AVL {
    Application::Application() : m_Window(nullptr) {
        m_Window = std::make_unique<LinuxWindow>();
    }

    Application::~Application() {
    }

    void Application::Run() {
        Event::KeyPressed e(KeyCode::F1);
        AVL_TRACE(e.ToString());
        while (!m_Window->ShouldClose()) {
            m_Window->Update();
        }
        m_Window->Shutdown();
    }
}
