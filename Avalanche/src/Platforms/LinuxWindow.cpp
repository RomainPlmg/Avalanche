#include "LinuxWindow.h"

#include "Avalanche/Core/Log.h"
#include "Avalanche/Events/Event.h"

namespace AVL {

static bool s_GLFWInitialized = false;

Window* Window::Create(const WindowProps& props) {
    return new LinuxWindow(props);
}

LinuxWindow::LinuxWindow(const WindowProps& props) : m_Handler(nullptr) {
    Init(props);
}

void LinuxWindow::Init(const WindowProps& props) {
    m_WindowData.title = props.title;
    m_WindowData.width = props.width;
    m_WindowData.height = props.height;

    AVL_CORE_INFO("Creating window {0} ({1}x{2})", props.title, props.width, props.height);

    if (!s_GLFWInitialized) {
        AVL_CORE_ASSERT(glfwInit(), "Unable to initialize GLFW. Abort.")
        s_GLFWInitialized = true;
    }

    m_Handler = glfwCreateWindow(static_cast<int>(props.width), static_cast<int>(props.height), props.title.c_str(),
                                 nullptr, nullptr);
    glfwMakeContextCurrent(m_Handler);
    glfwSetWindowUserPointer(m_Handler, this);
    glfwSetFramebufferSizeCallback(m_Handler, framebuffer_size_callback);
    glfwSetKeyCallback(m_Handler, key_callback);
    glfwSetCursorPosCallback(m_Handler, mouse_cursor_pos_callback);
    SetVSync(true);

    AVL_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize GLAD. Abort.")
}

void LinuxWindow::Update() {
    glfwPollEvents();
    glfwSwapBuffers(m_Handler);
}

void LinuxWindow::Close() {
    glfwSetWindowShouldClose(m_Handler, true);
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

void LinuxWindow::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    auto* self = static_cast<LinuxWindow*>(glfwGetWindowUserPointer(window));
    WindowResizeEvent event(width, height);
    // self->m_Dispatcher->Dispatch(event);
}

void LinuxWindow::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::shared_ptr<KeyEvent> event;
    switch (action) {
        case GLFW_PRESS:
            event = std::make_shared<KeyPressedEvent>(static_cast<KeyCode>(key));
            EventDispatcher::GetInstance()->Dispatch(*event);
            break;
        case GLFW_REPEAT:
            event = std::make_shared<KeyPressedEvent>(static_cast<KeyCode>(key), true);
            EventDispatcher::GetInstance()->Dispatch(*event);
            break;
        case GLFW_RELEASE:
            event = std::make_shared<KeyReleasedEvent>(static_cast<KeyCode>(key));
            EventDispatcher::GetInstance()->Dispatch(*event);
            break;
        default:
            break;
    }
}

void LinuxWindow::mouse_cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
    MouseMotionEvent event(xpos, ypos);
    EventDispatcher::GetInstance()->Dispatch(event);
}
}  // namespace AVL