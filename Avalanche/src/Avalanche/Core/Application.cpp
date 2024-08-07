#include "Application.h"
#include "Avalanche/Events/EventApplication.h"
#include "Avalanche/Events/EventKeyboard.h"
#include "Avalanche/Events/EventMouse.h"
#include "Log.h"

namespace AVL {
Application::Application() : m_Window(nullptr) {
    m_Window = std::unique_ptr<Window>(Window::Create());
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
