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

bool LinuxInput::IsMouseButtonPressedImpl(MouseButtonCode button) {
    auto window = static_cast<GLFWwindow*>(Application::GetIntance().GetWindow().GetHandler());

    auto state = glfwGetMouseButton(window, button);
    return (state == GLFW_PRESS || state == GLFW_REPEAT);
}

glm::vec2 LinuxInput::GetMousePositionImpl() {
    auto window = static_cast<GLFWwindow*>(Application::GetIntance().GetWindow().GetHandler());

    glm::dvec2 position;
    glfwGetCursorPos(window, &position.x, &position.y);

    return static_cast<glm::vec2>(position);
}
}  // namespace AVL