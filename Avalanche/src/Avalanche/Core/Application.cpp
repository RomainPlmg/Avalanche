#include "Application.h"
#include "Avalanche/Events/EventKeyboard.h"
#include "Log.h"
#include <GLFW/glfw3.h>

namespace AVL {
    Application::Application() : m_Window(nullptr) {
        m_Dispatcher = std::make_shared<Event::EventDispatcher>();
        m_Window = std::unique_ptr<Window>(Window::Create(*m_Dispatcher));
    }

    void Application::Run() {
        Listener l;
        m_Dispatcher->Subscribe(&l);
        while (!m_Window->ShouldClose()) {
            glClearColor(1, 0, 0, 1);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->Update();
        }
        m_Dispatcher->Unsubscribe(&l);
        m_Window->Shutdown();
    }
}
