#pragma once



namespace AVL::Event {

    enum class EventType;
    class Event;

    class EventBus {
    public:
        using Listener = std::function<void(const Event&)>;

        void Subscribe(EventType type, const Listener& listener); // Add a listener to a specific event type
        void Unsubscribe(EventType type, const Listener& listener); // Delete a listener to a specific event type
        void Publish(const Event& event); // Push an event on the bus
    private:
        std::unordered_map<EventType, std::vector<Listener>> m_Listeners;
    };
}