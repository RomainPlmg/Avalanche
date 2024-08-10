#pragma once

#include "Avalanche/Events/EventDispatcher.h"

namespace AVL {
struct WindowProps {
    std::string title;
    uint32_t width;
    uint32_t height;

    /* Default window props */
    explicit WindowProps(std::string title = "Avalanche Engine", uint32_t width = 1600, uint32_t height = 900);
};

class AVL_API Window {
   public:
    Window();
    virtual ~Window() = default;

    virtual void Update() = 0;
    virtual void Close() = 0;
    virtual void Shutdown() = 0;
    void OnEvent(const Event& event);

    /* Getters */
    virtual uint32_t GetWidth() const = 0;
    virtual uint32_t GetHeight() const = 0;
    virtual bool IsVSync() const = 0;
    virtual bool ShouldClose() const = 0;
    virtual void* GetHandler() const = 0;

    /* Setters */
    virtual void SetVSync(bool enable) = 0;

    /* Return pointer on the specific platform window */
    static Window* Create(const WindowProps& props = WindowProps());
};
}  // namespace AVL
