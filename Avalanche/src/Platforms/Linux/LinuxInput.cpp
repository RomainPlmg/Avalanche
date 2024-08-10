#include "LinuxInput.h"
#include "Avalanche/Core/Application.h"

#include <GLFW/glfw3.h>

namespace AVL {
Input* Input::m_Instance = new LinuxInput();

bool LinuxInput::IsKeyPressedImpl(KeyCode keycode) {
    auto window = static_cast<GLFWwindow*>(Application::GetIntance().GetWindow().GetHandler());

    auto state = glfwGetKey(window, keycode);
    return (state == GLFW_PRESS || state == GLFW_REPEAT);
}
}  // namespace AVL