#include "Buffer.h"
#include "Platforms/API/OpenGL/OpenGLBuffer.h"
#include "Renderer.h"

namespace AVL {

/* Vertex Buffer class */
std::shared_ptr<VertexBuffer> VertexBuffer::Create(uint32_t size) {
    switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            AVL_CORE_FATAL("Please select a graphic API");
            break;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLVertexBuffer>(size);
        default:
            break;
    }
    AVL_CORE_FATAL("Unknowm graphic API.");
}
std::shared_ptr<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size) {
    switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            AVL_CORE_FATAL("Please select a graphic API");
            break;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLVertexBuffer>(vertices, size);
        default:
            break;
    }
    AVL_CORE_FATAL("Unknowm graphic API.");
}

/* Index Buffer class */
std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count) {
    switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            AVL_CORE_FATAL("Please select a graphic API");
            break;
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLIndexBuffer>(indices, count);
        default:
            break;
    }
    AVL_CORE_FATAL("Unknowm graphic API.");
}

BufferLayout::BufferLayout(std::initializer_list<BufferElement> elements) : m_Elements(elements), m_Stride(0) {
    uint32_t offset = 0;
    for (auto& element : m_Elements) {
        element.Offset = offset;
        offset += element.Size;
        m_Stride += element.Size;
    }
}

}  // namespace AVL