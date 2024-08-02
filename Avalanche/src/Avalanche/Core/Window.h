#pragma once

#include "Core.h"
#include "Avalanche/Events/Event.h"

namespace AVL {
    struct WindowProps {
        std::string title;
        uint32_t width;
        uint32_t height;

        /* Default window props */
        explicit WindowProps(const std::string &title = "Avalanche Engine", uint32_t width = 1600,
                             uint32_t height = 900);
    };

    class AVL_API Window {
    public:
        using EventCallbackFn = std::function<void(const Event::Event &)>;

        virtual ~Window() = default;

        virtual void Update() = 0;


        /* Window attributes */
        [[nodiscard]] virtual uint32_t GetWidth() const = 0;

        [[nodiscard]] virtual uint32_t GetHeight() const = 0;

        [[nodiscard]] virtual bool IsVSync() const = 0;

        virtual void SetEventCallback(const EventCallbackFn &callback) = 0;

        virtual void SetVSync(bool enable) = 0;

        [[nodiscard]] virtual bool ShouldClose() const = 0;

        virtual void Shutdown() = 0;


        /* Return pointer on the specific platform window */
        static Window *Create(const WindowProps &props = WindowProps());
    };
}
