#include "Window.h"
#include "Log.h"

namespace AVL {

    WindowProps::WindowProps(const std::string &title, uint32_t width, uint32_t height) :
            title(title), width(width), height(height) {}

    Window::Window(const WindowProps &props) : m_Handler(nullptr) {
        AVL_CORE_INFO("Creating window {0} ({1}x{2})", props.title, props.width, props.height);
        if (!glfwInit()) AVL_CORE_FATAL("Unable to initialized GLFW. Abort.")

        m_Handler = glfwCreateWindow((int)props.width, (int)props.height, props.title.c_str(), nullptr, nullptr);
    }

    bool Window::ShouldClose() const {
        return glfwWindowShouldClose(m_Handler);
    }

    void Window::Update() {
        glfwPollEvents();
        glfwSwapBuffers(m_Handler);
    }

    void Window::Shutdown() {
        glfwDestroyWindow(m_Handler);
        glfwTerminate();
    }

} // AVL