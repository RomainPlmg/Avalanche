#include "Application.h"
#include "Avalanche/Events/EventKeyboard.h"
#include "Log.h"
#include <GLFW/glfw3.h>

namespace AVL {
    Application::Application() : m_Window(nullptr) {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {
    }

    void Application::Run() {
        Event::KeyPressed e(KeyCode::F1);
        AVL_TRACE(e.ToString());

        while (!m_Window->ShouldClose()) {
            glClearColor(1, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->Update();
        }
        m_Window->Shutdown();
    }
}
