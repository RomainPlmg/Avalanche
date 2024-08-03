#include "Window.h"
#include "Log.h"

namespace AVL {

    Window::Window(Event::EventDispatcher& dispatcher) : m_Dispatcher(&dispatcher) {

    }

    WindowProps::WindowProps(const std::string &title, const uint32_t width, const uint32_t height) :
            title(title), width(width), height(height) {}

} // AVL