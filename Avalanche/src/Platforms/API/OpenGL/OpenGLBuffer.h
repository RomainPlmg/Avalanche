#pragma once

#include <glad/glad.h>
#include "Avalanche/Renderer/Buffer.h"

namespace AVL {

class OpenGLVertexBuffer : public VertexBuffer {
   public:
    OpenGLVertexBuffer(uint32_t size);
    OpenGLVertexBuffer(float* vertices, uint32_t size);
    ~OpenGLVertexBuffer();
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
    OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
    ~OpenGLIndexBuffer();

    virtual void Bind() override;
    virtual void Unbind() override;

    virtual uint32_t GetCount() const override { return m_Count; }

   private:
    uint32_t m_RendererID;
    uint32_t m_Count;
};

}  // namespace AVL