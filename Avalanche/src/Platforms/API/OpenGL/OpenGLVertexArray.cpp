#include "OpenGLVertexArray.h"
#include "OpenGLBuffer.h"

namespace AVL {

OpenGLVertexArray::OpenGLVertexArray() {
    glCreateVertexArrays(1, &m_RendererID);
}

OpenGLVertexArray::~OpenGLVertexArray() {
    glDeleteVertexArrays(1, &m_RendererID);
}

GLenum OpenGLVertexArray::GetOpenGLType(ShaderDataType type) {
    switch (type) {
        case ShaderDataType::None:
            return GL_NONE;
        case ShaderDataType::Float:
            return GL_FLOAT;
        case ShaderDataType::Float2:
            return GL_FLOAT;
        case ShaderDataType::Float3:
            return GL_FLOAT;
        case ShaderDataType::Float4:
            return GL_FLOAT;
        case ShaderDataType::Mat3:
            return GL_FLOAT;
        case ShaderDataType::Mat4:
            return GL_FLOAT;
        case ShaderDataType::Int:
            return GL_INT;
        case ShaderDataType::Int2:
            return GL_INT;
        case ShaderDataType::Int3:
            return GL_INT;
        case ShaderDataType::Int4:
            return GL_INT;
        case ShaderDataType::Bool:
            return GL_BOOL;
        default:
            break;
    }
    AVL_CORE_ERROR("Unkmown shader data type");
    return 0;
}

void OpenGLVertexArray::Bind() const {
    glBindVertexArray(m_RendererID);
}

void OpenGLVertexArray::Unbind() const {
    glBindVertexArray(0);
}

void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer) {
    glBindVertexArray(m_RendererID);
    buffer->Bind();

    const auto& layout = buffer->GetLayout();
    for (const auto& element : layout.GetElements()) {
        if (element.Type == ShaderDataType::Float || element.Type == ShaderDataType::Float2 ||
            element.Type == ShaderDataType::Float3 || element.Type == ShaderDataType::Float4) {
            glEnableVertexAttribArray(m_VertexBufferIndex);
            glVertexAttribPointer(m_VertexBufferIndex, element.GetComponentCount(), GetOpenGLType(element.Type),
                                  element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(),
                                  (const GLvoid*)static_cast<uintptr_t>(element.Offset));
        } else if (element.Type == ShaderDataType::Int || element.Type == ShaderDataType::Int2 ||
                   element.Type == ShaderDataType::Int3 || element.Type == ShaderDataType::Int4 ||
                   element.Type == ShaderDataType::Bool) {
            glEnableVertexAttribArray(m_VertexBufferIndex);
            glVertexAttribIPointer(m_VertexBufferIndex, element.GetComponentCount(), GetOpenGLType(element.Type),
                                   layout.GetStride(), (const GLvoid*)static_cast<uintptr_t>(element.Offset));
        } else if (element.Type == ShaderDataType::Mat3 || element.Type == ShaderDataType::Mat4) {
            // glEnableVertexAttribArray(m_VertexBufferIndex);
            AVL_CORE_WARN("Matrices in vertex arrays not yet supported");
        } else {
            AVL_CORE_FATAL("Unknowm ShaderDataType");
        }
        m_VertexBufferIndex++;
    }

    m_VertexBuffers.push_back(buffer);
}

void OpenGLVertexArray::UpdateIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) {
    glBindVertexArray(m_RendererID);
    buffer->Bind();

    m_IndexBuffer = buffer;
}

}  // namespace AVL
