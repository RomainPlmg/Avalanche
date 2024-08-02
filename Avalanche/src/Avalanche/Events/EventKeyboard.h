#pragma once

#include "Event.h"
#include "Avalanche/Core/KeyCodes.h"

namespace AVL::Event {
    template<typename Action>
    class KeyEvent : public Event<Action> {
    public:
        ~KeyEvent() override = default;

        [[nodiscard]] inline KeyCode GetKeyCode() const { return m_KeyCode; }
        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        explicit KeyEvent(const KeyCode keycode) : m_KeyCode(keycode) {
        }

        KeyCode m_KeyCode;
    };

    class KeyPressed final : public KeyEvent<KeyPressed> {
    public:
        explicit KeyPressed(const KeyCode keycode, const bool isRepeat = false) : KeyEvent(keycode),
            m_IsRepeat(isRepeat) {
        }

        [[nodiscard]] inline bool IsRepeat() const { return m_IsRepeat; }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressed: " << m_KeyCode << " (repeat = " << m_IsRepeat << ")";
            return ss.str();
        }

    private:
        bool m_IsRepeat;
    };

    class KeyReleased final : public KeyEvent<KeyReleased> {
    public:
        explicit KeyReleased(const KeyCode keycode) : KeyEvent(keycode) {
        }

        [[nodiscard]] std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleased: " << m_KeyCode;
            return ss.str();
        }
    };
}
