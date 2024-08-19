#include "GraphicsContext.h"
#include "Avalanche/Core/Log.h"
#include "Platforms/API/OpenGL/OpenGLContext.h"
#include "Renderer.h"

struct GLFWwindow;

namespace AVL {

std::unique_ptr<GraphicsContext> GraphicsContext::Create(void* window) {
    switch (Renderer::GetAPI()) {
        case RendererAPI::API::None:
            AVL_CORE_FATAL("Please select a graphic API");
        case RendererAPI::API::OpenGL:
            return std::make_unique<OpenGLContext>(static_cast<GLFWwindow*>(window));
        default:
            break;
    }
    AVL_CORE_FATAL("Unknowm graphic API.");
}

}  // namespace AVL
