#pragma once

#include "Core.h"
#include "Window.h"

namespace AVL {
    class AVL_API Application {
    public:
        Application();

        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
    };

    // To be defined by the client
    Application *CreateApplication();
}
