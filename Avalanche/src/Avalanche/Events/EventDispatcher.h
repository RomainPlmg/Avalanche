#pragma once

#include "Event.h"

namespace AVL::Event {
template <typename T>
class EventDispatcher {
   private:
   public:
    // void Subscribe(EventListener* eventListener); // Add a listener to a
    // specific event type void Unsubscribe(EventListener* eventListener); //
    // Delete a listener to a specific event type void Dispatch(Event &event);
    // // Push an event on the bus
   private:
    // std::vector<EventListener*> m_Listeners;
};
}  // namespace AVL::Event
