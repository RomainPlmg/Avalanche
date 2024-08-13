#pragma once

#include "Avalanche/Renderer/Buffer.h"

namespace AVL {
class OpenGLVertexBuffer : public VertexBuffer {
   public:
    virtual void Bind() override;
    virtual void Unbind() override;
    virtual void SetData(const void* data, uint32_t size) override;

    virtual inline const BufferLayout& GetLayout() const override { return m_Layout; }
    virtual inline void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

   private:
    uint32_t m_RendererID;
    BufferLayout m_Layout;
};

class OpenGLIndexBuffer : public IndexBuffer {
   public:
    virtual void Bind() override;
    virtual void Unbind() override;

    virtual uint32_t GetCount() const override;

   private:
    uint32_t m_RendererID;
};

}  // namespace AVL