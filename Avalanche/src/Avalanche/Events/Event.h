#pragma once

namespace AVL::Event {
    /* Use of bit shift operations because an event can be in multiple categories */
    enum EventCategory {
        None = 0,
        EventCategoryApplication = 1 << 0,
        EventCategoryInput = 1 << 1,
        EventCategoryKeyboard = 1 << 2,
        EventCategoryMouse = 1 << 3,
        EventCategoryMouseButton = 1 << 4
    };

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


    /* Will be inherited */
    template<typename EventType>
    class Event {
    public:
        virtual ~Event() = default;
        [[nodiscard]] virtual int GetCategoryFlags() const = 0;

        static inline std::string GetType() { return typeid(EventType).name(); }

        [[nodiscard]] virtual std::string ToString() const = 0;

        static inline bool IsInCategory(const EventCategory &category) { return GetCategoryFlags() & category; }
            
        friend std::ostream &operator<<(std::ostream &os, const Event &e) {
            return os << e.ToString();
        }
    };
}
