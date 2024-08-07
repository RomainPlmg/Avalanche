#pragma once

#include "Event.h"

namespace AVL {
class KeyEvent : public Event {
   public:
    [[nodiscard]] const KeyCode GetKeyCode() const { return m_KeyCode; }
    EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

   protected:
    explicit KeyEvent(const KeyCode keycode) : m_KeyCode(keycode) {}

    KeyCode m_KeyCode;
};

class KeyPressedEvent final : public KeyEvent {
   public:
    explicit KeyPressedEvent(const KeyCode keycode, const bool isRepeat = false)
        : KeyEvent(keycode), m_IsRepeat(isRepeat) {}

    [[nodiscard]] inline bool IsRepeat() const { return m_IsRepeat; }

    [[nodiscard]] std::string ToString() const override {
        std::stringstream ss;
        if (KeyNames.find(m_KeyCode) == KeyNames.end()) {
            ss << "KeyPressed: Unknown key code (" << m_KeyCode << ") (repeat = " << m_IsRepeat << ")";
        } else {
            ss << "KeyPressed: " << KeyNames.at(m_KeyCode) << " (repeat = " << m_IsRepeat << ")";
        }

        return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyPressed)

   private:
    bool m_IsRepeat;
};

class KeyReleasedEvent final : public KeyEvent {
   public:
    explicit KeyReleasedEvent(const KeyCode keycode) : KeyEvent(keycode) {}

    [[nodiscard]] std::string ToString() const override {
        std::stringstream ss;
        if (KeyNames.find(m_KeyCode) == KeyNames.end()) {
            ss << "KeyReleased: Unknown key code (" << m_KeyCode << ")";
        } else {
            ss << "KeyReleased: " << KeyNames.at(m_KeyCode);
        }

        return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyReleased)
};
}  // namespace AVL