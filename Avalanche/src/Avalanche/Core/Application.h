#pragma once

#include "Platforms/LinuxWindow.h"
#include "Avalanche/Core/Log.h"

namespace AVL {
    class AVL_API Application {
    public:
        Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        std::shared_ptr<Event::EventDispatcher> m_Dispatcher;
    };

    // To be defined by the client
    Application *CreateApplication();

    class Listener : public Event::EventListener {
    public:
        void OnEvent(AVL::Event::Event &event) override {
            AVL_CORE_TRACE(event.ToString());
        }
    };
}