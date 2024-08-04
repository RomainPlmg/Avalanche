#pragma once

#include <GLFW/glfw3.h>

#include "Event.h"

namespace AVL::Event {
class ApplicationEvent : public Event {
    EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class WindowResize : public ApplicationEvent {
   public:
    int width, height;

    WindowResize(int width, int height) : width(width), height(height) {}

    EVENT_CLASS_TYPE(WindowResize)

    [[nodiscard]] std::string ToString() const override {
        std::stringstream ss;
        ss << "Window resized to: " << width << "x" << height;
        return ss.str();
    }
};

class WindowClose : public ApplicationEvent {
   public:
    explicit WindowClose(GLFWwindow *window) { glfwDestroyWindow(window); }

    EVENT_CLASS_TYPE(WindowClose)

    [[nodiscard]] std::string ToString() const override {
        std::stringstream ss;
        ss << "Window closed";
        return ss.str();
    }
};
}  // namespace AVL::Event