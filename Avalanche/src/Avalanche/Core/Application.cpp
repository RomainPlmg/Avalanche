#include "Application.h"
#include "Input.h"
#include "Log.h"

namespace AVL {
Application* Application::m_Instance = nullptr;

Application::Application() : m_Window(nullptr) {
    AVL_CORE_ASSERT(!m_Instance, "Application already exists.");
    m_Instance = this;
    m_Window = std::unique_ptr<Window>(Window::Create());
    m_LayerStack = std::make_unique<LayerStack>();

    EventDispatcher::GetInstance()->Subscribe(EventCategory::EventCategoryInput, AVL_BIND_EVENT_FN(OnEvent));
}

void Application::Run() {
    while (!m_Window->ShouldClose()) {
        m_Window->Update();
    }
    EventDispatcher::GetInstance()->Unsubscribe(EventCategory::EventCategoryInput, AVL_BIND_EVENT_FN(OnEvent));
    m_Window->Shutdown();
}

void Application::OnEvent(const Event& event) {
    AVL_CORE_TRACE(event.ToString());
}
}  // namespace AVL
