#pragma once

#include "Avalanche/Core/Window.h"
#include "Avalanche/Renderer/GraphicsContext.h"

#include <glad/glad.h>
// Include glad before glfw
#include <GLFW/glfw3.h>

namespace AVL {
class LinuxWindow : public Window {
   public:
    explicit LinuxWindow(const WindowProps& props);
    ~LinuxWindow() override = default;

    virtual void Update() override;
    virtual void Close() override;
    virtual bool ShouldClose() override;
    virtual void Shutdown() override;

    /* Getters */
    virtual inline uint32_t GetWidth() const override { return m_WindowData.width; }
    virtual inline uint32_t GetHeight() const override { return m_WindowData.height; }
    virtual inline bool IsVSync() const override { return m_WindowData.vsync; }
    virtual inline void* GetHandler() const override { return m_Handler; }

    /* Setters */
    virtual void SetVSync(bool enable) override;

   private:
    void Init(const WindowProps& props);
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);
    static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    static void window_pos_callback(GLFWwindow* window, int xpos, int ypos);

    GLFWwindow* m_Handler;
    std::unique_ptr<GraphicsContext> m_Context;

    struct WindowData {
        std::string title;
        uint32_t width;
        uint32_t height;
        bool vsync;
    } m_WindowData;
};
}  // namespace AVL
