#pragma once

#include <GLFW/glfw3.h>


namespace AVL {

    struct WindowProps {
        std::string title;
        uint32_t width;
        uint32_t height;

        /* Default window props */
        explicit WindowProps(const std::string &title = "Avalanche Engine", uint32_t width = 1600,
                             uint32_t height = 900);
    };

    class Window {
    public:
        explicit Window(const WindowProps &props = WindowProps());

        bool ShouldClose() const;
        void Update();
        void Shutdown();

        [[nodiscard]] inline GLFWwindow *GetHandler() const { return m_Handler; }

    private:
        GLFWwindow *m_Handler;
    };

}
