#include "RendererAPI.h"
#include "Avalanche/Core/Log.h"
#include "Platforms/API/OpenGL/OpenGLRendererAPI.h"

namespace AVL {

RendererAPI::API RendererAPI::m_API = RendererAPI::API::OpenGL;  // Default API

std::unique_ptr<RendererAPI> RendererAPI::Create() {
    switch (m_API) {
        case RendererAPI::API::None:
            AVL_CORE_FATAL("Please select a graphic API");
        case RendererAPI::API::OpenGL:
            return std::make_unique<OpenGLRendererAPI>();
        default:
            AVL_CORE_FATAL("Unknowm graphic API.");
    }
}

}  // namespace AVL
