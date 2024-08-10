#pragma once

#include "LayerStack.h"
#include "Log.h"
#include "Platforms/Linux/LinuxWindow.h"

namespace AVL {
class AVL_API Application {
   public:
    Application();

    void Run();
    void OnEvent(const Event& event);

    /* Getters */
    static Application& GetIntance() { return *m_Instance; }
    Window& GetWindow() const { return *m_Window; }

   private:
    static Application* m_Instance;
    std::unique_ptr<Window> m_Window;
    std::unique_ptr<LayerStack> m_LayerStack;
};

// To be defined by the client
Application* CreateApplication();
}  // namespace AVL