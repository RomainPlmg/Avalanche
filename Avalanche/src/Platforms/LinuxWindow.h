#pragma once

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include "Avalanche/Core/Window.h"

namespace AVL {
class LinuxWindow : public Window {
   public:
    explicit LinuxWindow(const WindowProps& props);
    ~LinuxWindow() override = default;

    void Update() override;
    void Close() override;

    /* Window attributes */
    [[nodiscard]] uint32_t GetWidth() const override { return m_WindowData.width; }
    [[nodiscard]] uint32_t GetHeight() const override { return m_WindowData.height; }
    [[nodiscard]] bool IsVSync() const override { return m_WindowData.vsync; }
    [[nodiscard]] bool ShouldClose() const override;
    void SetVSync(bool enable) override;

    void Shutdown() override;

   private:
    void Init(const WindowProps& props);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

    GLFWwindow* m_Handler;
    struct WindowData {
        std::string title;
        uint32_t width;
        uint32_t height;
        bool vsync;
    } m_WindowData;
};
}  // namespace AVL
