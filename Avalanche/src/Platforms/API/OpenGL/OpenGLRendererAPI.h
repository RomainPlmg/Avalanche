#pragma once

#include "Avalanche/Renderer/RendererAPI.h"

namespace AVL {
class OpenGLRendererAPI : public RendererAPI {
    virtual void Init() override;
    virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
    virtual void SetClearColor(const Color& color) override;
    virtual void Clear() override;
};
}  // namespace AVL