#include "OpenGLShader.h"
#include "Avalanche/Core/Log.h"

#include <glm/gtc/type_ptr.hpp>

namespace AVL {

void OpenGLShader::SetUniformInt(const std::string& name, int value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        AVL_CORE_ERROR("Error: Unable to find the uniform \'{0}\'", name);
    }
    glUniform1i(uniformLoc, value);
}

void OpenGLShader::SetUniformIntArray(const std::string& name, int* values, uint32_t count) const {}

void OpenGLShader::SetUniformFloat(const std::string& name, float value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        AVL_CORE_ERROR("Error: Unable to find the uniform \'{0}\'", name);
    }
    glUniform1f(uniformLoc, value);
}

void OpenGLShader::SetUniformFloat2(const std::string& name, const glm::vec2& value) const {}

void OpenGLShader::SetUniformFloat3(const std::string& name, const glm::vec3& value) const {}

void OpenGLShader::SetUniformFloat4(const std::string& name, const glm::vec4& value) const {}

void OpenGLShader::SetUniformMat4(const std::string& name, const glm::mat4& value) const {
    GLint uniformLoc = glGetUniformLocation(m_RendererID, name.c_str());
    if (uniformLoc == -1) {
        AVL_CORE_ERROR("Error: Unable to find the uniform \'{0}\'", name);
    }
    glUniformMatrix4fv(uniformLoc, 1, GL_FALSE, glm::value_ptr(value));
}

}  // namespace AVL