#include "Renderer.h"

namespace AVL {

std::unique_ptr<RendererAPI> Renderer::m_RendererAPI = RendererAPI::Create();

}  // namespace AVL