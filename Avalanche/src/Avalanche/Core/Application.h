#pragma once

#include "Avalanche/Core/Log.h"
#include "Platforms/LinuxWindow.h"

namespace AVL {
class AVL_API Application {
   public:
    Application();

    void Run();

   private:
    std::unique_ptr<Window> m_Window;
    // std::shared_ptr<Event::EventDispatcher> m_Dispatcher;
};

// To be defined by the client
Application *CreateApplication();
}  // namespace AVL