#include "OpenGLContext.h"
#include "Avalanche/Core/Log.h"

namespace AVL {
OpenGLContext::OpenGLContext(GLFWwindow* handler) : m_Handler(handler) {}

void OpenGLContext::Init() {
    glfwMakeContextCurrent(m_Handler);
    AVL_CORE_ASSERT(gladLoadGLLoader((GLADloadproc)glfwGetProcAddress), "Failed to initialize GLAD. Abort.");
    AVL_CORE_INFO("OpenGL initialized");
}

void OpenGLContext::SwapBuffers() {
    glfwSwapBuffers(m_Handler);
}
}  // namespace AVL
