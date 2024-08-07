#pragma once

#include "Avalanche/Core/Log.h"
#include "Platforms/LinuxWindow.h"

namespace AVL {
class AVL_API Application {
   public:
    Application();

    void Run();
    void OnEvent(const Event& event);

   private:
    std::unique_ptr<Window> m_Window;
};

// To be defined by the client
Application* CreateApplication();
}  // namespace AVL