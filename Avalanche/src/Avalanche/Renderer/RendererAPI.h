#pragma once

#include "Avalanche/Utils/Color.h"

namespace AVL {
class RendererAPI {
   public:
    enum class API { None = 0, OpenGL, Vulkan, DirectX, Metal };

    virtual ~RendererAPI() = default;

    virtual void Init() = 0;
    virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
    virtual void SetClearColor(const Color& color) = 0;
    virtual void Clear() = 0;

    static inline API GetAPI() { return m_API; }
    static std::unique_ptr<RendererAPI> Create();

   private:
    static API m_API;
};
}  // namespace AVL