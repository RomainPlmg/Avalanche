#include "EventDispatcher.h"

namespace AVL::Event {

// void EventDispatcher::Subscribe(EventListener *listener) {
//     m_Listeners.push_back(listener);
// }

// void EventDispatcher::Unsubscribe(EventListener *listener) {
//     m_Listeners.erase(
//             std::remove(m_Listeners.begin(), m_Listeners.end(), listener),
//             m_Listeners.end()
//     );
// }

// void EventDispatcher::Dispatch(Event &event) {
//     for (const auto &listener: m_Listeners) {
//         listener->OnEvent(event);
//     }
// }

}  // namespace AVL::Event