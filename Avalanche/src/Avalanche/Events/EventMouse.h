#pragma once

#include "Event.h"

namespace AVL {
class MouseEvent : public Event {
    EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};

class MouseMotionEvent : public MouseEvent {
   public:
    MouseMotionEvent(double x, double y) : posX(x), posY(y) {}

    double posX, posY;

    std::string ToString() const override {
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

    std::string ToString() const override {
        std::stringstream ss;
        ss << "Mouse " << (button ? "right" : "left") << " click";
        return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
};

class MouseButtonReleasedEvent : public MouseEvent {
   public:
    MouseButtonReleasedEvent(int button) : button(button) {}

    int button;

    std::string ToString() const override {
        std::stringstream ss;
        ss << "Mouse " << (button ? "right" : "left") << " click released";
        return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
};
}  // namespace AVL