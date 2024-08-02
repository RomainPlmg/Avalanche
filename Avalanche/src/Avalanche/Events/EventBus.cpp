#include "EventBus.h"
#include <algorithm>

namespace AVL::Event {

    void EventBus::Subscribe(const EventType type, const Listener& listener) {
        m_Listeners[type].push_back(listener);
    }

    void EventBus::Unsubscribe(const EventType type, const Listener& listener) {

    }

    void EventBus::Publish(const Event &event) {

    }

}