#pragma once

namespace AVL {
enum class EventType {
    None = 0,

    /* Window events */
    WindowClose,
    WindowResize,
    WindowFocus,
    WindowLostFocus,
    WindowMoved,

    /* Application events*/
    AppTick,
    AppUpdate,
    AppRender,

    /* Keyboard events */
    KeyPressed,
    KeyReleased,
    KeyTyped,

    /* Mouse events */
    MouseButtonPressed,
    MouseButtonReleased,
    MouseMoved,
    MouseScrolled
};

/* Use of bit shift operations because an event can be in multiple categories */
enum EventCategory {
    None = 0,
    EventCategoryApplication = 1 << 0,
    EventCategoryInput = 1 << 1,
    EventCategoryKeyboard = 1 << 2,
    EventCategoryMouse = 1 << 3,
    EventCategoryMouseButton = 1 << 4
};

#define EVENT_CLASS_TYPE(type)                     \
    virtual EventType GetType() const override {   \
        return type;                               \
    }                                              \
    virtual const char* GetName() const override { \
        return #type;                              \
    }

#define EVENT_CLASS_CATEGORY(category)              \
    virtual int GetCategoryFlags() const override { \
        return category;                            \
    }

/* Pure virtual class, will be inherited */
class AVL_API Event {
   public:
    [[nodiscard]] virtual int GetCategoryFlags() const = 0;

    [[nodiscard]] virtual EventType GetType() const = 0;

    [[nodiscard]] virtual const char* GetName() const = 0;

    [[nodiscard]] virtual std::string ToString() const = 0;

    [[nodiscard]] inline bool IsInCategory(const EventCategory& category) const {
        return GetCategoryFlags() & category;
    }

    friend std::ostream& operator<<(std::ostream& os, const Event& e) { return os << e.ToString(); }
};
}  // namespace AVL