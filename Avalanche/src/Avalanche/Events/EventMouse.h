#pragma once

#include <GLFW/glfw3.h>
#include "Event.h"

namespace AVL {
class MouseEvent : public Event {
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};

class MouseMotionEvent : public MouseEvent {
   public:
    MouseMotionEvent(double x, double y) : posX(x), posY(y) {}

    double posX, posY;

    [[nodiscard]] std::string ToString() const override {
        std::stringstream ss;
        ss << "Mouse moved at: x=" << posX << " | y=" << posY;
        return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseMoved)
};

class MouseButtonPressedEvent : public MouseEvent {
   public:
    MouseButtonPressedEvent(int button) : button(button) {}

    int button;

    [[nodiscard]] std::string ToString() const override {
        std::stringstream ss;
        ss << "Mouse " << (button == GLFW_MOUSE_BUTTON_LEFT ? "left" : "right") << " click";
        return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
};

class MouseButtonReleasedEvent : public MouseEvent {
   public:
    MouseButtonReleasedEvent(int button) : button(button) {}

    int button;

    [[nodiscard]] std::string ToString() const override {
        std::stringstream ss;
        ss << "Mouse " << (button == GLFW_MOUSE_BUTTON_LEFT ? "left" : "right") << " click released";
        return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
};
}  // namespace AVL