#include "Window.h"

#include "Avalanche/Events/EventApplication.h"
#include "Log.h"

namespace AVL {

Window::Window() {
    EventDispatcher::GetInstance()->Subscribe(EventCategory::EventCategoryApplication, AVL_BIND_EVENT_FN(OnEvent));
}

void Window::OnEvent(const Event& event) {
    switch (event.GetType()) {
        case EventType::WindowClose:
            Close();
            break;

        default:
            return;
    }
}

WindowProps::WindowProps(std::string title, const uint32_t width, const uint32_t height)
    : title(std::move(title)), width(width), height(height) {}
}  // namespace AVL