#pragma once

#include "Avalanche/Events/EventDispatcher.h"
#include "RendererAPI.h"

namespace AVL {

class Renderer {
   public:
    static inline void Init() { m_RendererAPI->Init(); }
    static inline void Shutdown() {}

    static inline void SetViewport(uint32_t width, uint32_t height) { m_RendererAPI->SetViewport(0, 0, width, height); }
    static inline void SetClearColor(const Color& color) { m_RendererAPI->SetClearColor(color); }
    static inline void Clear() { m_RendererAPI->Clear(); }

    static inline RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

   private:
    static std::unique_ptr<RendererAPI> m_RendererAPI;
};

}  // namespace AVL