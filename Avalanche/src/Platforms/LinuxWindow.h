#pragma once

#include "Avalanche/Core/Window.h"
#include <GLFW/glfw3.h>


namespace AVL {
    class LinuxWindow : public Window {
    public:
        explicit LinuxWindow(const WindowProps &props);

        ~LinuxWindow() override = default;

        void Update() override;

        /* Window attributes */
        [[nodiscard]] uint32_t GetWidth() const override { return m_WindowData.width; }

        [[nodiscard]] uint32_t GetHeight() const override { return m_WindowData.height; }

        [[nodiscard]] bool IsVSync() const override {return m_WindowData.vsync; }

        void SetEventCallback(const EventCallbackFn &callback) override;

        void SetVSync(bool enable) override;

        [[nodiscard]] bool ShouldClose() const override;

        void Shutdown() override;

    private:
        void Init(const WindowProps &props);

        GLFWwindow *m_Handler;
        struct WindowData {
            std::string title;
            uint32_t width;
            uint32_t height;
            bool vsync;
            EventCallbackFn eventCallback;
        } m_WindowData;


    };
}
