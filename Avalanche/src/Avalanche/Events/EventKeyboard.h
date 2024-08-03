#pragma once

#include "Event.h"

namespace AVL::Event {
    class KeyEvent : public Event {
    public:
        ~KeyEvent() override = default;

        [[nodiscard]] inline KeyCode GetKeyCode() const { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        explicit KeyEvent(const KeyCode keycode) : m_KeyCode(keycode) {
        }

        KeyCode m_KeyCode;
    };

    class KeyPressed final : public KeyEvent {
    public:
        explicit KeyPressed(const KeyCode keycode, const bool isRepeat = false) : KeyEvent(keycode),
            m_IsRepeat(isRepeat) {
        }

        [[nodiscard]] inline bool IsRepeat() const { return m_IsRepeat; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressed: " << KeyNames.at(m_KeyCode) << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        bool m_IsRepeat;
    };

    class KeyReleased final : public KeyEvent {
    public:
        explicit KeyReleased(const KeyCode keycode) : KeyEvent(keycode) {
        }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleased: " << KeyNames.at(m_KeyCode);
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };
}
