#include "OpenGLBuffer.h"

namespace AVL {

/* Vertex buffer */
OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size) {
    glCreateBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size) {
    glCreateBuffers(1, &m_RendererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer() {
    glDeleteBuffers(1, &m_RendererID);
}

void OpenGLVertexBuffer::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
}

void OpenGLVertexBuffer::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void OpenGLVertexBuffer::SetData(const void* data, uint32_t size) {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);

    // Avoid to completely recreating the data store with 'glBufferData'.
    // This avoids the cost of reallocating the data store.
    glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
}

/* Index buffer */
OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t count) : m_Count(count) {
    glCreateBuffers(1, &m_RendererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * count, indices, GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer() {
    glDeleteBuffers(1, &m_RendererID);
}

void OpenGLIndexBuffer::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
}

void OpenGLIndexBuffer::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

}  // namespace AVL