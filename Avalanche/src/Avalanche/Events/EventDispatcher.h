#pragma once

#include "Event.h"

namespace AVL {
class EventDispatcher {
   public:
    EventDispatcher(EventDispatcher& other) = delete;
    void operator=(const EventDispatcher&) = delete;

    [[maybe_unused]] static EventDispatcher* GetInstance();

    using Listener = std::function<void(const Event&)>;

    // Add a listener to a specific event category
    void Subscribe(EventCategory category, const Listener& listener);
    // Delete a listener to a specific event category
    void Unsubscribe(EventCategory category, const Listener& listener);
    // Push an event on the bus
    void Dispatch(Event& event);

   private:
    EventDispatcher() = default;
    static EventDispatcher* m_EventDispatcher;
    std::unordered_map<EventCategory, std::vector<Listener>> m_Listeners;
};
}  // namespace AVL
