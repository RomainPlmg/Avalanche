#include "LinuxWindow.h"
#include "Avalanche/Core/Log.h"
#include "Avalanche/Core/Core.h"

namespace AVL {

    static bool s_GLFWInitialized = false;

    Window *Window::Create(const WindowProps &props) {
        return new LinuxWindow(props);
    }

    LinuxWindow::LinuxWindow(const WindowProps &props) : m_Handler(nullptr) {
        Init(props);
    }


    void LinuxWindow::Init(const WindowProps &props) {
        m_WindowData.title = props.title;
        m_WindowData.width = props.width;
        m_WindowData.height = props.height;

        AVL_CORE_INFO("Creating window {0} ({1}x{2})", props.title, props.width, props.height);

        if (!s_GLFWInitialized) {
            AVL_CORE_ASSERT(glfwInit(), "Unable to initialize GLFW. Abort.")
            s_GLFWInitialized = true;
        }

        m_Handler = glfwCreateWindow(static_cast<int>(props.width), static_cast<int>(props.height), props.title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Handler);
        glfwSetWindowUserPointer(m_Handler, &m_WindowData);
        SetVSync(true);
    }

    void LinuxWindow::Update() {
        glfwPollEvents();
        glfwSwapBuffers(m_Handler);
    }

    bool LinuxWindow::ShouldClose() const {
        return glfwWindowShouldClose(m_Handler);
    }

    void LinuxWindow::Shutdown() {
        glfwDestroyWindow(m_Handler);
        glfwTerminate();
    }

    void LinuxWindow::SetVSync(bool enable) {
        if (enable) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }

        m_WindowData.vsync = enable;
    }

    void LinuxWindow::SetEventCallback(const EventCallbackFn &callback) {

    }



}