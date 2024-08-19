#include "Renderer.h"

namespace AVL {

std::unique_ptr<RendererAPI> Renderer::m_RendererAPI;

void Renderer::Render(const Shader& shader, const VertexBuffer& buffer, const glm::mat4& transform) {
    shader.Bind();
    shader.SetUniformMat4("u_ModelMatrix", transform);
}

}  // namespace AVL