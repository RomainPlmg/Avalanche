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
            return std::make_shared<OpenGLVertexBuffer>();
        default:
            break;
    }

    AVL_CORE_FATAL("Unknowm graphic API.");
}
std::shared_ptr<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size) {
    return std::shared_ptr<VertexBuffer>();
}

/* Index Buffer class */
std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* indices, uint32_t count) {
    return std::shared_ptr<IndexBuffer>();
}

}  // namespace AVL