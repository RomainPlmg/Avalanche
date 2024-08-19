#pragma once

#include <glad/glad.h>
#include "Avalanche/Renderer/VertexArray.h"

namespace AVL {
class OpenGLVertexArray : public VertexArray {
   public:
    OpenGLVertexArray();
    ~OpenGLVertexArray();

    static GLenum GetOpenGLType(ShaderDataType type);

    virtual void Bind() const override;
    virtual void Unbind() const override;

    virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer) override;
    virtual void UpdateIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) override;

   private:
    uint32_t m_RendererID;
};
}  // namespace AVL
