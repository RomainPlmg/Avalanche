#pragma once

#include "Event.h"

namespace AVL::Event {
    /* Interface for any object or function witch deals with events */
    class EventListener {
    public:
        virtual ~EventListener() = default;

        virtual void OnEvent(Event &event) = 0;
    };

    class EventDispatcher {
    public:
        void Subscribe(EventListener* eventListener); // Add a listener to a specific event type
        void Unsubscribe(EventListener* eventListener); // Delete a listener to a specific event type
        void Dispatch(Event &event); // Push an event on the bus
    private:
        std::vector<EventListener*> m_Listeners;
    };
}
