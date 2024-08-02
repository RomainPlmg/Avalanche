#pragma once

#include "Core.h"
#include "Platforms/LinuxWindow.h"

namespace AVL {
    class AVL_API Application {
    public:
        Application();

        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<LinuxWindow> m_Window;
    };

    // To be defined by the client
    Application *CreateApplication();
}
