#include "VertexArray.h"
#include "Platforms/API/OpenGL/OpenGLVertexArray.h"
#include "Renderer.h"

namespace AVL {
std::shared_ptr<VertexArray> VertexArray::Create() {
    switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            AVL_CORE_FATAL("Please select a graphic API");
        case RendererAPI::API::OpenGL:
            return std::make_shared<OpenGLVertexArray>();
        default:
            break;
    }
    AVL_CORE_FATAL("Unknowm graphic API.");
}
}  // namespace AVL
