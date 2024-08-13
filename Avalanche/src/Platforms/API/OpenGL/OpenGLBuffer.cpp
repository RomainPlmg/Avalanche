#include "OpenGLBuffer.h"
#include <glad/glad.h>

namespace AVL {

/* Vertex buffer */
void OpenGLVertexBuffer::Bind() {
    glBindBuffer(GL_VERTEX_ARRAY, m_RendererID);
}

void OpenGLVertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLVertexBuffer::SetData(const void* data, uint32_t size) {}

/* Index buffer */
void OpenGLIndexBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void OpenGLIndexBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

uint32_t OpenGLIndexBuffer::GetCount() const {
    return 0;
}

}  // namespace AVL