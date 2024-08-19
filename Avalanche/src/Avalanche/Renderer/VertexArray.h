#pragma once

#include "Buffer.h"

namespace AVL {
class VertexArray {
   public:
    virtual ~VertexArray() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer) = 0;
    virtual void UpdateIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) = 0;

    static std::shared_ptr<VertexArray> Create();

   protected:
    uint32_t m_VertexBufferIndex = 0;
    std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
    std::shared_ptr<IndexBuffer> m_IndexBuffer;
};
}  // namespace AVL